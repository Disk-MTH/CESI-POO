#include "CustomersPage.h"
#include "../forms/CustomerForm.h"
#include "../../App.h"

void CustomersPage::reloadCustomersGridView()
{
	this->dataGridViewCustomers->Rows->Clear();
	
	DataSet^ customers = App::app->db->query("SELECT c.id_customer, c.first_name, c.last_name, CONVERT(VARCHAR, c.birthdate, 103) AS birthdate, ISNULL(b.billingAddressesCount, 0) + ISNULL(d.deliveryAddressesCount, 0) AS addressesCount FROM customer c LEFT JOIN (SELECT id_customer, COUNT(*) AS billingAddressesCount FROM customerHasAddresses cha WHERE cha.type = 0 GROUP BY id_customer) b ON c.id_customer = b.id_customer LEFT JOIN (SELECT id_customer, COUNT(*) AS deliveryAddressesCount FROM customerHasAddresses cha WHERE cha.type = 1 GROUP BY id_customer) d ON c.id_customer = d.id_customer;");
	
	for (int i = 0; i < customers->Tables[0]->Rows->Count; i++)
	{
		this->dataGridViewCustomers->Rows->Add(customers->Tables[0]->Rows[i]->ItemArray);
	}
}

Void CustomersPage::buttonCreateOrder_Click(Object^ sender, EventArgs^ e)
{
	App::app->toastMessage(this, "Fonctionnalite non implementee: Creer une commande", Color::Red, 2000);
}

Void CustomersPage::buttonAdd_Click(Object^ sender, EventArgs^ e)
{
	String^ firstName = "";
	String^ lastName = "";
	String^ birthdate = "";
	auto addCustomerForm = gcnew CustomerForm(&firstName, &lastName, &birthdate);

	if (addCustomerForm->ShowDialog() == Windows::Forms::DialogResult::OK)
	{
		try
		{
			App::app->db->insert("INSERT INTO customer (first_name, last_name, birthdate) VALUES ('" + firstName + "', '" + lastName + "', '" + birthdate + "')");
			App::app->App::toastMessage(this, "Donnees ajoutees", Color::Green, 3000);
			App::app->logger->log("Data inserted: \"" + firstName + "\", \"" + lastName + "\", \"" + birthdate + "\"");
		}
		catch (Exception^ exception)
		{
			App::app->toastMessage(this, "Erreur lors de l'ajout des donnees", Color::Red, 3000);
			App::app->logger->error("Error while inserting data: \"" + firstName + "\", \"" + lastName + "\", \"" + birthdate + "\"");
			App::app->logger->error(exception->Message);
			return;
		}

		//fillCustomersGridView();
	}
}

Void CustomersPage::buttonEdit_Click(Object^ sender, EventArgs^ e)
{
	String^ firstName = this->dataGridViewCustomers->CurrentRow->Cells[1]->Value->ToString();
	String^ lastName = this->dataGridViewCustomers->CurrentRow->Cells[2]->Value->ToString();
	String^ birthdate = this->dataGridViewCustomers->CurrentRow->Cells[3]->Value->ToString();
	auto addCustomerForm = gcnew CustomerForm(&firstName, &lastName, &birthdate);

	if (addCustomerForm->ShowDialog() == Windows::Forms::DialogResult::OK)
	{
		try
		{
			App::app->db->insert("INSERT INTO customer (first_name, last_name, birthdate) VALUES ('" + firstName + "', '" + lastName + "', '" + birthdate + "')");
			App::app->App::toastMessage(this, "Donnees ajoutees", Color::Green, 3000);
			App::app->logger->log("Data inserted: \"" + firstName + "\", \"" + lastName + "\", \"" + birthdate + "\"");
		}
		catch (Exception^ exception)
		{
			App::app->toastMessage(this, "Erreur lors de l'ajout des donnees", Color::Red, 3000);
			App::app->logger->error("Error while inserting data: \"" + firstName + "\", \"" + lastName + "\", \"" + birthdate + "\"");
			App::app->logger->error(exception->Message);
			return;
		}

		//fillCustomersGridView();
	}
}

Void CustomersPage::buttonDelete_Click(Object^ sender, EventArgs^ e)
{
	App::app->toastMessage(this, "Fonctionnalite non implementee: Modifier un client", Color::Red, 2000);
}
