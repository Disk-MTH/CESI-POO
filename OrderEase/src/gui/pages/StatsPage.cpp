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

void StatsPage::retrieveSuggestion(ComboBox^ comboBox, String^ query)
{
	DataSet^ lastNames = App::app->db->query(query->Replace("{data}", comboBox->Text));
	comboBox->Items->Clear();
	for (int i = 0; i < lastNames->Tables[0]->Rows->Count; i++)
	{
		comboBox->Items->Add(lastNames->Tables[0]->Rows[i]->ItemArray[0]->ToString());
	}
	comboBox->SelectionStart = comboBox->Text->Length;
}

void StatsPage::comboBox_keyPress(Object^ sender, KeyPressEventArgs^ e)
{
	retrieveSuggestion(this->comboBoxFirstName, "SELECT first_name FROM customer WHERE first_name LIKE '{data}%' AND last_name LIKE '" + this->comboBoxLastName->Text + "%' AND deleted = 0;");
	retrieveSuggestion(this->comboBoxLastName, "SELECT last_name FROM customer WHERE last_name LIKE '{data}%' AND first_name LIKE '" + this->comboBoxFirstName->Text + "%' AND deleted = 0;");
	retrieveSuggestion(this->comboBoxBirthdate, "SELECT CONVERT(VARCHAR(10), birthdate, 103) AS birthdate FROM customer WHERE CONVERT(VARCHAR(10), birthdate, 103) LIKE '{data}%' AND last_name = '" + this->comboBoxLastName->Text + "' AND first_name = '" + this->comboBoxFirstName->Text + "' AND deleted = 0;");
}

void StatsPage::boxInt_KeyPress(Object^ sender, KeyPressEventArgs^ e)
{
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08)
	{
		e->Handled = true;
	}
}

void StatsPage::boxFloat_KeyPress(Object^ sender, KeyPressEventArgs^ e)
{
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08 && e->KeyChar != 0x2C && e->KeyChar != 0x2E)
	{
		e->Handled = true;
	}
}

void StatsPage::boxDate_KeyPress(Object^ sender, KeyPressEventArgs^ e)
{
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08 && e->KeyChar != 0x2F)
	{
		e->Handled = true;
	}
}

void StatsPage::buttonCustomer_Click(Object^ sender, EventArgs^ e)
{
	String^ lastName = this->comboBoxLastName->Text;
	String^ firstName = this->comboBoxFirstName->Text;
	String^ birthdate = this->comboBoxBirthdate->Text;

	if (App::isEmpty("Nom", lastName) || App::isEmpty("Prenom", firstName) || App::isValidDate("Date de naissance", birthdate) == "")
	{
		return;
	}

	birthdate = App::isValidDate("Date de naissance", birthdate);
	
	String^ value = App::app->db->query("SELECT ROUND(SUM(ohp.price), 3) AS sum_of_purchases_costs FROM [order] o INNER JOIN customer c ON o.id_customer = c.id_customer INNER JOIN address b ON o.id_billing_address = b.id_address INNER JOIN address d ON o.id_delivery_address = d.id_address INNER JOIN orderHasProduct ohp ON o.id_order = ohp.id_order WHERE o.deleted = 0 AND c.last_name = '" + lastName + "' AND c.first_name = '" + firstName + "' AND c.birthdate = '" + birthdate + "' ;")->Tables[0]->Rows[0]->ItemArray[0]->ToString();
	this->labelCustomerTotal->Text = value + " $";
}

void StatsPage::buttonTurnover_Click(Object^ sender, EventArgs^ e)
{
	String^ month = this->textBoxMonth->Text;
	String^ year = this->textBoxYear->Text;

	if (App::isEmpty("Mois", month) || App::isEmpty("Annee", year))
	{
		return;
	}
	
	String^ value = App::app->db->query("SELECT ROUND((SUM(ohp.price) - SUM(p.buy_price)), 3) AS turnover FROM [order] o INNER JOIN customer c ON o.id_customer = c.id_customer INNER JOIN address b ON o.id_billing_address = b.id_address INNER JOIN address d ON o.id_delivery_address = d.id_address INNER JOIN orderHasProduct ohp ON o.id_order = ohp.id_order INNER JOIN product p ON ohp.id_product = p.id_product WHERE o.deleted = 0 AND MONTH(o.issue_date) = " + month + " AND YEAR(o.issue_date) = " + year + " ;")->Tables[0]->Rows[0]->ItemArray[0]->ToString();
	this->labelValueTurnover->Text = value + " $";
}

void StatsPage::buttonValue_Click(Object^ sender, EventArgs^ e)
{
	String^ margin = this->comboBoxMargin->Text->Replace(",", ".");
	String^ vat = this->comboBoxVat->Text->Replace(",", ".");
	String^ reduction = this->comboBoxReduction->Text->Replace(",", ".");
	String^ losses = this->comboBoxLosses->Text->Replace(",", ".");

	if (App::isEmpty("Marge", margin) || App::isEmpty("TVA", vat) || App::isEmpty("Reduction", reduction) || App::isEmpty("Pertes", losses))
	{
		return;
	}
	
	String^ value = App::app->db->query("SELECT ROUND((SUM(p.buy_price * (1 + (" + margin + "/100.0)) * (1 + (" + vat + "/100.0)) * (1 - (" + reduction + "/100.0)) * (1 - (" + losses + "/100.0)) * p.quantity) - SUM(p.buy_price * p.quantity)), 3) AS turnover_of_current_stock FROM product p INNER JOIN tiered_price tp ON p.id_product = tp.id_product WHERE p.deleted = 0 AND tp.minimal_quantity = 1;")->Tables[0]->Rows[0]->ItemArray[0]->ToString();
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







