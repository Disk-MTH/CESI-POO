#include "OrderDetails.h"
#include "../../App.h"

void OrderDetails::reloadProductsGridView()
{
	this->dataGridViewTieredPrices->Rows->Clear();

	DataSet^ products = App::app->db->query(
		"SELECT p.type, p.name, p.colour, ohp.quantity, ohp.tf_price,+ ohp.price FROM product p INNER JOIN orderHasProduct ohp ON p.id_product = ohp.id_product WHERE ohp.id_order = " + this->orderId + "ORDER BY ohp.quantity DESC;");

	for (int i = 0; i < products->Tables[0]->Rows->Count; i++)
	{
		this->dataGridViewTieredPrices->Rows->Add(products->Tables[0]->Rows[i]->ItemArray);
	}
}
