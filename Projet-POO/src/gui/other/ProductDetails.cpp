#include "ProductDetails.h"
#include "../../App.h"

void ProductDetails::reloadTieredPricesGridView()
{
	this->dataGridViewTieredPrices->Rows->Clear();

	DataSet^ tiredPrices = App::app->db->query("SELECT minimal_quantity, tf_price, ROUND(tf_price * (1 + vat_rate / 100), 3) AS price FROM tiered_price INNER JOIN product p ON tiered_price.id_product = p.id_product WHERE p.deleted = 0 AND p.id_product = " + this->productId + ";");
	
	for (int i = 0; i < tiredPrices->Tables[0]->Rows->Count; i++)
	{
		this->dataGridViewTieredPrices->Rows->Add(tiredPrices->Tables[0]->Rows[i]->ItemArray);
	}
}
