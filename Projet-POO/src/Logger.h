#pragma once

using namespace System;
using namespace IO;

namespace Projet_POO
{
	public ref class Logger sealed
	{
		bool isFileEnabled;
		bool shouldDebug;
		StreamWriter^ logFile;
		
		public:
			Logger(String^ logFolder, bool isFileEnabled, bool shouldDebug);
			~Logger();

			void formattedPrint(String^ message, String^ color);
			void log(String^ message);
			void warn(String^ message);
			void error(String^ message);
			void debug(String^ message);

			static String^ WHITE = "\033[1;37m";
			static String^ RED = "\033[1;31m";
			static String^ GREEN = "\033[1;32m";
			static String^ YELLOW = "\033[1;33m";
			static String^ BLUE = "\033[1;34m";
			static String^ MAGENTA = "\033[1;35m";
			static String^ CYAN = "\033[1;36m";
			static String^ BLACK = "\033[1;30m";
			static String^ RESET = "\033[0m";

			static String^ getFormattedDate()
			{
				return DateTime::Now.ToString("dd-MM-yyyy");
			}

			static String^ getFormattedTime()
			{
				return DateTime::Now.ToString("HH-mm-ss");
			}
	};
}
