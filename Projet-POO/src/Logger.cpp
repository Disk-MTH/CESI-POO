#include "Logger.h"
#include "cstdio"

using namespace Projet_POO;
using namespace Globalization;

Logger::Logger(String^ logFolder, bool isFileEnabled)
{
	this->isFileEnabled = isFileEnabled;
	int number = 0;

	if (!Directory::Exists(logFolder))
	{
		Directory::CreateDirectory(logFolder);
	}

	while (File::Exists(logFolder + "\\" + getFormattedDate() + "_" + number + ".log"))
	{
		number++;
	}
	logFile = gcnew StreamWriter(logFolder + "\\" + getFormattedDate() + "_" + number + ".log");
}

Logger::~Logger()
{
	if (logFile != nullptr)
	{
		logFile->Close();
	}
}

void Logger::formattedPrint(String^ message, String^ color)
{
	message = getFormattedTime() + " - " + message;
	Console::WriteLine(color + message + RESET);

	if (isFileEnabled)
	{
		logFile->WriteLine(message);
		logFile->Flush();
	}
}

void Logger::log(String^ message)
{
	formattedPrint("Log: " + message, WHITE);
}

void Logger::warn(String^ message)
{
	formattedPrint("Warn: " + message, YELLOW);
}

void Logger::error(String^ message)
{
	formattedPrint("Error: " + message, RED);
}