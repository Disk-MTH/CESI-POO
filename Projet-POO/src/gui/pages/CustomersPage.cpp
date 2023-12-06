#include "CustomersPage.h"
#include "../../App.h"
#include "../forms/CustomerForm.h"
#include "../forms/OrderForm.h"

void CustomersPage::reloadCustomersGridView()
{
	this->dataGridViewCustomers->Rows->Clear();

	DataSet^ customers = App::app->db->query(
		"SELECT id_customer, last_name, first_name, CONVERT(VARCHAR, birthdate, 103) AS birthdate FROM customer" + (this->checkBoxDeleted->Checked ? ";" : " WHERE deleted = 0;"));

	for (int i = 0; i < customers->Tables[0]->Rows->Count; i++)
	{
		this->dataGridViewCustomers->Rows->Add(customers->Tables[0]->Rows[i]->ItemArray);
	}
}

void CustomersPage::openCustomerForm(String^ customerId, String^ lastName, String^ firstName, String^ birthdate)
{
	auto addCustomerForm = gcnew CustomerForm(customerId, lastName, firstName, birthdate);
	if (addCustomerForm->ShowDialog() == Windows::Forms::DialogResult::OK)
	{
		App::app->App::toastMessage(this, "Modifications enregistrees", Color::Green, 3000);
		reloadCustomersGridView();
	}
}

void CustomersPage::checkBoxDeleted_Click(Object^ sender, EventArgs^ e)
{
	reloadCustomersGridView();	
}

void CustomersPage::buttonCreateOrder_Click(Object^ sender, EventArgs^ e)
{
	if (this->dataGridViewCustomers->SelectedRows->Count == 0)
	{
		App::app->logger->warn("Can't create order: no customer selected");
		App::app->toastMessage(this, "Veuillez selectionner un client", Color::Red, 2000);
		return;
	}
	
	auto orderForm = gcnew OrderForm(
		"",
		this->dataGridViewCustomers->CurrentRow->Cells[1]->Value->ToString(),
		this->dataGridViewCustomers->CurrentRow->Cells[2]->Value->ToString(),
		this->dataGridViewCustomers->CurrentRow->Cells[3]->Value->ToString(),
		"",
		"",
		""
	);
	if (orderForm->ShowDialog() == Windows::Forms::DialogResult::OK)
	{
		App::app->App::toastMessage(this, "Commande enregistree", Color::Green, 3000);
	}
}

void CustomersPage::buttonAdd_Click(Object^ sender, EventArgs^ e)
{
	openCustomerForm("", "", "", "");
}

void CustomersPage::buttonEdit_Click(Object^ sender, EventArgs^ e)
{
	if (this->dataGridViewCustomers->SelectedRows->Count == 0)
	{
		App::app->logger->warn("Can't edit: no customer selected");
		App::app->toastMessage(this, "Veuillez selectionner un client", Color::Red, 2000);
		return;
	}
	
	openCustomerForm(
		this->dataGridViewCustomers->CurrentRow->Cells[0]->Value->ToString(),
		this->dataGridViewCustomers->CurrentRow->Cells[1]->Value->ToString(),
		this->dataGridViewCustomers->CurrentRow->Cells[2]->Value->ToString(),
		this->dataGridViewCustomers->CurrentRow->Cells[3]->Value->ToString()
	);
}

void CustomersPage::buttonDelete_Click(Object^ sender, EventArgs^ e)
{
	if (this->dataGridViewCustomers->SelectedRows->Count == 0)
	{
		App::app->logger->warn("Can't delete: no customer selected");
		App::app->toastMessage(this, "Veuillez selectionner un client", Color::Red, 2000);
		return;
	}
	
	try
	{
		App::app->db->execute("UPDATE customer SET deleted = 1 WHERE id_customer = " + this->dataGridViewCustomers->CurrentRow->Cells[0]->Value->ToString() + ";");
		App::app->logger->log("Customer deleted: \"" + this->dataGridViewCustomers->CurrentRow->Cells[1]->Value->ToString() + "\", \"" + this->dataGridViewCustomers->CurrentRow->Cells[2]->Value->ToString() + "\", \"" + this->dataGridViewCustomers->CurrentRow->Cells[3]->Value->ToString() + "\"");
		App::app->toastMessage(this, "Client supprime", Color::Green, 2000);
		reloadCustomersGridView();
	}
	catch (Exception^ exception)
	{
		App::app->logger->error("Error while deleting customer: \"" + this->dataGridViewCustomers->CurrentRow->Cells[1]->Value->ToString() + "\", \"" + this->dataGridViewCustomers->CurrentRow->Cells[2]->Value->ToString() + "\", \"" + this->dataGridViewCustomers->CurrentRow->Cells[3]->Value->ToString() + "\"");
		App::app->logger->error(exception);
		App::app->toastMessage(this, "Erreur lors de la suppression du client", Color::Red, 3000);
	}
}
