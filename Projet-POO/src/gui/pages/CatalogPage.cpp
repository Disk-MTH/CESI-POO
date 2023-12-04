#include "CatalogPage.h"
#include "../../App.h"
#include "../forms/ProductForm.h"
#include "../other/ProductDetails.h"

void CatalogPage::reloadCatalogGridView()
{
	this->dataGridViewCatalog->Rows->Clear();

	DataSet^ customers = App::app->db->query("SELECT id_product, deleted, reference, type, name, colour, buy_price, vat_rate, quantity, provisioning_threshold FROM product;");
	
	for (int i = 0; i < customers->Tables[0]->Rows->Count; i++)
	{
		this->dataGridViewCatalog->Rows->Add(customers->Tables[0]->Rows[i]->ItemArray);
	}
}

void CatalogPage::buttonProductDetails_Click(Object^ sender, EventArgs^ e)
{
	if (this->dataGridViewCatalog->SelectedRows->Count == 0)
	{
		App::app->logger->warn("Can't show details: no product selected");
		App::app->toastMessage(this, "Veuillez selectionner un produit", Color::Red, 2000);
		return;
	}
	
	auto productDetails = gcnew ProductDetails(
		this->dataGridViewCatalog->CurrentRow->Cells[0]->Value->ToString(),
		this->dataGridViewCatalog->CurrentRow->Cells[2]->Value->ToString(),
		this->dataGridViewCatalog->CurrentRow->Cells[3]->Value->ToString(),
		this->dataGridViewCatalog->CurrentRow->Cells[4]->Value->ToString(),
		this->dataGridViewCatalog->CurrentRow->Cells[5]->Value->ToString(),
		this->dataGridViewCatalog->CurrentRow->Cells[6]->Value->ToString(),
		this->dataGridViewCatalog->CurrentRow->Cells[7]->Value->ToString(),
		this->dataGridViewCatalog->CurrentRow->Cells[8]->Value->ToString(),
		this->dataGridViewCatalog->CurrentRow->Cells[9]->Value->ToString()
		);
	productDetails->ShowDialog();
}

void CatalogPage::buttonAdd_Click(Object^ sender, EventArgs^ e)
{
	auto addCustomerForm = gcnew ProductForm();
	if (addCustomerForm->ShowDialog() == Windows::Forms::DialogResult::OK)
	{
		App::app->App::toastMessage(this, "Modifications enregistrees", Color::Green, 3000);
		reloadCatalogGridView();
	}
}

void CatalogPage::buttonEdit_Click(Object^ sender, EventArgs^ e)
{
	
}

void CatalogPage::buttonDelete_Click(Object^ sender, EventArgs^ e)
{
	
}