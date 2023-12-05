#include "PaymentForm.h"
#include "../../App.h"

void PaymentForm::buttonCancel_Click(Object^ sender, EventArgs^ e)
{
	this->Close();
}

void PaymentForm::buttonValidate_Click(Object^ sender, EventArgs^ e)
{
	amount = this->textBoxAmount->Text;
	paymentMean = this->comboBoxType->Text;
	paymentDate = this->textBoxDate->Text;
	validated = this->checkBoxValided->Checked ? "True" : "False";

	if (App::isEmpty("Montant", amount) || App::isEmpty("Moyen de paiement", paymentMean) || App::isEmpty("Date", paymentDate))
	{
		return;
	}

	try //TODO : FIX EDITING CAUSING A DUPLICATE
	{
		if (paymentId != "")
		{
			App::app->db->execute("DELETE FROM payment WHERE id_payment = " + paymentId + ";");
		}

		auto paymentId = App::app->db->insert("INSERT INTO payment (payment_date, payment_mean, amount, validated, id_order) VALUES ('" + paymentDate + "', '" + paymentMean + "', '" + amount + "', '" + validated + "', '" + this->orderId + "');");

		App::app->logger->log("Payment saved: \"" + amount + "\", \"" + paymentMean + "\", \"" + paymentDate + "\", \"" + validated + "\" and asociated to order id: \"" + this->orderId + "\"");
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
