#include "CustomerForm.h"
#include "../../App.h"

void CustomerForm::reloadAddressesGridView()
{

}

void CustomerForm::buttonAdd_Click(Object^ sender, EventArgs^ e)
{

}

void CustomerForm::buttonEdit_Click(Object^ sender, EventArgs^ e)
{

}

void CustomerForm::buttonDelete_Click(Object^ sender, EventArgs^ e)
{

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
