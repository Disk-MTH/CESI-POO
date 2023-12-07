#include "OrderForm.h"
#include "../../App.h"

void OrderForm::reloadProductsGridView()
{
	if (this->orderId != "")
	{
		this->dataGridViewProducts->Rows->Clear();

		DataSet^ orders = App::app->db->query("SELECT p.id_product, p.type, p.name, p.colour, ohp.quantity, ohp.price, ohp.id_orderHasProduct FROM product p INNER JOIN dbo.orderHasProduct ohp on p.id_product = ohp.id_product WHERE id_order = " + orderId + ";");

		for (int i = 0; i < orders->Tables[0]->Rows->Count; i++)
		{
			this->dataGridViewProducts->Rows->Add(orders->Tables[0]->Rows[i]->ItemArray);
		}
	}
}

int^ OrderForm::createOrder()
{
	lastName = this->comboBoxLastName->Text;
	firstName = this->comboBoxFirstName->Text;
	birthdate = this->comboBoxBirthdate->Text;
	billingAddress = this->comboBoxBillingAddress->Text;
	deliveryAddress = this->comboBoxDeliveryAddress->Text;
	deliveryDate = this->textBoxDeliveryDate->Text;
	
	if (App::isEmpty("Nom", lastName) || App::isEmpty("Prenom", firstName) || App::isValidDate("Date de naissance", birthdate) == "" || App::isEmpty("Adresse de facturation", billingAddress) || App::isEmpty("Adresse de livraison", deliveryAddress) || App::isValidDate("Date de livraison", deliveryDate) == "")
	{
		return 0;
	}

	birthdate = App::isValidDate("Date de naissance", birthdate);
	deliveryDate = App::isValidDate("Date de livraison", deliveryDate);
	String^ reference = (firstName->Substring(0, 2) + lastName->Substring(0, 2) + DateTime::Now.ToString("yy") + deliveryAddress->Split(',')[2]->Substring(1, 3) + orderId)->ToLower();
	String^ issueDate = DateTime::Now.ToString("dd/MM/yyyy");
	
	String^ customerId;
	try
	{
		DataSet^ customer = App::app->db->query("SELECT id_customer FROM customer WHERE last_name = '" + lastName + "' AND first_name = '" + firstName + "' AND birthdate = '" + birthdate + "';");
		customerId = customer->Tables[0]->Rows[0]->ItemArray[0]->ToString();
	}
	catch (Exception^ exception)
	{
		App::app->logger->error("Error retrieving customer id: \"" + lastName + "\", \"" + firstName + "\", \"" + birthdate + "\"");
		App::app->logger->error(exception);
		App::app->toastMessage(this, "Le client n'existe pas", Color::Red, 3000);
		return 0;
	}

	String^ billingAddressId;
	try
	{
		DataSet^ address = App::app->db->query("SELECT id_address FROM address WHERE CONCAT(street, ', ', zip_code, ', ', city) = '" + billingAddress + "';");
		billingAddressId = address->Tables[0]->Rows[0]->ItemArray[0]->ToString();
	}
	catch (Exception^ exception)
	{
		App::app->logger->error("Error retrieving billing address id: \"" + billingAddress + "\"");
		App::app->logger->error(exception);
		App::app->toastMessage(this, "L'adresse de facturation n'existe pas", Color::Red, 3000);
		return 0;
	}

	String^ deliveryAddressId;
	try
	{
		DataSet^ address = App::app->db->query("SELECT id_address FROM address WHERE CONCAT(street, ', ', zip_code, ', ', city) = '" + deliveryAddress + "';");
		deliveryAddressId = address->Tables[0]->Rows[0]->ItemArray[0]->ToString();
	}
	catch (Exception^ exception)
	{
		App::app->logger->error("Error retrieving delivery address id: \"" + deliveryAddress + "\"");
		App::app->logger->error(exception);
		App::app->toastMessage(this, "L'adresse de livraison n'existe pas", Color::Red, 3000);
		return 0;
	}

	try
	{
		if (orderId == "")
		{
			orderId = App::app->db->insert("INSERT INTO [order] (reference, issue_date, expected_delivery_date, id_customer, id_billing_address, id_delivery_address) VALUES ('" + reference + "', '" + issueDate + "', '" + deliveryDate + "', '" + customerId + "', '" + billingAddressId + "', '" + deliveryAddressId + "');");
			reference = reference + orderId;
			App::app->db->execute("UPDATE [order] SET reference = '" + reference + "' WHERE id_order = " + orderId + ";");
		}
		else
		{
			App::app->db->execute("UPDATE [order] SET reference = '" + reference + "', issue_date = '" + issueDate + "', expected_delivery_date = '" + deliveryDate + "', id_customer = '" + customerId + "', id_billing_address = '" + billingAddressId + "', id_delivery_address = '" + deliveryAddressId + "' WHERE id_order = " + orderId + ";");
		}

		App::app->logger->log("Order saved: \"" + reference + "\", \"" + issueDate + "\", \"" + deliveryDate + "\", \"" + customerId + "\", \"" + billingAddressId + "\", \"" + deliveryAddressId + "\"");
		reloadProductsGridView();
		return 1;
	}
	catch (Exception^ exception)
	{
		App::app->logger->error("Error while creating order: \"" + reference + "\", \"" + issueDate + "\", \"" + deliveryDate + "\", \"" + customerId + "\", \"" + billingAddressId + "\", \"" + deliveryAddressId + "\"");
		App::app->logger->error(exception);
		App::app->toastMessage(this, "Erreur lors de la creation de la commande", Color::Red, 3000);
	}
	return 0;
}

void OrderForm::retrieveSuggestion(ComboBox^ comboBox, String^ query)
{
	DataSet^ lastNames = App::app->db->query(query->Replace("{data}", comboBox->Text));
	comboBox->Items->Clear();
	for (int i = 0; i < lastNames->Tables[0]->Rows->Count; i++)
	{
		comboBox->Items->Add(lastNames->Tables[0]->Rows[i]->ItemArray[0]->ToString());
	}
	comboBox->SelectionStart = comboBox->Text->Length;
}

void OrderForm::orderForm_Load(Object^ sender, EventArgs^ e)
{
	this->Location = Point(this->Location.X, this->Location.Y - 15);
}

void OrderForm::comboBoxUser_keyPress(Object^ sender, KeyPressEventArgs^ e)
{
	retrieveSuggestion(this->comboBoxFirstName, "SELECT first_name FROM customer WHERE first_name LIKE '{data}%' AND last_name LIKE '" + this->comboBoxLastName->Text + "%' AND deleted = 0;");
	retrieveSuggestion(this->comboBoxLastName, "SELECT last_name FROM customer WHERE last_name LIKE '{data}%' AND first_name LIKE '" + this->comboBoxFirstName->Text + "%' AND deleted = 0;");
	retrieveSuggestion(this->comboBoxBirthdate, "SELECT CONVERT(VARCHAR(10), birthdate, 103) AS birthdate FROM customer WHERE CONVERT(VARCHAR(10), birthdate, 103) LIKE '{data}%' AND last_name = '" + this->comboBoxLastName->Text + "' AND first_name = '" + this->comboBoxFirstName->Text + "' AND deleted = 0;");
	retrieveSuggestion(this->comboBoxBillingAddress, "SELECT CONCAT(street, ', ', zip_code, ', ', city) AS billing_address FROM address WHERE CONCAT(street, ', ', zip_code, ', ', city) LIKE '{data}%' AND id_address IN (SELECT id_address FROM customerHasAddress WHERE id_customer = (SELECT id_customer FROM customer WHERE last_name = '" + this->comboBoxLastName->Text + "' AND first_name = '" + this->comboBoxFirstName->Text + "') AND id_address_type = 1 OR id_address_type = 3) AND deleted = 0;");
	retrieveSuggestion(this->comboBoxDeliveryAddress, "SELECT CONCAT(street, ', ', zip_code, ', ', city) AS delivery_address FROM address WHERE CONCAT(street, ', ', zip_code, ', ', city) LIKE '{data}%' AND id_address IN (SELECT id_address FROM customerHasAddress WHERE id_customer = (SELECT id_customer FROM customer WHERE last_name = '" + this->comboBoxLastName->Text + "' AND first_name = '" + this->comboBoxFirstName->Text + "') AND id_address_type = 2 OR id_address_type = 3) AND deleted = 0;");
}

void OrderForm::comboBoxProduct_keyPress(Object^ sender, KeyPressEventArgs^ e)
{
	retrieveSuggestion(this->comboBoxType, "SELECT DISTINCT type FROM product WHERE type LIKE '{data}%' AND name LIKE '" + this->comboBoxProductName->Text + "%' AND colour LIKE '" + this->comboBoxColour->Text + "%';");
	retrieveSuggestion(this->comboBoxProductName, "SELECT DISTINCT name FROM product WHERE name LIKE '{data}%' AND type LIKE '" + this->comboBoxType->Text + "%' AND colour LIKE '" + this->comboBoxColour->Text + "%';");
	retrieveSuggestion(this->comboBoxColour, "SELECT DISTINCT colour FROM product WHERE colour LIKE '{data}%' AND name LIKE '" + this->comboBoxProductName->Text + "%' AND type LIKE '" + this->comboBoxType->Text + "%';");
}

void OrderForm::boxInt_KeyPress(Object^ sender, KeyPressEventArgs^ e)
{
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08)
	{
		e->Handled = true;
	}
}

void OrderForm::boxDate_KeyPress(Object^ sender, KeyPressEventArgs^ e)
{
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08 && e->KeyChar != 0x2F)
	{
		e->Handled = true;
	}
}

void OrderForm::buttonAdd_Click(Object^ sender, EventArgs^ e)
{
	if (createOrder()->Equals(1))
	{
		String^ name = this->comboBoxProductName->Text;
		String^ type = this->comboBoxType->Text;
		String^ colour = this->comboBoxColour->Text;
		String^ quantity = this->textBoxQuantity->Text;

		String^ productId;
		try
		{
			DataSet^ product = App::app->db->query("SELECT id_product FROM product WHERE name = '" + name + "' AND type = '" + type + "' AND colour = '" + colour + "';");
			productId = product->Tables[0]->Rows[0]->ItemArray[0]->ToString();
		}
		catch (Exception^ exception)
		{
			App::app->logger->error("Error retrieving product id: \"" + name + "\", \"" + type + "\", \"" + colour + "\"");
			App::app->logger->error(exception);
			App::app->toastMessage(this, "Le produit n'existe pas", Color::Red, 3000);
			return;
		}

		String^ orderHasProductId = "";
		try
		{
			DataSet^ oldOrderHasProduct = App::app->db->query("SELECT id_orderHasProduct, quantity FROM orderHasProduct WHERE id_order = " + orderId + " AND id_product = " + productId + ";");

			if (oldOrderHasProduct->Tables[0]->Rows->Count > 0)
			{
				orderHasProductId = oldOrderHasProduct->Tables[0]->Rows[0]->ItemArray[0]->ToString();
				quantity = (Convert::ToDouble(quantity) + Convert::ToDouble(oldOrderHasProduct->Tables[0]->Rows[0]->ItemArray[1]->ToString())).ToString();
			}
		}
		catch (Exception^ exception)
		{
		}

		String^ tfPriceUnit;
		String^ vatPriceUnit;
		String^ priceUnit;

		try
		{
			DataSet^ product = App::app->db->query("SELECT TOP 1 tp.tf_price, ROUND(p.vat_rate / 100 * tp.tf_price, 3) AS vat_price, ROUND(tp.tf_price * (1 + p.vat_rate / 100), 3) AS price FROM product p INNER JOIN tiered_price tp ON p.id_product = tp.id_product WHERE tp.deleted = 0 AND tp.minimal_quantity <= " + quantity + " AND p.id_product = " + productId + " ORDER BY tp.minimal_quantity DESC;");
			tfPriceUnit = product->Tables[0]->Rows[0]->ItemArray[0]->ToString();
			vatPriceUnit = product->Tables[0]->Rows[0]->ItemArray[1]->ToString();
			priceUnit = product->Tables[0]->Rows[0]->ItemArray[2]->ToString();
		}
		catch (Exception^ exception)
		{
			App::app->logger->error("Error retrieving product price: \"" + productId + "\", \"" + quantity + "\"");
			App::app->logger->error(exception);
			App::app->toastMessage(this, "Le prix du produit n'existe pas", Color::Red, 3000);
			return;
		}

		String^ tfPrice = (Convert::ToDouble(tfPriceUnit) * Convert::ToDouble(quantity)).ToString()->Replace(",", ".");
		String^ vatPrice = (Convert::ToDouble(vatPriceUnit) * Convert::ToDouble(quantity)).ToString()->Replace(",", ".");
		String^ price = (Convert::ToDouble(priceUnit) * Convert::ToDouble(quantity)).ToString()->Replace(",", ".");
		
		if (orderHasProductId == "")
		{
			try
			{
				App::app->db->execute("INSERT INTO orderHasProduct (id_order, id_product, quantity, price, tf_price, vat_price) VALUES (" + orderId + ", " + productId + ", " + quantity + ", " + price + ", " + tfPrice + ", " + vatPrice + ");");
				App::app->logger->log("Product added: \"" + productId + "\", \"" + name + "\", \"" + type + "\", \"" + colour + "\", \"" + quantity + "\", \"" + tfPrice + "\", \"" + vatPrice + "\", \"" + price + "\"");
				App::app->toastMessage(this, "Produit ajoute", Color::Green, 2000);
				reloadProductsGridView();
			}
			catch (Exception^ exception)
			{
				App::app->logger->error("Error while adding product: \"" + productId + "\", \"" + name + "\", \"" + type + "\", \"" + colour + "\", \"" + quantity + "\", \"" + tfPrice + "\", \"" + vatPrice + "\", \"" + price + "\"");
				App::app->logger->error(exception);
				App::app->toastMessage(this, "Erreur lors de l'ajout du produit", Color::Red, 3000);
			}
		}
		else
		{
			try
			{
				App::app->db->execute("UPDATE orderHasProduct SET quantity = " + quantity + ", price = " + price + ", tf_price = " + tfPrice + ", vat_price = " + vatPrice + " WHERE id_orderHasProduct = " + orderHasProductId + ";");
				App::app->logger->log("Product updated: \"" + productId + "\", \"" + name + "\", \"" + type + "\", \"" + colour + "\", \"" + quantity + "\", \"" + tfPrice + "\", \"" + vatPrice + "\", \"" + price + "\"");
				App::app->toastMessage(this, "Produit mis a jour", Color::Green, 2000);
				reloadProductsGridView();
			}
			catch (Exception^ exception)
			{
				App::app->logger->error("Error while updating product: \"" + productId + "\", \"" + name + "\", \"" + type + "\", \"" + colour + "\", \"" + quantity + "\", \"" + tfPrice + "\", \"" + vatPrice + "\", \"" + price + "\"");
				App::app->logger->error(exception);
				App::app->toastMessage(this, "Erreur lors de la mise a jour du produit", Color::Red, 3000);
			}
		}
	}
}

void OrderForm::buttonDelete_Click(Object^ sender, EventArgs^ e)
{
	if (this->dataGridViewProducts->SelectedRows->Count == 0)
	{
		App::app->logger->warn("Can't delete: no product selected");
		App::app->toastMessage(this, "Veuillez selectionner un produit", Color::Red, 2000);
		return;
	}

	try
	{
		App::app->db->execute("DELETE FROM orderHasProduct WHERE id_order = " + orderId + " AND id_product = " + this->dataGridViewProducts->CurrentRow->Cells[0]->Value->ToString() + "AND id_orderHasProduct = " + this->dataGridViewProducts->CurrentRow->Cells[6]->Value->ToString() + ";");
		App::app->logger->log("Product deleted: \"" + this->dataGridViewProducts->CurrentRow->Cells[0]->Value->ToString() + "\", \"" + this->dataGridViewProducts->CurrentRow->Cells[1]->Value->ToString() + "\", \"" + this->dataGridViewProducts->CurrentRow->Cells[2]->Value->ToString() + "\", \"" + this->dataGridViewProducts->CurrentRow->Cells[3]->Value->ToString() + "\", \"" + this->dataGridViewProducts->CurrentRow->Cells[4]->Value->ToString() + "\", \"" + this->dataGridViewProducts->CurrentRow->Cells[5]->Value->ToString() + "\"");
		App::app->toastMessage(this, "Produit supprime", Color::Green, 2000);
		reloadProductsGridView();
	}
	catch (Exception^ exception)
	{
		App::app->logger->error("Error while deleting product: \"" + this->dataGridViewProducts->CurrentRow->Cells[0]->Value->ToString() + "\", \"" + this->dataGridViewProducts->CurrentRow->Cells[1]->Value->ToString() + "\", \"" + this->dataGridViewProducts->CurrentRow->Cells[2]->Value->ToString() + "\", \"" + this->dataGridViewProducts->CurrentRow->Cells[3]->Value->ToString() + "\", \"" + this->dataGridViewProducts->CurrentRow->Cells[4]->Value->ToString() + "\", \"" + this->dataGridViewProducts->CurrentRow->Cells[5]->Value->ToString() + "\"");
		App::app->logger->error(exception);
		App::app->toastMessage(this, "Erreur lors de la suppression du produit", Color::Red, 3000);
	}
}

void OrderForm::buttonCancel_Click(Object^ sender, EventArgs^ e)
{
	if (this->mode == "0" && orderId != "")
	{
		try
		{
			App::app->db->execute("DELETE FROM orderHasProduct WHERE id_order = " + orderId + ";");
			App::app->db->execute("DELETE FROM [order] WHERE id_order = " + orderId + ";");
			App::app->logger->log("Order deleted: \"" + orderId + "\"");
			App::app->toastMessage(this, "Commande supprimee", Color::Green, 2000);
		}
		catch (Exception^ exception)
		{
			App::app->logger->error("Error while deleting order: \"" + orderId + "\"");
			App::app->logger->error(exception);
			App::app->toastMessage(this, "Erreur lors de la suppression de la commande", Color::Red, 3000);
		}
	}

	this->Close();
}

void OrderForm::buttonValidate_Click(Object^ sender, EventArgs^ e)
{
	if (createOrder()->Equals(1))
	{
		this->DialogResult = Windows::Forms::DialogResult::OK;
		this->Close();
	}
}
