#include "AddresseForm.h"

#include <type_traits>

#include "../../App.h"

void AddresseForm::buttonCancel_Click(Object^ sender, EventArgs^ e)
{
	this->Close();
}

void AddresseForm::buttonValidate_Click(Object^ sender, EventArgs^ e)
{
	address = this->textBoxStreetName->Text;
	zipCode = this->textBoxZipCode->Text;
	city = this->comboBoxCity->Text;
	type = "1";
	customerId = this->customerId;

	if (App::isEmpty ("Adresse", address) || App::isEmpty ("Code postal", zipCode) || App::isEmpty ("Ville", city))
	{
		return;
	}

	try
	{
		if (addressId =="")
		{
			App::app->logger->log("111111111111");
			int InsertedAddressID = App::app->db->insert("INSERT INTO address (street_name, zip_code, city) VALUES ('" + address + "', '" + zipCode + "', '" + city + "');");
			App::app->logger->log("2222222222");
			App::app->db->insert("INSERT INTO customerHasAddresses (id_customer, id_address, type) VALUES ('" + customerId + "', '" + InsertedAddressID + "', '" + type + "');");
			App::app->logger->log("3333333333");
		}
		else
		{
			App::app->db->execute("UPDATE address SET street_name = '" + address + "', zip_code = '" + zipCode + "', city = '" + city + "' WHERE id_address = " + addressId + ";");
		}

		App::app->logger->log("Address saved: \"" + address + "\", \"" + zipCode + "\", \"" + city + "\", \"" + type + "\"");
		this->DialogResult = Windows::Forms::DialogResult::OK;
		this->Close();
	}
	catch (Exception^ exception)
	{
		App::app->logger->error("Error while saving address: \"" + address + "\", \"" + zipCode + "\", \"" + city + "\", \"" + type + "\"");
		App::app->logger->error(exception->Message);
		App::app->toastMessage(this, "Erreur lors de l'enregistrement de l'adresse", Color::Red, 3000);
	}
}

