#include "OrderForm.h"
#include "../../App.h"

void OrderForm::reloadProductsGridView()
{
	if (this->orderId != "")
	{
		this->dataGridViewProducts->Rows->Clear();

		DataSet^ orders = App::app->db->query("SELECT p.id_product, p.type, p.name, p.colour, ohp.quantity, ohp.price FROM product p INNER JOIN dbo.orderHasProduct ohp on p.id_product = ohp.id_product WHERE id_order = " + orderId + ";");

		for (int i = 0; i < orders->Tables[0]->Rows->Count; i++)
		{
			this->dataGridViewProducts->Rows->Add(orders->Tables[0]->Rows[i]->ItemArray);
		}
	}
}

int^ OrderForm::createOrder()
{
	/*
	*        String^ orderId;
		String^ lastName;
		String^ firstName;
		String^ birthdate;
		String^ billingAddress;
		String^ deliveryAddress;
	 */

	lastName = this->comboBoxLastName->Text;
	firstName = this->comboBoxFirstName->Text;
	birthdate = this->comboBoxBirthDate->Text;
	billingAddress = this->comboBoxBillingAddress->Text;
	deliveryAddress = this->comboBoxDeliveryAddress->Text;

	if (App::isEmpty("Nom", lastName) || App::isEmpty("Prenom", firstName) || App::isValidDate("Date de naissance", birthdate) == "" || App::isEmpty("Adresse de facturation", billingAddress) || App::isEmpty("Adresse de livraison", deliveryAddress))
	{
		return 0;
	}

	birthdate = App::isValidDate("Date de naissance", birthdate);

	//get customer Id from name, lastname and birthdate
	String^ customerId = "";
	
	try
	{
		DataSet^ customer = App::app->db->query("SELECT id_customer FROM customer WHERE last_name = '" + lastName + "' AND first_name = '" + firstName + "' AND birthdate = '" + birthdate + "' LIMIT 1;");
		customerId = customer->Tables[0]->Rows[0]->ItemArray[0]->ToString();
	}
	catch (Exception ^ exception)
	{
		App::app->logger->error("Error retrieving customer id: \"" + lastName + "\", \"" + firstName + "\", \"" + birthdate + "\"");
		App::app->logger->error(exception->Message);
		App::app->toastMessage(this, "Le client n'existe pas", Color::Red, 3000);
		return 0;
	}

	//check 
}

void OrderForm::buttonValidate_Click(Object^ sender, EventArgs^ e)
{
	if (createOrder()->Equals(1))
	{
		this->DialogResult = Windows::Forms::DialogResult::OK;
		this->Close();
	}
}
