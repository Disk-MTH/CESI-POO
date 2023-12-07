#include "CustomerForm.h"
#include "../../App.h"
#include "../forms/AddresseForm.h"

void CustomerForm::reloadAddressesGridView()
{
	if (this->customerId != "")
	{
		this->dataGridViewAddresses->Rows->Clear();

		DataSet^ addresses = App::app->db->query(
		"SELECT a.id_address, a.street, a.zip_code, a.city, at.id_address_type, at.type FROM address a INNER JOIN customerHasAddress cha ON a.id_address = cha.id_address INNER JOIN address_type at ON cha.id_address_type = at.id_address_type WHERE a.deleted = 0 AND cha.id_customer = " + customerId + ";");
		for (int i = 0; i < addresses->Tables[0]->Rows->Count; i++)
		{
			this->dataGridViewAddresses->Rows->Add(addresses->Tables[0]->Rows[i]->ItemArray);
		}
	}
}

int^ CustomerForm::createCustomer()
{
	lastName = this->textBoxLastName->Text;
	firstName = this->textBoxFirstName->Text;
	birthdate = this->textBoxBirthdate->Text;

	if (App::isEmpty("Nom", lastName) || App::isEmpty("Prenom", firstName) || App::isValidDate("Date de naissance", birthdate) == "")
	{
		return 0;
	}

	birthdate = App::isValidDate("Date de naissance", birthdate);
	
	try
	{
		if (customerId == "")
		{
			customerId = App::app->db->insert("INSERT INTO customer (last_name, first_name, birthdate) VALUES ('" + lastName + "', '" + firstName + "', '" + birthdate + "')");
		}
		else
		{
			App::app->db->execute("UPDATE customer SET last_name = '" + lastName + "', first_name = '" + firstName + "', birthdate = '" + birthdate + "' WHERE id_customer = " + customerId);
		}

		App::app->logger->log("Customer saved: \"" + lastName + "\", \"" + firstName + "\", \"" + birthdate + "\"");
		return 1;
	}
	catch (Exception^ exception)
	{
		App::app->logger->error("Error while editing customer: \"" + lastName + "\", \"" + firstName + "\", \"" + birthdate + "\"");
		App::app->logger->error(exception);
		App::app->toastMessage(this, "Erreur lors de la modifications du client", Color::Red, 3000);
	}
	return 0;
}

void CustomerForm::openAddressesForm(String^ addressId, String^ address, String^ zipCode, String^ city, String^ type)
{
	if (createCustomer()->Equals(1))
	{
		auto addAddressForm = gcnew AddresseForm(addressId, address, zipCode, city, type, this->customerId);
		if (addAddressForm->ShowDialog() == Windows::Forms::DialogResult::OK)
		{
			App::app->App::toastMessage(this, "Addresses enregistrees", Color::Green, 3000);
			reloadAddressesGridView();
		}
	}
}

void CustomerForm::boxDate_KeyPress(Object^ sender, KeyPressEventArgs^ e)
{
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08 && e->KeyChar != 0x2F)
	{
		e->Handled = true;
	}
}

void CustomerForm::buttonAdd_Click(Object^ sender, EventArgs^ e)
{
	openAddressesForm("", "", "", "", "");
}

void CustomerForm::buttonEdit_Click(Object^ sender, EventArgs^ e)
{
	if (this->dataGridViewAddresses->SelectedRows->Count == 0)
	{
		App::app->logger->warn("Can't edit: no address selected");
		App::app->toastMessage(this, "Veuillez selectionner une adresse", Color::Red, 2000);
		return;
	}
	
	openAddressesForm(
		this->dataGridViewAddresses->CurrentRow->Cells[0]->Value->ToString(),
		this->dataGridViewAddresses->CurrentRow->Cells[1]->Value->ToString(),
		this->dataGridViewAddresses->CurrentRow->Cells[2]->Value->ToString(),
		this->dataGridViewAddresses->CurrentRow->Cells[3]->Value->ToString(),
		this->dataGridViewAddresses->CurrentRow->Cells[4]->Value->ToString()
	);
}

void CustomerForm::buttonDelete_Click(Object^ sender, EventArgs^ e)
{
	if (this->dataGridViewAddresses->SelectedRows->Count == 0)
	{
		App::app->logger->warn("Can't delete: no address selected");
		App::app->toastMessage(this, "Veuillez selectionner une adresse", Color::Red, 2000);
		return;
	}
	
	try
	{
		App::app->db->execute("UPDATE address SET deleted = 1 WHERE id_address = " + this->dataGridViewAddresses->CurrentRow->Cells[0]->Value->ToString() + ";");
		App::app->logger->log("Address deleted: \"" + this->dataGridViewAddresses->CurrentRow->Cells[1]->Value->ToString() + "\", \"" + this->dataGridViewAddresses->CurrentRow->Cells[2]->Value->ToString() + "\", \"" + this->dataGridViewAddresses->CurrentRow->Cells[3]->Value->ToString() + "\", \"" + this->dataGridViewAddresses->CurrentRow->Cells[4]->Value->ToString() + "\"");
		App::app->toastMessage(this, "Adresse supprimee", Color::Green, 2000);
		reloadAddressesGridView();
	}
	catch (Exception^ exception)
	{
		App::app->logger->error("Error while deleting address: \"" + this->dataGridViewAddresses->CurrentRow->Cells[1]->Value->ToString() + "\", \"" + this->dataGridViewAddresses->CurrentRow->Cells[2]->Value->ToString() + "\", \"" + this->dataGridViewAddresses->CurrentRow->Cells[3]->Value->ToString() + "\", \"" + this->dataGridViewAddresses->CurrentRow->Cells[4]->Value->ToString() + "\"");
		App::app->logger->error(exception);
		App::app->toastMessage(this, "Erreur lors de la suppression de l'adresse", Color::Red, 3000);
	}
}

void CustomerForm::buttonCancel_Click(Object^ sender, EventArgs^ e)
{
	if (this->mode == "0" && customerId != "" && this->DialogResult != Windows::Forms::DialogResult::OK)
	{
		try
		{
			DataSet^ addresses = App::app->db->query("SELECT id_address FROM customerHasAddress WHERE id_customer = " + customerId + ";");
			App::app->db->execute("DELETE FROM customerHasAddress WHERE id_customer = " + customerId + ";");
			App::app->db->execute("DELETE FROM customer WHERE id_customer = " + customerId + ";");
			for (int i = 0; i < addresses->Tables[0]->Rows->Count; i++)
			{
				App::app->db->execute("DELETE FROM address WHERE id_address = " + addresses->Tables[0]->Rows[i]->ItemArray[0]->ToString() + ";");
			}
		}
		catch (Exception^ exception)
		{
			App::app->logger->error(exception);
		}
	}
	
	this->Close();
}

void CustomerForm::buttonValidate_Click(Object^ sender, EventArgs^ e)
{
	if (createCustomer()->Equals(1))
	{
		this->DialogResult = Windows::Forms::DialogResult::OK;
		this->Close();
	}
}
