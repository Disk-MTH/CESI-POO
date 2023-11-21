#include "Database.h"
#include "gui/HomePage.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

int __clrcall WinMain(array<String^>^ args)
{
    Database^ mabdd = gcnew Database();
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Project2::HomePage form;
    Application::Run(% form);
}