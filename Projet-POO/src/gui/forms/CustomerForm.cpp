#include "CustomerForm.h"
#include "../../App.h"
#include "../forms/AddresseForm.h"

void CustomerForm::reloadAddressesGridView()
{
	if (this->customerId != "")
	{
		this->dataGridViewAddresses->Rows->Clear();

		DataSet^ addresses = App::app->db->query(
		"SELECT a.id_address,a.street_name,a.zip_code,cha.type,a.city FROM address a JOIN customerHasAddresses cha ON a.id_address = cha.id_address WHERE cha.id_customer = " + customerId + ";");

		for (int i = 0; i < addresses->Tables[0]->Rows->Count; i++)
		{
			this->dataGridViewAddresses->Rows->Add(addresses->Tables[0]->Rows[i]->ItemArray);
		}
	}
}

void CustomerForm::openAddressesForm(String^ addressId, String^ address, String^ zipCode, String^ city, String^ type)
{
	auto addAddressForm = gcnew AddresseForm(addressId, address, zipCode, city, type, customerId);
	if (addAddressForm->ShowDialog() == Windows::Forms::DialogResult::OK)
	{
		App::app->App::toastMessage(this, "Modifications enregistrees", Color::Green, 3000);
		reloadAddressesGridView();
	}
}


void CustomerForm::buttonAdd_Click(Object^ sender, EventArgs^ e)
{
	openAddressesForm("","","","","");
}

void CustomerForm::buttonEdit_Click(Object^ sender, EventArgs^ e)
{
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
	try
	{
		App::app->db->execute("UPDATE customerHasAddresses SET deleted = 1 WHERE id_customer = " + customerId + " AND id_address = " + this->dataGridViewAddresses->CurrentRow->Cells[0]->Value->ToString() + ";");
		App::app->logger->log("Address deleted: \"" + this->dataGridViewAddresses->CurrentRow->Cells[1]->Value->ToString() + "\", \"" + this->dataGridViewAddresses->CurrentRow->Cells[2]->Value->ToString() + "\", \"" + this->dataGridViewAddresses->CurrentRow->Cells[3]->Value->ToString() + "\", \"" + this->dataGridViewAddresses->CurrentRow->Cells[4]->Value->ToString() + "\"");
		App::app->toastMessage(this, "Adresse supprimee", Color::Green, 2000);
		reloadAddressesGridView();
	}
	catch (Exception^ exception)
	{
		App::app->logger->error("Error while deleting address: \"" + this->dataGridViewAddresses->CurrentRow->Cells[1]->Value->ToString() + "\", \"" + this->dataGridViewAddresses->CurrentRow->Cells[2]->Value->ToString() + "\", \"" + this->dataGridViewAddresses->CurrentRow->Cells[3]->Value->ToString() + "\", \"" + this->dataGridViewAddresses->CurrentRow->Cells[4]->Value->ToString() + "\"");
		App::app->logger->error(exception->Message);
		App::app->toastMessage(this, "Erreur lors de la suppression de l'adresse", Color::Red, 3000);
	}
}

void CustomerForm::buttonCancel_Click(Object^ sender, EventArgs^ e)
{
	this->Close();
}

void CustomerForm::buttonValidate_Click(Object^ sender, EventArgs^ e)
{
	firstName = this->textBoxFirstName->Text;
	lastName = this->textBoxLastName->Text;
	birthdate = App::isValidDate("Date de naissance", this->textBoxBirthdate->Text);

	if (App::isEmpty("Prenom", firstName) || App::isEmpty("Nom", lastName) || birthdate == "")
	{
		return;
	}
	
	try
	{
		if (customerId == "")
		{
			App::app->db->insert("INSERT INTO customer (first_name, last_name, birthdate) VALUES ('" + firstName + "', '" + lastName + "', '" + birthdate + "')");
		}
		else
		{
			App::app->db->execute("UPDATE customer SET first_name = '" + firstName + "', last_name = '" + lastName + "', birthdate = '" + birthdate + "' WHERE id_customer = " + customerId);
		}

		App::app->logger->log("Data edited: \"" + firstName + "\", \"" + lastName + "\", \"" + birthdate + "\"");
		this->DialogResult = Windows::Forms::DialogResult::OK;
		this->Close();
	}
	catch (Exception^ exception)
	{
		App::app->logger->error("Error while editing data: \"" + firstName + "\", \"" + lastName + "\", \"" + birthdate + "\"");
		App::app->logger->error(exception->Message);
		App::app->toastMessage(this, "Erreur lors de l'enregistrement des modifications", Color::Red, 3000);
	}
}
