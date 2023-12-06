#include "CatalogPage.h"
#include "../../App.h"
#include "../forms/ProductForm.h"
#include "../other/ProductDetails.h"

void CatalogPage::reloadCatalogGridView()
{
	this->dataGridViewCatalog->Rows->Clear();

	DataSet^ customers = App::app->db->query("SELECT id_product, deleted, reference, type, name, colour, buy_price, vat_rate, quantity, provisioning_threshold FROM product WHERE deleted = 0;");
	
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
	auto addProductForm = gcnew ProductForm("","","","","","","","");
	if (addProductForm->ShowDialog() == Windows::Forms::DialogResult::OK)
	{
		App::app->App::toastMessage(this, "Modifications enregistrees", Color::Green, 3000);
		reloadCatalogGridView();
	}
}

void CatalogPage::buttonEdit_Click(Object^ sender, EventArgs^ e)
{
	App::app->logger->warn("#######################");
	if (this->dataGridViewCatalog->SelectedRows->Count == 0)
	{
		App::app->logger->warn("Can't edit: no customer selected");
		App::app->toastMessage(this, "Veuillez selectionner un client", Color::Red, 2000);
		return;
	}
	
	auto editCustomerFOrm = gcnew ProductForm(
		this->dataGridViewCatalog->CurrentRow->Cells[0]->Value->ToString(),
		this->dataGridViewCatalog->CurrentRow->Cells[9]->Value->ToString(),
		this->dataGridViewCatalog->CurrentRow->Cells[7]->Value->ToString(),
		this->dataGridViewCatalog->CurrentRow->Cells[8]->Value->ToString(),
		this->dataGridViewCatalog->CurrentRow->Cells[6]->Value->ToString(),
		this->dataGridViewCatalog->CurrentRow->Cells[4]->Value->ToString(),
		this->dataGridViewCatalog->CurrentRow->Cells[3]->Value->ToString(),
		this->dataGridViewCatalog->CurrentRow->Cells[5]->Value->ToString()
	);
	if (editCustomerFOrm->ShowDialog() == Windows::Forms::DialogResult::OK)
	{
		App::app->App::toastMessage(this, "Modifications enregistrees", Color::Green, 3000);
		reloadCatalogGridView();
	}
}

void CatalogPage::buttonDelete_Click(Object^ sender, EventArgs^ e)
{
	if (this->dataGridViewCatalog->SelectedRows->Count == 0)
	{
		App::app->logger->warn("Can't delete: product selected");
		App::app->toastMessage(this, "Veuillez selectionner un produit", Color::Red, 2000);
		return;
	}
	
	try
	{
		App::app->db->execute("UPDATE product SET deleted = 1 WHERE id_product = " + this->dataGridViewCatalog->CurrentRow->Cells[0]->Value->ToString() + ";");
		App::app->logger->log("product deleted: \"" + this->dataGridViewCatalog->CurrentRow->Cells[0]->Value->ToString() + "\", \"" + this->dataGridViewCatalog->CurrentRow->Cells[2]->Value->ToString() + "\"");
		App::app->toastMessage(this, "Adresse supprimee", Color::Green, 2000);
		reloadCatalogGridView();
	}
	catch (Exception^ exception)
	{
		App::app->logger->error("Error while deleting product: \"" + this->dataGridViewCatalog->CurrentRow->Cells[1]->Value->ToString() + "\", \"" + this->dataGridViewCatalog->CurrentRow->Cells[2]->Value->ToString() + "\"");
		App::app->logger->error(exception);
		App::app->toastMessage(this, "Erreur lors de la suppression du produit", Color::Red, 3000);
	}
}
