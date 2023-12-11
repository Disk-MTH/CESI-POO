#include "PaymentForm.h"
#include "../../App.h"

void PaymentForm::retrieveSuggestion(ComboBox^ comboBox, String^ query)
{
	DataSet^ lastNames = App::app->db->query(query->Replace("{data}", comboBox->Text));
	comboBox->Items->Clear();
	for (int i = 0; i < lastNames->Tables[0]->Rows->Count; i++)
	{
		comboBox->Items->Add(lastNames->Tables[0]->Rows[i]->ItemArray[0]->ToString());
	}
	comboBox->SelectionStart = comboBox->Text->Length;
}

void PaymentForm::boxFloat_KeyPress(Object^ sender, KeyPressEventArgs^ e)
{
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08 && e->KeyChar != 0x2E && e->KeyChar != 0x2C)
	{
		e->Handled = true;
	}
}

void PaymentForm::boxDate_KeyPress(Object^ sender, KeyPressEventArgs^ e)
{
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08 && e->KeyChar != 0x2F)
	{
		e->Handled = true;
	}
}

void PaymentForm::buttonCancel_Click(Object^ sender, EventArgs^ e)
{
	this->Close();
}

void PaymentForm::buttonValidate_Click(Object^ sender, EventArgs^ e)
{
	amount = this->textBoxAmount->Text->Replace(".", ",");
	paymentMean = this->comboBoxType->Text;
	paymentDate = this->textBoxDate->Text;
	validated = this->checkBoxValided->Checked ? "True" : "False";

	if (App::isEmpty("Montant", amount) || App::isEmpty("Moyen de paiement", paymentMean) || App::isValidDate("Date", paymentDate) == "")
	{
		return;
	}

	paymentDate = App::isValidDate("Date", paymentDate);

	if (Convert::ToDouble(payedAmount) + Convert::ToDouble(amount) > Convert::ToDouble(totalAmount))
	{
		App::app->logger->warn("Can't save: payment amount is greater than order amount");
		App::app->toastMessage(this, "Le montant du versement ne peut pas etre superieur au montant de la commande", Color::Red, 3000);
		return;
	}

	amount = amount->Replace(",", ".");
	
	try
	{
		if (mode == "0")
		{
			App::app->db->insert("INSERT INTO payment (id_order, payment_date, payment_mean, amount, validated) VALUES ('" + orderId + "', '" + paymentDate + "', '" + paymentMean + "', '" + amount + "', '" + validated + "');");
		}
		else
		{
			App::app->db->execute("UPDATE payment SET payment_date = '" + paymentDate + "', payment_mean = '" + paymentMean + "', amount = '" + amount + "', validated = '" + validated + "' WHERE id_payment = " + paymentId + " ;");
		}

		App::app->logger->log("Payment saved: \"" + amount + "\", \"" + paymentMean + "\", \"" + paymentDate + "\", \"" + validated + "\" and asociated to order id: \"" + orderId + "\"");
		this->DialogResult = Windows::Forms::DialogResult::OK;
		this->Close();
	}
	catch (Exception^ exception)
	{
		App::app->logger->error("Error while saving payment: \"" + amount + "\", \"" + paymentMean + "\", \"" + paymentDate + "\", \"" + validated + "\"");
		App::app->logger->error(exception);
		App::app->toastMessage(this, "Erreur lors de l'enregistrement du versement", Color::Red, 3000);
	}

}
