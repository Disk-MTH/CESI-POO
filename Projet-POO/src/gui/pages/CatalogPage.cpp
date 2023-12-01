#include "CatalogPage.h"
#include "../../App.h"

void CatalogPage::reloadCatalogGridView()
{
	this->dataGridViewCatalog->Rows->Clear();

	DataSet^ customers = App::app->db->query("SELECT id_product, deleted, reference, type, name, colour, buy_price, vat_rate, quantity, provisioning_threshold FROM product;");
	
	for (int i = 0; i < customers->Tables[0]->Rows->Count; i++)
	{
		this->dataGridViewCatalog->Rows->Add(customers->Tables[0]->Rows[i]->ItemArray);
	}
}

void CatalogPage::buttonAdd_Click(Object^ sender, EventArgs^ e)
{
	
}

void CatalogPage::buttonEdit_Click(Object^ sender, EventArgs^ e)
{
	
}

void CatalogPage::buttonDelete_Click(Object^ sender, EventArgs^ e)
{
	
}