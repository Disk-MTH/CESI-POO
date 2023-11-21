#include "Database.h"
#include "gui/HomePage.h"

using namespace System;
using namespace System::Windows::Forms;

int __clrcall WinMain(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Database^ db = gcnew Database();
    
    if (!db->isConnected()) {
        MessageBox::Show("Erreur de connexion a la base de données", "Erreur", MessageBoxButtons::OK, MessageBoxIcon::Error);
    } else {
        Projet_POO::HomePage form(db);
        Application::Run(% form);
    }
}