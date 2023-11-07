#include "BDD.h"
#include "MyForm.h"
using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]

int __clrcall WinMain(array<String^>^ args)
{
    BDD^ mabdd = gcnew BDD();
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Project2::MyForm monFormulaire;//ATTENTION : ici testWin est le nom du projet. Vous devez l'adapter au nom de votre projet
    Application::Run(% monFormulaire);
}