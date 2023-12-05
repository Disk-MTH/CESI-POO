#include "ProductForm.h"
#include "../../App.h"
#include "../forms/TieredPriceForm.h"

int^ ProductForm::createProduct()
{
    Name = this->textBoxName->Text;
    BuyPrice = this->textBoxBuyPrice->Text;
    Quantity = this->textBoxQuantity->Text;
    RestockThreshold = this->textBoxRestockThreshold->Text;
    VAT = this->textBoxVAT->Text;

    if (App::isEmpty("Nom", Name) || App::isEmpty("Prix d'achat", BuyPrice) || App::isEmpty("Quantité", Quantity) || App::isEmpty("Seuil de réapprovisionnement", RestockThreshold) || App::isEmpty("TVA", VAT))
    {
        return 0;
    }
	
    try
    {
        if (productId == "")
        {
            productId = App::app->db->insert("INSERT INTO product (name, buy_price, quantity, provisioning_threshold, vat_rate) VALUES ('" + Name + "', '" + BuyPrice + "', '" + Quantity + "','" + RestockThreshold + "','" + VAT + "')");
        }
        else
        {
            App::app->db->execute("UPDATE product SET name = '" + Name + "', buy_price = '" + BuyPrice + "', quantity = '" + Quantity + "', provisioning_threshold = '" + RestockThreshold + "', vat_rate = '" + VAT + "'  WHERE id_product = " + productId);
        }

        App::app->logger->log("Product edited: \"" + Name + "\", \"" + BuyPrice + "\", \"" + Quantity + "\", \"" + RestockThreshold + "\", \"" + VAT + "\"");
        return 1;
    }
    catch (Exception^ exception)
    {
        App::app->logger->error("Error while editing Product: \"" + Name + "\", \"" + BuyPrice + "\", \"" + Quantity + "\", \"" + RestockThreshold + "\", \"" + VAT + "\"");
        App::app->logger->error(exception->Message);
        App::app->toastMessage(this, "Erreur lors de la modifications du client", Color::Red, 3000);
    }
    return 0;
}

void ProductForm::buttonDelete_Click(Object^ sender, EventArgs^ e)
{
    if (this->dataGridViewTieredPrice->SelectedRows->Count == 0)
    {
        App::app->logger->warn("Can't delete: no tiered price selected");
        App::app->toastMessage(this, "Veuillez selectionner un seuil de réapprovisionnement", Color::Red, 2000);
        return;
    }
	
    try
    {
        App::app->db->execute("UPDATE product SET deleted = 1 WHERE id_address = " + this->dataGridViewTieredPrice->CurrentRow->Cells[0]->Value->ToString() + ";");
        App::app->logger->log("Product deleted: \"" + this->dataGridViewTieredPrice->CurrentRow->Cells[1]->Value->ToString() + "\", \"" + this->dataGridViewTieredPrice->CurrentRow->Cells[2]->Value->ToString() + "\", \"" + this->dataGridViewTieredPrice->CurrentRow->Cells[3]->Value->ToString() + "\", \"" + this->dataGridViewTieredPrice->CurrentRow->Cells[4]->Value->ToString() + "\"");
        App::app->toastMessage(this, "Adresse supprimee", Color::Green, 2000);
        reloadGridViewTieredPrice();
    }
    catch (Exception^ exception)
    {
        App::app->logger->error("Error while deleting product: \"" + this->dataGridViewTieredPrice->CurrentRow->Cells[1]->Value->ToString() + "\", \"" + this->dataGridViewTieredPrice->CurrentRow->Cells[2]->Value->ToString() + "\", \"" + this->dataGridViewTieredPrice->CurrentRow->Cells[3]->Value->ToString() + "\", \"" + this->dataGridViewTieredPrice->CurrentRow->Cells[4]->Value->ToString() + "\"");
        App::app->logger->error(exception);
        App::app->toastMessage(this, "Erreur lors de la suppression du produit", Color::Red, 3000);
    }
}

void ProductForm::reloadGridViewTieredPrice()
{
    if (this->productId != "")
    {
        App::app->logger->warn("#######");
        this->dataGridViewTieredPrice->Rows->Clear();

        DataSet^ products = App::app->db->query(
        "SELECT minimal_quantity, tf_price FROM tiered_price WHERE deleted = 0 AND id_product =" + "1" + "ORDER BY minimal_quantity" ";");
        for (int i = 0; i < products->Tables[0]->Rows->Count; i++)
        {
            this->dataGridViewTieredPrice->Rows->Add(products->Tables[0]->Rows[i]->ItemArray);
        }
    }
}

void ProductForm::openTieredPriceForm(String^ a, String^ b, String^ c, String^ d, String^ e)
{
    if (createProduct()->Equals(1))
    {
        auto addTieredPriceForm = gcnew TieredPriceForm(a, b, c, d, e, this->productId);
        if (addTieredPriceForm->ShowDialog() == Windows::Forms::DialogResult::OK)
        {
            App::app->App::toastMessage(this, "Seuil de réapprovisionnement enregistrees", Color::Green, 3000);
            reloadGridViewTieredPrice();
        }
    }
}

void ProductForm::buttonAdd_Click(Object^ sender, EventArgs^ e)
{
    openTieredPriceForm("", "", "", "", "");
}

void ProductForm::buttonEdit_Click(Object^ sender, EventArgs^ e)
{
    if (this->dataGridViewTieredPrice->SelectedRows->Count == 0)
    {
        App::app->logger->warn("Can't edit: no tiered price selected");
        App::app->toastMessage(this, "Veuillez selectionner un seuil de réapprovisionnement", Color::Red, 2000);
        return;
    }
	
    openTieredPriceForm(
        this->dataGridViewTieredPrice->CurrentRow->Cells[0]->Value->ToString(),
        this->dataGridViewTieredPrice->CurrentRow->Cells[1]->Value->ToString(),
        this->dataGridViewTieredPrice->CurrentRow->Cells[2]->Value->ToString(),
        this->dataGridViewTieredPrice->CurrentRow->Cells[3]->Value->ToString(),
        this->dataGridViewTieredPrice->CurrentRow->Cells[4]->Value->ToString()
    );
}

void ProductForm::buttonCancel_Click(Object^ sender, EventArgs^ e)
{
    if (this->mode == "0" && productId != "" && this->DialogResult != Windows::Forms::DialogResult::OK)
    {
        try
        {
            DataSet^ products = App::app->db->query("SELECT id_product FROM product WHERE id_product = " + productId + ";");
            App::app->db->execute("DELETE FROM product WHERE id_product = " + productId + ";");
            for (int i = 0; i < products->Tables[0]->Rows->Count; i++)
            {
                App::app->db->execute("DELETE FROM tiered_price WHERE id_tiered_price = " + products->Tables[0]->Rows[i]->ItemArray[0]->ToString() + ";");
            }
        }
        catch (Exception^ exception)
        {
            App::app->logger->error(exception);
        }
    }
	
    this->Close();
}

void ProductForm::buttonValidate_Click(Object^ sender, EventArgs^ e)
{
    if (createProduct()->Equals(1))
    {
        this->DialogResult = Windows::Forms::DialogResult::OK;
        this->Close();
    }
}






