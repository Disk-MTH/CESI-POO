#include "StatsPage.h"
#include "../../App.h"

void StatsPage::reloadLeastSoldGridView()
{
	this->dataGridViewLeastSold->Rows->Clear();

	DataSet^ orders = App::app->db->query("SELECT TOP 10 p.reference, p.type, p.name, p.colour, p.buy_price, p.vat_rate, p.quantity, p.provisioning_threshold, SUM(ohp.quantity) AS quantity_sold FROM product p INNER JOIN orderHasProduct ohp ON p.id_product = ohp.id_product GROUP BY p.reference, p.type, p.name, p.colour, p.buy_price, p.vat_rate, p.quantity, p.provisioning_threshold ORDER BY SUM(ohp.quantity) ASC;");

	for (int i = 0; i < orders->Tables[0]->Rows->Count; i++)
	{
		this->dataGridViewLeastSold->Rows->Add(orders->Tables[0]->Rows[i]->ItemArray);
	}
}

void StatsPage::reloadMostSoldGridView()
{
	this->dataGridViewMostSold->Rows->Clear();

	DataSet^ orders = App::app->db->query("SELECT TOP 10 p.reference, p.type, p.name, p.colour, p.buy_price, p.vat_rate, p.quantity, p.provisioning_threshold, SUM(ohp.quantity) AS quantity_sold FROM product p INNER JOIN orderHasProduct ohp ON p.id_product = ohp.id_product GROUP BY p.reference, p.type, p.name, p.colour, p.buy_price, p.vat_rate, p.quantity, p.provisioning_threshold ORDER BY SUM(ohp.quantity) DESC;");
		

	for (int i = 0; i < orders->Tables[0]->Rows->Count; i++)
	{
		this->dataGridViewMostSold->Rows->Add(orders->Tables[0]->Rows[i]->ItemArray);
	}
}

void StatsPage::reloadUnderThresholdGridView()
{
	this->dataGridViewUnderThreshold->Rows->Clear();

	DataSet^ orders = App::app->db->query("SELECT p.id_product, p.reference, p.type, p.name, p.colour, p.buy_price, p.vat_rate, p.quantity, p.provisioning_threshold FROM product p WHERE p.deleted = 0 AND p.quantity < p.provisioning_threshold;");
	

	for (int i = 0; i < orders->Tables[0]->Rows->Count; i++)
	{
		this->dataGridViewUnderThreshold->Rows->Add(orders->Tables[0]->Rows[i]->ItemArray);
	}
}



