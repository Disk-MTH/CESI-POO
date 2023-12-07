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

void StatsPage::buttonCustomer_Click(Object^ sender, EventArgs^ e)
{
	String^ LastName = this->comboBoxLastName->Text;
	String^ FirstName = this->comboBoxFirstName->Text;
	String^ Birthdate = App::isValidDate("error",this->comboBoxBirthDate->Text);
	String^ value = App::app->db->query("SELECT ROUND(SUM(ohp.price), 3) AS sum_of_purchases_costs FROM [order] o INNER JOIN customer c ON o.id_customer = c.id_customer INNER JOIN address b ON o.id_billing_address = b.id_address INNER JOIN address d ON o.id_delivery_address = d.id_address INNER JOIN orderHasProduct ohp ON o.id_order = ohp.id_order WHERE o.deleted = 0 AND c.last_name = '" + LastName + "' AND c.first_name = '" + FirstName + "' AND c.birthdate = '" + Birthdate + "' ;")->Tables[0]->Rows[0]->ItemArray[0]->ToString();
	this->labelCustomerTotal->Text = value + " $";
}

void StatsPage::buttonTurnover_Click(Object^ sender, EventArgs^ e)
{
	String ^Month = this->textBoxMonth->Text;
	String ^Year = this->textBoxYear->Text;
	String^ value = App::app->db->query("SELECT ROUND((SUM(ohp.price) - SUM(p.buy_price)), 3) AS turnover FROM [order] o INNER JOIN customer c ON o.id_customer = c.id_customer INNER JOIN address b ON o.id_billing_address = b.id_address INNER JOIN address d ON o.id_delivery_address = d.id_address INNER JOIN orderHasProduct ohp ON o.id_order = ohp.id_order INNER JOIN product p ON ohp.id_product = p.id_product WHERE o.deleted = 0 AND MONTH(o.issue_date) = " + Month + " AND YEAR(o.issue_date) = " + Year + " ;")->Tables[0]->Rows[0]->ItemArray[0]->ToString();
	this->labelValueTurnover->Text = value + " $";
}

void StatsPage::buttonValue_Click(Object^ sender, EventArgs^ e)
{
	String^ Margin = this->textBoxMargin->Text;
	String^ Vat = this->textBoxVat->Text;
	String^ Reduction = this->textBoxReduction->Text;
	String^ Losses = this->textBoxLosses->Text;
	String^ value = App::app->db->query("SELECT ROUND((SUM(p.buy_price * (1 + (" + Margin + "/100.0)) * (1 + (" + Vat + "/100.0)) * (1 - (" + Reduction + "/100.0)) * (1 - (" + Losses + "/100.0)) * p.quantity) - SUM(p.buy_price * p.quantity)), 3) AS turnover_of_current_stock FROM product p INNER JOIN tiered_price tp ON p.id_product = tp.id_product WHERE p.deleted = 0 AND tp.minimal_quantity = 1;")->Tables[0]->Rows[0]->ItemArray[0]->ToString();
	this->labelCalculatedValue->Text = value + " $";
}

void StatsPage::reloadAverageCart()
{
	String^ value = App::app->db->query("SELECT total_amount AS average_order_total_price FROM (SELECT ROUND(SUM(ohp.price), 3) / COUNT(o.id_order) AS total_amount FROM [order] o INNER JOIN customer c ON o.id_customer = c.id_customer INNER JOIN address b ON o.id_billing_address = b.id_address INNER JOIN address d ON o.id_delivery_address = d.id_address INNER JOIN orderHasProduct ohp ON o.id_order = ohp.id_order WHERE o.deleted = 0) AS total_amount;")->Tables[0]->Rows[0]->ItemArray[0]->ToString();
	this->labelAverageCart->Text = "Panier moyen : " + value + " $";
}

void StatsPage::reloadStockValue()
{
	String^ value = App::app->db->query("SELECT SUM(p.buy_price * p.quantity) AS total_buy_price_value_of_current_stock FROM product p WHERE p.deleted = 0;")->Tables[0]->Rows[0]->ItemArray[0]->ToString();
	this->labelValueStock->Text = value + " $";
}







