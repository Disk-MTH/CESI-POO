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

			static String^ white = "\033[1;37m";
			static String^ red = "\033[1;31m";
			static String^ green = "\033[1;32m";
			static String^ yellow = "\033[1;33m";
			static String^ orange = "\033[1;33m";
			static String^ blue = "\033[1;34m";
			static String^ magenta = "\033[1;35m";
			static String^ cyan = "\033[1;36m";
			static String^ black = "\033[1;30m";
			static String^ reset = "\033[0m";

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
