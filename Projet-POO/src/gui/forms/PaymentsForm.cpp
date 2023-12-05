#include "PaymentsForm.h"

#include "PaymentForm.h"
#include "../../App.h"

void PaymentsForm::reloadPaymentsGridView()
{
	this->dataGridViewPaymentsDetails->Rows->Clear();

	DataSet^ orders = App::app->db->query("SELECT id_order, CONVERT(VARCHAR(10), payment_date, 103) AS payment_date,  payment_mean,  amount, validated FROM payment WHERE id_order = " + this->orderId + " ORDER BY payment_date DESC;");
	for (int i = 0; i < orders->Tables[0]->Rows->Count; i++)
	{
		this->dataGridViewPaymentsDetails->Rows->Add(orders->Tables[0]->Rows[i]->ItemArray);
	}
}

void PaymentsForm::buttonAdd_Click(Object^ sender, EventArgs^ e)
{
	openPaymentForm("", "", "", "", "");
}

void PaymentsForm::buttonEdit_Click(Object^ sender, EventArgs^ e)
{
	if (this->dataGridViewPaymentsDetails->SelectedRows->Count == 0)
	{
		App::app->logger->warn("Can't edit: no customer selected");
		App::app->toastMessage(this, "Veuillez selectionner un client", Color::Red, 2000);
		return;
	}
	openPaymentForm(
		this->dataGridViewPaymentsDetails->CurrentRow->Cells[0]->Value->ToString(),
		this->dataGridViewPaymentsDetails->CurrentRow->Cells[1]->Value->ToString(),
		this->dataGridViewPaymentsDetails->CurrentRow->Cells[2]->Value->ToString(),
		this->dataGridViewPaymentsDetails->CurrentRow->Cells[3]->Value->ToString(),
		this->dataGridViewPaymentsDetails->CurrentRow->Cells[4]->Value->ToString()
	);
}

void PaymentsForm::buttonDelete_Click(Object^ sender, EventArgs^ e)
{
	App::app->toastMessage(this, "Fonctionnalite non implementee: Supprimer un versement", Color::Red, 2000);
}

void PaymentsForm::openPaymentForm(String^ paymentId, String^ paymentDate, String^ paymentMean, String^ amount, String^ validated)
{
	auto addAddressForm = gcnew PaymentForm(paymentId, paymentDate, paymentMean, amount, validated, this->orderId);
	if (addAddressForm->ShowDialog() == Windows::Forms::DialogResult::OK)
	{
		App::app->App::toastMessage(this, "Addresses enregistrees", Color::Green, 3000);
		reloadPaymentsGridView();
	}
}
