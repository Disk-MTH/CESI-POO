#include "StaffPage.h"
#include "../../App.h"
#include "../forms/StaffForm.h"

void StaffPage::reloadStaffGridView()
{
    this->dataGridViewStaff->Rows->Clear();

    DataSet^ staff = App::app->db->query(
        "SELECT s.id_staff, s.last_name, s.first_name, CONVERT(VARCHAR(10), s.hire_date, 103), a.street, a.zip_code, a.city, b.last_name, b.first_name FROM staff s INNER JOIN address a on a.id_address = s.id_address LEFT JOIN staff b on b.id_staff = s.id_staff_boss" + (this->checkBoxDeleted->Checked ? ";" : " WHERE s.deleted = 0;"));

    for (int i = 0; i < staff->Tables[0]->Rows->Count; i++)
    {
        this->dataGridViewStaff->Rows->Add(staff->Tables[0]->Rows[i]->ItemArray);
    }
}

void StaffPage::openStaffForm(String^ idStaff, String^ lastName, String^ firstName, String^ hireDate, String^ wording, String^ zipCode, String^ city, String^ bossLastName, String^ bossFirstName)
{
    auto addStaffForm = gcnew StaffForm(idStaff, lastName, firstName, hireDate, wording, zipCode, city, bossLastName, bossFirstName);
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
    openStaffForm("", "", "", "", "", "", "", "", "");
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
        this->dataGridViewStaff->CurrentRow->Cells[3]->Value->ToString(),
        this->dataGridViewStaff->CurrentRow->Cells[4]->Value->ToString(),
        this->dataGridViewStaff->CurrentRow->Cells[5]->Value->ToString(),
        this->dataGridViewStaff->CurrentRow->Cells[6]->Value->ToString(),
        this->dataGridViewStaff->CurrentRow->Cells[7]->Value->ToString(),
        this->dataGridViewStaff->CurrentRow->Cells[8]->Value->ToString()
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
