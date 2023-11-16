#include "BDD.h"
#include "gui/MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

int __clrcall WinMain(array<String^>^ args)
{
    BDD^ mabdd = gcnew BDD();
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Project2::MyForm form;
    Application::Run(% form);
}