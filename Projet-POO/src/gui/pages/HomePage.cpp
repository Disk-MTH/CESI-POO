#include "HomePage.h"
#include "CustomersPage.h"
#include "OrdersPage.h"

Void HomePage::buttonCustomers_Click(Object^ sender, EventArgs^ e)
{
	this->Hide();
	auto customersPage = gcnew CustomersPage();
	customersPage->ShowDialog();
	this->Show();
}

Void HomePage::buttonStaff_Click(Object^ sender, EventArgs^ e)
{
	App::app->toastMessage(this, "Fonctionnalite non implementee: Personnel", Color::Red, 2000);
}

Void HomePage::buttonCatalog_Click(Object^ sender, EventArgs^ e)
{
	App::app->toastMessage(this, "Fonctionnalite non implementee: Catalogue", Color::Red, 2000);
}

Void HomePage::buttonStats_Click(Object^ sender, EventArgs^ e)
{
	App::app->toastMessage(this, "Fonctionnalite non implementee: Statistiques", Color::Red, 2000);
}

Void HomePage::buttonOrders_Click(Object^ sender, EventArgs^ e)
{
	this->Hide();
	auto ordersPage = gcnew OrdersPage();
	ordersPage->ShowDialog();
	this->Show();
}