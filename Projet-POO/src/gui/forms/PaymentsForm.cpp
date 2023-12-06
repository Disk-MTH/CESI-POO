#include "PaymentsForm.h"

#include "PaymentForm.h"
#include "../../App.h"

void PaymentsForm::reloadPaymentsGridView()
{
	this->dataGridViewPaymentsDetails->Rows->Clear();

	DataSet^ orders = App::app->db->query("SELECT id_payment, id_order, CONVERT(VARCHAR(10), payment_date, 103) AS payment_date, payment_mean,  amount, validated FROM payment WHERE id_order = " + orderId + " ORDER BY payment_date DESC;");
	for (int i = 0; i < orders->Tables[0]->Rows->Count; i++)
	{
		this->dataGridViewPaymentsDetails->Rows->Add(orders->Tables[0]->Rows[i]->ItemArray);
	}

	payedAmount = "0";
	for (int i = 0; i < this->dataGridViewPaymentsDetails->Rows->Count; i++)
	{
		payedAmount = Convert::ToString(Convert::ToDouble(payedAmount) + Convert::ToDouble(this->dataGridViewPaymentsDetails->Rows[i]->Cells[4]->Value->ToString()));
	}
}

void PaymentsForm::openPaymentForm(String^ paymentId, String^ orderId, String^ mean, String^ date, String^ amount, String^ validated)
{
	auto addAddressForm = gcnew PaymentForm(paymentId, orderId, mean, date, amount, validated, totalAmount, amount == "" ? payedAmount : (Convert::ToDouble(payedAmount) - Convert::ToDouble(amount)).ToString());
	if (addAddressForm->ShowDialog() == Windows::Forms::DialogResult::OK)
	{
		App::app->App::toastMessage(this, "Payements enregistres", Color::Green, 3000);
		reloadPaymentsGridView();
	}
}

void PaymentsForm::buttonAdd_Click(Object^ sender, EventArgs^ e)
{
	if (Convert::ToDouble(payedAmount) >= Convert::ToDouble(this->totalAmount))
	{
		App::app->logger->warn("Can't add: order is already payed");
		MessageBox::Show("La commande est deja payee", "Erreur", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	else
	{
		openPaymentForm(
			"",
			orderId,
			"",
			"",
			"",
			""
			);
	}
}

void PaymentsForm::buttonEdit_Click(Object^ sender, EventArgs^ e)
{
	if (this->dataGridViewPaymentsDetails->SelectedRows->Count == 0)
	{
		App::app->logger->warn("Can't edit: no payment selected");
		App::app->toastMessage(this, "Veuillez selectionner un payement", Color::Red, 2000);
		return;
	}
	
	openPaymentForm(
		this->dataGridViewPaymentsDetails->CurrentRow->Cells[0]->Value->ToString(),
		"",
		this->dataGridViewPaymentsDetails->CurrentRow->Cells[2]->Value->ToString(),
		this->dataGridViewPaymentsDetails->CurrentRow->Cells[3]->Value->ToString(),
		this->dataGridViewPaymentsDetails->CurrentRow->Cells[4]->Value->ToString(),
		this->dataGridViewPaymentsDetails->CurrentRow->Cells[5]->Value->ToString()
	);
}

void PaymentsForm::buttonDelete_Click(Object^ sender, EventArgs^ e)
{
	if (this->dataGridViewPaymentsDetails->SelectedRows->Count == 0)
	{
		App::app->logger->warn("Can't delete: no payment selected");
		App::app->toastMessage(this, "Veuillez selectionner un payement", Color::Red, 2000);
		return;
	}

	try
	{
		App::app->db->execute("DELETE FROM payment WHERE id_payment = " + this->dataGridViewPaymentsDetails->CurrentRow->Cells[0]->Value->ToString() + ";");

		App::app->logger->log("Payment deleted: \"" + this->dataGridViewPaymentsDetails->CurrentRow->Cells[2]->Value->ToString() + "\", \"" + this->dataGridViewPaymentsDetails->CurrentRow->Cells[3]->Value->ToString() + "\", \"" + this->dataGridViewPaymentsDetails->CurrentRow->Cells[4]->Value->ToString() + "\", \"" + this->dataGridViewPaymentsDetails->CurrentRow->Cells[5]->Value->ToString() + "\"");
		App::app->toastMessage(this, "Payement supprime", Color::Green, 2000);
		reloadPaymentsGridView();
	}
	catch (Exception^ exception)
	{
		App::app->logger->error("Error while deleting payment: \"" + this->dataGridViewPaymentsDetails->CurrentRow->Cells[2]->Value->ToString() + "\", \"" + this->dataGridViewPaymentsDetails->CurrentRow->Cells[3]->Value->ToString() + "\", \"" + this->dataGridViewPaymentsDetails->CurrentRow->Cells[4]->Value->ToString() + "\", \"" + this->dataGridViewPaymentsDetails->CurrentRow->Cells[5]->Value->ToString() + "\"");
		App::app->logger->error(exception);
		App::app->toastMessage(this, "Erreur lors de la suppression du payement", Color::Red, 3000);
	}
}