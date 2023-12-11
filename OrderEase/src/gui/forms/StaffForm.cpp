#include "StaffForm.h"
#include "../../App.h"

void StaffForm::retrieveSuggestion(ComboBox^ comboBox, String^ query)
{
    DataSet^ lastNames = App::app->db->query(query->Replace("{data}", comboBox->Text));
    comboBox->Items->Clear();
    for (int i = 0; i < lastNames->Tables[0]->Rows->Count; i++)
    {
        comboBox->Items->Add(lastNames->Tables[0]->Rows[i]->ItemArray[0]->ToString());
    }
    comboBox->SelectionStart = comboBox->Text->Length;
}

void StaffForm::comboBoxUser_keyPress(Object^ sender, KeyPressEventArgs^ e)
{
    retrieveSuggestion(this->comboBoxBossFirstName, "SELECT first_name FROM staff WHERE first_name LIKE '{data}%' AND last_name LIKE '" + this->comboBoxBossLastName->Text + "%' AND deleted = 0;");
    retrieveSuggestion(this->comboBoxBossLastName, "SELECT last_name FROM staff WHERE last_name LIKE '{data}%' AND first_name LIKE '" + this->comboBoxBossFirstName->Text + "%' AND deleted = 0;");
}

void StaffForm::comboBoxAddress_keyPress(Object^ sender, KeyPressEventArgs^ e)
{
    retrieveSuggestion(this->comboBoxZipCode, "SELECT DISTINCT zip_code FROM address WHERE zip_code LIKE '{data}%' AND deleted = 0;");
    retrieveSuggestion(this->comboBoxCity, "SELECT DISTINCT city FROM address WHERE zip_code = '" + this->comboBoxZipCode->Text + "' AND city LIKE '{data}%' AND deleted = 0;");
}

void StaffForm::boxInt_KeyPress(Object^ sender, KeyPressEventArgs^ e)
{
    if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08)
    {
        e->Handled = true;
    }
}

void StaffForm::boxDate_KeyPress(Object^ sender, KeyPressEventArgs^ e)
{
    if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08 && e->KeyChar != 0x2F)
    {
        e->Handled = true;
    }
}

void StaffForm::buttonCancel_Click(Object^ sender, EventArgs^ e)
{
    this->Close();
}

void StaffForm::buttonValidate_Click(Object^ sender, EventArgs^ e)
{
    lastName = this->textBoxLastName->Text;
    firstName = this->textBoxFirstName->Text;
    hireDate = this->textBoxHireDate->Text;
    wording = this->textBoxWording->Text;
    bossLastName = this->comboBoxBossLastName->Text;
    bossFirstName = this->comboBoxBossFirstName->Text;
    zipCode = this->comboBoxZipCode->Text;
    city = this->comboBoxCity->Text;

    if (App::isEmpty("Nom", lastName) || App::isEmpty("Prenom", firstName) || App::isValidDate("Date d'embauche", hireDate) == "" || App::isEmpty("Libelle", wording) || App::isEmpty("Code postal", zipCode) || App::isEmpty("Ville", city))
    {
        return;
    }

    hireDate = App::isValidDate("Date d'embauche", hireDate);
    
    String^ bossId = "";
    if (bossFirstName != "" && bossLastName != "")
    {
        try
        {
            DataSet^ product = App::app->db->query("SELECT id_staff FROM staff WHERE first_name = '" + bossFirstName + "' AND last_name = '" + bossLastName + "' AND deleted = 0;");
            bossId = product->Tables[0]->Rows[0]->ItemArray[0]->ToString();
        }
        catch (Exception^ exception)
        {
            App::app->logger->error("Error retrieving boss id: " + bossFirstName + " " + bossLastName);
            App::app->logger->error(exception);
            App::app->toastMessage(this, "Le superieur n'existe pas", Color::Red, 3000);
            return;
        }
    }
    
    try
    {
        DataSet^ address = App::app->db->query("SELECT id_address FROM address WHERE street = '" + wording + "' AND zip_code = '" + zipCode + "' AND city = '" + city + "';");
        String^ addressId;
        if (address->Tables[0]->Rows->Count == 0)
        {
            addressId = App::app->db->insert("INSERT INTO address (street, zip_code, city) VALUES ('" + wording + "', '" + zipCode + "', '" + city + "');");
        }
        else
        {
            addressId = address->Tables[0]->Rows[0]->ItemArray[0]->ToString();
        }

        if (staffId != "")
        {
            App::app->db->insert("UPDATE staff SET last_name = '" + lastName + "', first_name = '" + firstName + "', hire_date = '" + hireDate + "', id_staff_boss = " + (bossId == "" ? "NULL" : bossId) + ", id_address = " + addressId + " WHERE id_staff = " + staffId + ";");
        }
        else
        {
            App::app->db->insert("INSERT INTO staff (last_name, first_name, hire_date, id_staff_boss, id_address) VALUES ('" + lastName + "', '" + firstName + "', '" + hireDate + "', " + (bossId == "" ? "NULL" : bossId) + ", " + addressId + ");");
        }
        
        App::app->logger->log("Staff saved: " + lastName + " " + firstName + " " + hireDate + " " + bossId + " " + addressId);
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
