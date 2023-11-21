#include "BDD.h"
#include "gui/HomePage.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

int __clrcall WinMain(array<String^>^ args)
{
    //BDD^ mabdd = gcnew BDD();
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Project2::HomePage form;
    Application::Run(% form);
}