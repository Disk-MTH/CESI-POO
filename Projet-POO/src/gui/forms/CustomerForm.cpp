#include "CustomerForm.h"
#include "AddresseForm.h"

Void CustomerForm::buttonAdd_Click(Object^ sender, EventArgs^ e)
{
	auto addresseForm = gcnew AddresseForm();
	addresseForm->ShowDialog();
}

Void CustomerForm::buttonEdit_Click(Object^ sender, EventArgs^ e)
{
	App::app->toastMessage(this, "Fonctionnalite non implementee: Edition", Color::Red, 2000);
}

Void CustomerForm::buttonDelete_Click(Object^ sender, EventArgs^ e)
{
	App::app->toastMessage(this, "Fonctionnalite non implementee: Suppression", Color::Red, 2000);
}

Void CustomerForm::buttonCancel_Click(Object^ sender, EventArgs^ e)
{
	this->Close();
}

Void CustomerForm::buttonValidate_Click(Object^ sender, EventArgs^ e)
{
	App::app->toastMessage(this, "Fonctionnalite non implementee: Sauvegarde", Color::Red, 2000);
}
