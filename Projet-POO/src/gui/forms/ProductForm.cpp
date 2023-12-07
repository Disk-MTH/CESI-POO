#include "ProductForm.h"
#include "../../App.h"
#include "../forms/TieredPriceForm.h"

void ProductForm::reloadGridViewTieredPrice()
{
    if (this->productId != "")
    {
        this->dataGridViewTieredPrice->Rows->Clear();

        DataSet^ products = App::app->db->query(
        "SELECT minimal_quantity, tf_price, id_tiered_price FROM tiered_price WHERE deleted = 0 AND id_product =" + productId + "ORDER BY minimal_quantity" ";");
        for (int i = 0; i < products->Tables[0]->Rows->Count; i++)
        {
            this->dataGridViewTieredPrice->Rows->Add(products->Tables[0]->Rows[i]->ItemArray);
        }
    }
}

void ProductForm::retreiveSuggestion(ComboBox^ comboBox, String^ query)
{
    DataSet^ lastNames = App::app->db->query(query->Replace("{data}", comboBox->Text));
    comboBox->Items->Clear();
    for (int i = 0; i < lastNames->Tables[0]->Rows->Count; i++)
    {
        comboBox->Items->Add(lastNames->Tables[0]->Rows[i]->ItemArray[0]->ToString());
    }
    comboBox->SelectionStart = comboBox->Text->Length;
}

int^ ProductForm::createProduct()
{
    name = this->textBoxName->Text;
    buyPrice = this->textBoxBuyPrice->Text->Replace(",", ".");
    quantity = this->textBoxQuantity->Text;
    restockThreshold = this->textBoxRestockThreshold->Text;
    vat = this->textBoxVat->Text->Replace(",",".");
    type = this->comboBoxType->Text;
    colour = this->comboBoxColour->Text;
    
    if (App::isEmpty("Nom", name) || App::isEmpty("Prix d'achat", buyPrice) || App::isEmpty("Quantité", quantity) || App::isEmpty("Seuil de réapprovisionnement", restockThreshold) || App::isEmpty("TVA", vat) || App::isEmpty("Nature", type) || App::isEmpty("Couleur", colour))
    {
        return 0;
    }
	
    try
    {
        if (productId == "")
        {
            App::app->logger->warn("warn1");
            productId = App::app->db->insert("INSERT INTO product (name, buy_price, quantity, provisioning_threshold, vat_rate, type, colour, reference) VALUES ('" + name + "', '" + buyPrice + "', '" + quantity + "','" + restockThreshold + "','" + vat + "','" + type + "','" + colour + "','" + "testRef" + "')");
        }
        else
        {
            App::app->logger->warn("warn2");
            App::app->db->execute("UPDATE product SET name = '" + name + "', buy_price = '" + buyPrice + "', quantity = '" + quantity + "', provisioning_threshold = '" + restockThreshold + "', vat_rate = '" + vat + "', type = '" + type + "', colour = '" + colour + "'  WHERE id_product = " + productId);
        }

        App::app->logger->log("Product edited: \"" + name + "\", \"" + buyPrice + "\", \"" + quantity + "\", \"" + restockThreshold + "\", \"" + vat + "\"");
        return 1;
    }
    catch (Exception^ exception)
    {
        App::app->logger->error("Error while editing Product: \"" + name + "\", \"" + buyPrice + "\", \"" + quantity + "\", \"" + restockThreshold + "\", \"" + vat + "\"");
        App::app->logger->error(exception->Message);
        App::app->toastMessage(this, "Erreur lors de la modifications du client", Color::Red, 3000);
    }
    return 0;
}

void ProductForm::openTieredPriceForm(String^ tieredpriceId, String^ quantity, String^ tfprice)
{
    if (createProduct()->Equals(1))
    {
        auto addTieredPriceForm = gcnew TieredPriceForm(tieredpriceId, quantity, tfprice, this->productId);
        if (addTieredPriceForm->ShowDialog() == Windows::Forms::DialogResult::OK)
        {
            App::app->App::toastMessage(this, "Seuil de réapprovisionnement enregistrees", Color::Green, 3000);
            reloadGridViewTieredPrice();
        }
    }
}

void ProductForm::buttonAdd_Click(Object^ sender, EventArgs^ e)
{
    openTieredPriceForm("", "", "");
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
        this->dataGridViewTieredPrice->CurrentRow->Cells[2]->Value->ToString(),
        this->dataGridViewTieredPrice->CurrentRow->Cells[0]->Value->ToString(),
        this->dataGridViewTieredPrice->CurrentRow->Cells[1]->Value->ToString()
    );
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
        App::app->db->execute("UPDATE tiered_price SET deleted = 1 WHERE id_tiered_price = " + this->dataGridViewTieredPrice->CurrentRow->Cells[2]->Value->ToString() + ";");
        App::app->logger->log("tiered price deleted: \"" + this->dataGridViewTieredPrice->CurrentRow->Cells[1]->Value->ToString() + "\", \"" + this->dataGridViewTieredPrice->CurrentRow->Cells[2]->Value->ToString() + "\"");
        App::app->toastMessage(this, "Adresse supprimee", Color::Green, 2000);
        reloadGridViewTieredPrice();
    }
    catch (Exception^ exception)
    {
        App::app->logger->error("Error while deleting product: \"" + this->dataGridViewTieredPrice->CurrentRow->Cells[1]->Value->ToString() + "\", \"" + this->dataGridViewTieredPrice->CurrentRow->Cells[2]->Value->ToString() + "\"");
        App::app->logger->error(exception);
        App::app->toastMessage(this, "Erreur lors de la suppression du produit", Color::Red, 3000);
    }
}

void ProductForm::buttonCancel_Click(Object^ sender, EventArgs^ e)
{
    if (this->mode == "0" && productId != "" && this->DialogResult != Windows::Forms::DialogResult::OK)
    {
        try
        {
            DataSet^ products = App::app->db->query("SELECT id_product FROM product WHERE id_product = " + productId + ";");
            App::app->db->execute("DELETE FROM tiered_price WHERE id_product = " + productId + ";");
            App::app->db->execute("DELETE FROM product WHERE id_product = " + productId + ";");
            for (int i = 0; i < products->Tables[0]->Rows->Count; i++)
            {
                App::app->db->execute("DELETE FROM tiered_price WHERE id_tiered_price = " + products->Tables[0]->Rows[i]->ItemArray[0]->ToString() + ";");
            }
        }
        catch (Exception^ exception)
        {
            App::app->logger->error("Error while deleting product: \"" + this->dataGridViewTieredPrice->CurrentRow->Cells[1]->Value->ToString() + "\", \"" + this->dataGridViewTieredPrice->CurrentRow->Cells[2]->Value->ToString() + "\"");
            App::app->logger->error(exception);
            App::app->toastMessage(this, "Erreur lors de la suppression du produit", Color::Red, 3000);
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
