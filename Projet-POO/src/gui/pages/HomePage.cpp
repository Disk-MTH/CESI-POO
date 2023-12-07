#include "HomePage.h"
#include "../../App.h"
#include "CustomersPage.h"
#include "OrdersPage.h"
#include "CatalogPage.h"
#include "StaffPage.h"
#include "StatsPage.h"
#include "../forms/OrderForm.h"
#include "../other/OrderDetails.h"

Void HomePage::buttonCustomers_Click(Object^ sender, EventArgs^ e)
{
	this->Hide();
	auto customersPage = gcnew CustomersPage();
	customersPage->ShowDialog();
	this->Show();
}

Void HomePage::buttonStaff_Click(Object^ sender, EventArgs^ e)
{
	this->Hide();
	auto staffPage = gcnew StaffPage();
	staffPage->ShowDialog();
	this->Show();
}

Void HomePage::buttonCatalog_Click(Object^ sender, EventArgs^ e)
{
	this->Hide();
	auto catalogPage = gcnew CatalogPage();
	catalogPage->ShowDialog();
	this->Show();
}

Void HomePage::buttonStats_Click(Object^ sender, EventArgs^ e)
{
	this->Hide();
	auto catalogPage = gcnew StatsPage();
	catalogPage->ShowDialog();
	this->Show();
}

Void HomePage::buttonOrders_Click(Object^ sender, EventArgs^ e)
{
	this->Hide();
	auto ordersPage = gcnew OrdersPage();
	ordersPage->ShowDialog();
	this->Show();
}
