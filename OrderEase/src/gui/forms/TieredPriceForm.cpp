#include "TieredPriceForm.h"
#include "../../App.h"

void TieredPriceForm::boxInt_KeyPress(Object^ sender, KeyPressEventArgs^ e)
{
    if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08)
    {
        e->Handled = true;
    }
}

void TieredPriceForm::boxFloat_KeyPress(Object^ sender, KeyPressEventArgs^ e)
{
    if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08 && e->KeyChar != 0x2C && e->KeyChar != 0x2E)
    {
        e->Handled = true;
    }
}

void TieredPriceForm::buttonCancel_Click(Object^ sender, EventArgs^ e)
{
    this->Close();
}

void TieredPriceForm::buttonValidate_Click(Object^ sender, EventArgs^ e)
{
    quantity = this->textBoxQuantity->Text->Replace(",", ".");
    tfprice = this->textBoxTfPrice->Text;
    
    if (App::isEmpty("Quantité", quantity) || App::isEmpty("Prix hors taxe", tfprice))
    {
        return;
    }

    try
    {
        if (tieredpriceId != "")
        {
            App::app->db->execute("UPDATE tiered_price SET deleted = 1 WHERE id_tiered_price = " + tieredpriceId + ";");
        }

        App::app->db->insert("INSERT INTO tiered_price (id_product, minimal_quantity, tf_price) VALUES ('" + this->productId + "', '" + quantity + "', '" + tfprice + "');");
        App::app->logger->log("tiered price saved: \"" + quantity + "\", \"" + tfprice + "\", and asociated to product id: \"" + this->productId + "\"");
        this->DialogResult = Windows::Forms::DialogResult::OK;
        this->Close();
    }
    catch (Exception^ exception)
    {
        App::app->logger->error("Error while saving tiered price: \"" + quantity + "\", \"" + tfprice + "\"");
        App::app->logger->error(exception);
        App::app->toastMessage(this, "Erreur lors de l'enregistrement du seuil de reaprovisionement", Color::Red, 3000);
    }
}
