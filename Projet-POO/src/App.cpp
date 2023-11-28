#include "App.h"
#include "gui/pages/HomePage.h"
#include "gui/other/LoadingScreen.h"

using namespace Projet_POO;
using namespace System;
using namespace System::Threading;
using namespace System::Windows::Forms;

void App::launch(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	db = gcnew Database();
	bool isFileEnabled = false;
	bool shouldDebug = false;

	for (int i = 0; i < args->Length; i++)
	{
		if (args[i] == "logs=true")
		{
			isFileEnabled = true;
		}
		else if (args[i] == "debug=true")
		{
			shouldDebug = true;
		}
	}
	logger = gcnew Logger("logs", isFileEnabled, shouldDebug);
	logger->log("Logger initialized with logs " + (isFileEnabled ? Logger::green + "enable" : Logger::red + "disable") + Logger::white + " and debug " + (shouldDebug ? Logger::green + "enable" : Logger::red + "disable"));

	auto loadingPage = gcnew LoadingScreen();
	loadingPage->Show();

	auto dbConnectionThread = gcnew Thread(gcnew ParameterizedThreadStart(db, &Database::connect));
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

void App::toastMessage(Form^ parent, String^ message, Color color, const int duration)
{
	auto toastThread = gcnew Thread(gcnew ParameterizedThreadStart(this, &App::toastMessageThread));
	toastThread->Start(gcnew array<Object^>{parent, message, color, duration});
	toastThread->IsBackground = true;
}

void App::toastMessageThread(Object^ args)
{
	auto argsArray = static_cast<array<Object^>^>(args);
	auto parent = static_cast<Form^>(argsArray[0]);
	auto message = static_cast<String^>(argsArray[1]);
	auto color = static_cast<Color>(argsArray[2]);
	const auto duration = static_cast<int>(argsArray[3]);
	
	while (!parent->IsHandleCreated)
	{
		Thread::Sleep(100);
	}

	if (this->toast != nullptr)
	{
		parent->Invoke(gcnew Action(this->toast, &ToastMessage::close));
		this->toast = nullptr;
	}

	while (!parent->IsHandleCreated)
	{
		Thread::Sleep(100);
	}
	
	this->toast = gcnew ToastMessage(parent, message, color, duration);
	parent->Invoke(gcnew Action(this->toast, &ToastMessage::show));

	while (this->toast->Visible)
	{
		Application::DoEvents();
		Thread::Sleep(100);
	}
}
