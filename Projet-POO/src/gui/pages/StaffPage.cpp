#include "StaffPage.h"
#include "../../App.h"
#include "../forms/StaffForm.h"

void StaffPage::reloadStaffGridView()
{
    this->dataGridViewStaff->Rows->Clear();

    DataSet^ Staff = App::app->db->query(
        "SELECT id_staff, first_name, last_name, CONVERT(VARCHAR, hire_date, 103) AS hire_date, deleted, id_staff_boss, id_address FROM staff" + (this->checkBoxDeleted->Checked ? ";" : " WHERE deleted = 0;"));

    for (int i = 0; i < Staff->Tables[0]->Rows->Count; i++)
    {
        this->dataGridViewStaff->Rows->Add(Staff->Tables[0]->Rows[i]->ItemArray);
    }
}

void StaffPage::openStaffForm(String^ idStaff, String^ firstName, String^ lastName, String^ hireDate)
{
    auto addStaffForm = gcnew StaffForm(idStaff, lastName, firstName, hireDate);
    if (addStaffForm->ShowDialog() == Windows::Forms::DialogResult::OK)
    {
        App::app->App::toastMessage(this, "Modifications enregistrees", Color::Green, 3000);
        reloadStaffGridView();
    }
}

void StaffPage::checkBoxDeleted_Click(Object^ sender, EventArgs^ e)
{
    reloadStaffGridView();	
}

void StaffPage::buttonAdd_Click(Object^ sender, EventArgs^ e)
{
    openStaffForm("", "", "", "");
}

void StaffPage::buttonEdit_Click(Object^ sender, EventArgs^ e)
{
    if (this->dataGridViewStaff->SelectedRows->Count == 0)
    {
        App::app->logger->warn("Can't edit: no customer selected");
        App::app->toastMessage(this, "Veuillez selectionner un client", Color::Red, 2000);
        return;
    }
	
    openStaffForm(
        this->dataGridViewStaff->CurrentRow->Cells[0]->Value->ToString(),
        this->dataGridViewStaff->CurrentRow->Cells[1]->Value->ToString(),
        this->dataGridViewStaff->CurrentRow->Cells[2]->Value->ToString(),
        this->dataGridViewStaff->CurrentRow->Cells[3]->Value->ToString()
    );
}

void StaffPage::buttonDelete_Click(Object^ sender, EventArgs^ e)
{
    if (this->dataGridViewStaff->SelectedRows->Count == 0)
    {
        App::app->logger->warn("Can't delete: no customer selected");
        App::app->toastMessage(this, "Veuillez selectionner un client", Color::Red, 2000);
        return;
    }
	
    try
    {
        App::app->db->execute("UPDATE staff SET deleted = 1 WHERE id_staff = " + this->dataGridViewStaff->CurrentRow->Cells[0]->Value->ToString() + ";");
        App::app->logger->log("Customer deleted");
        App::app->toastMessage(this, "Client supprime", Color::Green, 2000);
        reloadStaffGridView();
    }
    catch (Exception^ exception)
    {
        App::app->logger->error("Error while deleting customer");
        App::app->logger->error(exception);
        App::app->toastMessage(this, "Erreur lors de la suppression du client", Color::Red, 3000);
    }
}
