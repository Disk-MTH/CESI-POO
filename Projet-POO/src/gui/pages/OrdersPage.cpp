#include "OrdersPage.h"
#include "../../App.h"
#include "../forms/OrderForm.h"
#include "../forms/PaymentsForm.h"
#include "../other/OrderDetails.h"

void OrdersPage::reloadOrdersGridView()
{
	this->dataGridViewOrders->Rows->Clear();

	DataSet^ orders = App::app->db->query(
		"SELECT o.id_order, o.reference, c.last_name, c.first_name, CONVERT(VARCHAR(10), c.birthdate, 103) AS birthdate, CONVERT(VARCHAR(10), o.issue_date, 103) AS issue_date, CONVERT(VARCHAR(10), o.expected_delivery_date, 103) AS expected_delivery_date, CONCAT(b.street, ', ', b.zip_code, ', ', b.city) AS billing_address, CONCAT(d.street, ', ', d.zip_code, ', ', d.city) AS delivery_address, SUM(ohp.price) AS total_amount, (SELECT SUM(amount) FROM payment WHERE id_order = o.id_order) AS payed_amount, CONVERT(VARCHAR(10), IIF((SELECT SUM(amount) FROM payment WHERE id_order = o.id_order) = SUM(ohp.price), (SELECT MAX(payment_date) FROM payment WHERE id_order = o.id_order), NULL), 103) AS payment_date, SUM(ohp.vat_price) AS vat_amount, SUM(ohp.tf_price) AS tf_amount FROM [order] o INNER JOIN customer c ON o.id_customer = c.id_customer INNER JOIN address b ON o.id_billing_address = b.id_address INNER JOIN address d ON o.id_delivery_address = d.id_address INNER JOIN orderHasProduct ohp ON o.id_order = ohp.id_order "
		+ (this->checkBoxDeleted->Checked ? "" : "WHERE o.deleted = 0") + " GROUP BY o.id_order, o.reference, o.issue_date, o.expected_delivery_date, c.last_name, c.first_name, c.birthdate, b.street, b.zip_code, b.city, d.street, d.zip_code, d.city;");
	for (int i = 0; i < orders->Tables[0]->Rows->Count; i++)
	{
		this->dataGridViewOrders->Rows->Add(orders->Tables[0]->Rows[i]->ItemArray);
	}
}

void OrdersPage::openOrderForm()
{
	/*if (createCustomer()->Equals(1))
	{
		auto addAddressForm = gcnew AddresseForm(addressId, address, zipCode, city, type, this->customerId);
		if (addAddressForm->ShowDialog() == Windows::Forms::DialogResult::OK)
		{
			App::app->App::toastMessage(this, "Addresses enregistrees", Color::Green, 3000);
			reloadAddressesGridView();
		}
	}*/

	auto orderForm = gcnew OrderForm();
	if (orderForm->ShowDialog() == Windows::Forms::DialogResult::OK)
	{
		App::app->App::toastMessage(this, "Addresses enregistrees", Color::Green, 3000);
		reloadOrdersGridView();
	}
}

void OrdersPage::checkBoxDeleted_Click(Object^ sender, EventArgs^ e)
{
	reloadOrdersGridView();
}

void OrdersPage::buttonPayments_Click(Object^ sender, EventArgs^ e)
{
	if (this->dataGridViewOrders->SelectedRows->Count == 0)
	{
		App::app->logger->warn("Can't show payments details: no order selected");
		App::app->toastMessage(this, "Veuillez selectionner une commande", Color::Red, 2000);
		return;
	}

	auto paymentsForm = gcnew PaymentsForm(
		this->dataGridViewOrders->CurrentRow->Cells[0]->Value->ToString(),
		this->dataGridViewOrders->CurrentRow->Cells[1]->Value->ToString()
	);
	paymentsForm->ShowDialog();
}

void OrdersPage::buttonOrderDetails_Click(Object^ sender, EventArgs^ e)
{
	if (this->dataGridViewOrders->SelectedRows->Count == 0)
	{
		App::app->logger->warn("Can't show details: no order selected");
		App::app->toastMessage(this, "Veuillez selectionner une commande", Color::Red, 2000);
		return;
	}

	auto orderDetails = gcnew OrderDetails(
		this->dataGridViewOrders->CurrentRow->Cells[0]->Value->ToString(),
		this->dataGridViewOrders->CurrentRow->Cells[1]->Value->ToString(),
		this->dataGridViewOrders->CurrentRow->Cells[2]->Value->ToString() + " " + this->dataGridViewOrders->CurrentRow->Cells[3]->Value->ToString(),
		this->dataGridViewOrders->CurrentRow->Cells[4]->Value->ToString(),
		this->dataGridViewOrders->CurrentRow->Cells[7]->Value->ToString(),
		this->dataGridViewOrders->CurrentRow->Cells[8]->Value->ToString(),
		this->dataGridViewOrders->CurrentRow->Cells[5]->Value->ToString(),
		this->dataGridViewOrders->CurrentRow->Cells[6]->Value->ToString(),
		this->dataGridViewOrders->CurrentRow->Cells[9]->Value->ToString(),
		this->dataGridViewOrders->CurrentRow->Cells[12]->Value->ToString(),
		this->dataGridViewOrders->CurrentRow->Cells[13]->Value->ToString()
	);
	orderDetails->ShowDialog();
}

void OrdersPage::buttonAdd_Click(Object^ sender, EventArgs^ e)
{
	openOrderForm();
}

void OrdersPage::buttonEdit_Click(Object^ sender, EventArgs^ e)
{
	if (this->dataGridViewOrders->SelectedRows->Count == 0)
	{
		App::app->logger->warn("Can't edit: no order selected");
		App::app->toastMessage(this, "Veuillez selectionner une commande", Color::Red, 2000);
		return;
	}

	openOrderForm();
}

void OrdersPage::buttonDelete_Click(Object^ sender, EventArgs^ e)
{
	App::app->toastMessage(this, "Fonctionnalite non implementee: Supprimer une commande", Color::Red, 2000);
}

void OrdersPage::openOrderDetailsForm()
{

}
