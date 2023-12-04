#include "OrdersPage.h"
#include "../../App.h"

void OrdersPage::reloadOrdersGridView()
{
	this->dataGridViewOrders->Rows->Clear();

	DataSet^ orders = App::app->db->query("SELECT o.id_order, o.reference, o.issue_date, o.expected_delivery_date, c.last_name, c.first_name, c.birthdate, CONCAT(b.street, ', ', b.zip_code, ', ', b.city) AS billing_address, CONCAT(d.street, ', ', d.zip_code, ', ', d.city) AS delivery_address, SUM(ohp.price) AS total_amount, (SELECT SUM(amount) FROM payment WHERE id_order = o.id_order) AS payment_amount, IIF((SELECT SUM(amount) FROM payment WHERE id_order = o.id_order) = SUM(ohp.price), (SELECT MAX(payment_date) FROM payment WHERE id_order = o.id_order), NULL) AS payment_date FROM [order] o INNER JOIN customer c ON o.id_customer = c.id_customer INNER JOIN address b ON o.id_billing_address = b.id_address INNER JOIN address d ON o.id_delivery_address = d.id_address INNER JOIN orderHasProduct ohp ON o.id_order = ohp.id_order WHERE o.deleted = 0 GROUP BY o.id_order, o.reference, o.issue_date, o.expected_delivery_date, c.last_name, c.first_name, c.birthdate, b.street, b.zip_code, b.city, d.street, d.zip_code, d.city;");

	for (int i = 0; i < orders->Tables[0]->Rows->Count; i++)
	{
		this->dataGridViewOrders->Rows->Add(orders->Tables[0]->Rows[i]->ItemArray);
	}
}

void OrdersPage::openOrderForm()
{
	
}

void OrdersPage::checkBoxDeleted_Click(Object^ sender, EventArgs^ e)
{
	reloadOrdersGridView();
}

void OrdersPage::buttonPayments_Click(Object^ sender, EventArgs^ e)
{
	App::app->toastMessage(this, "Fonctionnalite non implementee: Paiements", Color::Red, 2000);
}

void OrdersPage::buttonOrderDetails_Click(Object^ sender, EventArgs^ e)
{
	App::app->toastMessage(this, "Fonctionnalite non implementee: Details de la commande", Color::Red, 2000);
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




