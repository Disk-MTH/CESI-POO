#include "App.h"

#include "gui/HomePage.h"
#include "gui/LoadingScreen.h"

using namespace Projet_POO;
using namespace System;
using namespace System::Threading;
using namespace System::Windows::Forms;

void App::launch(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	db = gcnew Database();
	
	LoadingScreen^ loadingPage = gcnew LoadingScreen();
	loadingPage->Show();
	
	Thread^ dbConnectionThread = gcnew Thread(gcnew ParameterizedThreadStart(db, &Database::connect));
	dbConnectionThread->Start("Data Source=127.0.0.1,1433;Initial Catalog = database;User ID=sa;Password=4pQ4ZVpJz22g6z");

	while (dbConnectionThread->IsAlive)
	{
		Application::DoEvents();
		Thread::Sleep(100);
	}

	loadingPage->Close();

	if (!db->isConnected())
	{
		MessageBox::Show("Erreur de connexion a la base de donnees", "Erreur", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	Application::Run(gcnew HomePage());
	db->disconnect();
}
