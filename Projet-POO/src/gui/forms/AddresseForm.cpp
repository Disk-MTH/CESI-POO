#include "AddresseForm.h"

#include "../../App.h"

void AddresseForm::textBoxZipCode_KeyPress(Object^ sender, KeyPressEventArgs^ e)
{
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08)
	{
		e->Handled = true;
	}
}

void AddresseForm::buttonCancel_Click(Object^ sender, EventArgs^ e)
{
	this->Close();
}

void AddresseForm::buttonValidate_Click(Object^ sender, EventArgs^ e)
{
	street = this->textBoxStreet->Text;
	zipCode = this->textBoxZipCode->Text;
	city = this->comboBoxCity->Text;
	String^ addressTypeId = this->checkBoxDelivery->Checked && this->checkBoxDelivery->Checked ? "3" : this->checkBoxDelivery->Checked ? "2" : this->checkBoxBilling->Checked ? "1" : "";

	if (App::isEmpty ("Adresse", street) || App::isEmpty ("Code postal", zipCode) || App::isEmpty ("Ville", city) || App::isEmpty ("Type", addressTypeId))
	{
		return;
	}

	try
	{
		if (addressId != "")
		{
			App::app->db->execute("UPDATE address SET deleted = 1 WHERE id_address = " + addressId + ";");
		}

		auto addressId = App::app->db->insert("INSERT INTO address (street, zip_code, city) VALUES ('" + street + "', '" + zipCode + "', '" + city + "');");
		App::app->db->insert("INSERT INTO customerHasAddresses (id_customer, id_address, id_address_type) VALUES ('" + this->customerId + "', '" + addressId + "', '" + addressTypeId + "');");

		App::app->logger->log("Address saved: \"" + street + "\", \"" + zipCode + "\", \"" + city + "\", \"" + addressTypeId + "\"");
		this->DialogResult = Windows::Forms::DialogResult::OK;
		this->Close();
	}
	catch (Exception^ exception)
	{
		App::app->logger->error("Error while saving address: \"" + street + "\", \"" + zipCode + "\", \"" + city + "\", \"" + addressTypeId + "\"");
		App::app->logger->error(exception);
		App::app->toastMessage(this, "Erreur lors de l'enregistrement de l'adresse", Color::Red, 3000);
	}
}

