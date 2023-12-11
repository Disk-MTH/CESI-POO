#include "Logger.h"

using namespace OrderEase;
using namespace Globalization;

Logger::Logger(String^ logFolder, bool isFileEnabled, bool shouldDebug)
{
	this->isFileEnabled = isFileEnabled;
	this->shouldDebug = shouldDebug;

	if (isFileEnabled)
	{
		if (!Directory::Exists(logFolder))
		{
			Directory::CreateDirectory(logFolder);
		}

		int number = 0;
		while (File::Exists(logFolder + "\\" + getFormattedDate() + "_" + number + ".log"))
		{
			number++;
		}
		logFile = gcnew StreamWriter(logFolder + "\\" + getFormattedDate() + "_" + number + ".log");
	}
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
	Console::WriteLine(color + message + reset);

	if (isFileEnabled)
	{
		logFile->WriteLine(message);
		logFile->Flush();
	}
}

void Logger::log(String^ message)
{
	formattedPrint("Log: " + message, white);
}

void Logger::warn(String^ message)
{
	formattedPrint("Warn: " + message, yellow);
}

void Logger::warn(Exception^ exception)
{
	warn(exception->Message);
	for each (String^ line in exception->StackTrace->Split('\n'))
	{
		warn(line);
	}
}

void Logger::error(String^ message)
{
	formattedPrint("Error: " + message, red);
}

void Logger::error(Exception^ exception)
{
	error(exception->Message);
	for each (String^ line in exception->StackTrace->Split('\n'))
	{
		error(line);
	}
}

void Logger::debug(String^ message)
{
	if (shouldDebug)
	{
		formattedPrint("Debug: " + message, cyan);
	}
}