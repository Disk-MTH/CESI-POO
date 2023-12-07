#include "StaffForm.h"
#include "../../App.h"

void StaffForm::buttonCancel_Click(Object^ sender, EventArgs^ e)
{
    this->Close();
}

void StaffForm::buttonValidate_Click(Object^ sender, EventArgs^ e)
{
    LastName = this->textBoxLastName->Text;
    FirstName = this->textBoxFirstName->Text;
    Birthdate = this->textBoxBirthdate->Text;
    Wording = this->textBoxWording->Text;
    BossLastName = this->comboBoxBossLastName->Text;
    BossFirstName = this->comboBoxBossFirstName->Text;
    ZipCode = this->comboBoxZipCode->Text;
    City = this->comboBoxCity->Text;

    if (App::isEmpty("Nom", LastName) || App::isEmpty("Prenom", FirstName) || App::isEmpty("Date de naissance", Birthdate) || App::isEmpty("Libelle", Wording) || App::isEmpty("Nom boss", BossLastName) || App::isEmpty("Prenom boss", BossFirstName) || App::isEmpty("Code postal", ZipCode) || App::isEmpty("Ville", City))
    {
        return;
    }

    try
    {
        if (staffId != "")
        {
            App::app->db->execute("UPDATE staff SET deleted = 1 WHERE id_staff = " + staffId + ";");
        }

        auto addressId = App::app->db->insert("INSERT INTO staff (id_staff, first_name, last_name, hire_date, id_staff_boss, id_address) VALUES ('" + this->staffId + "', '" + FirstName + "', '" + LastName + "'), '" + Birthdate + "', '" + Wording + "';");
        App::app->logger->log("Staff saved");
        this->DialogResult = Windows::Forms::DialogResult::OK;
        this->Close();
    }
    catch (Exception^ exception)
    {
        App::app->logger->error("Error while saving Staff");
        App::app->logger->error(exception);
        App::app->toastMessage(this, "Erreur lors de l'enregistrement du personnel", Color::Red, 3000);
    }
}
