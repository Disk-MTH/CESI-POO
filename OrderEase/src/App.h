#pragma once

#include "Database.h"
#include "Logger.h"
#include "gui/other/ToastMessage.h"

using namespace OrderEase;
using namespace Drawing;
using namespace Windows::Forms;

namespace OrderEase
{
	public ref class App
	{
		public:
			static App^ app = gcnew App();

			Database^ db;
			Logger^ logger;
			ToastMessage^ toast;

			void launch(array<String^>^ args);
			void toastMessage(Form^ parent, String^ message, Color color, int duration);

			static bool isEmpty(String^ name, String^ data)
			{
				if (data == "")
				{
					app->logger->warn("Invalid data \"" + name + "\": empty");
					MessageBox::Show("Le champ \"" + name + "\" est vide !", "Erreur", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return true;
				}
				return false;
			}

			static String^ isValidDate(String^ name, String^ data)
			{
				DateTime date;
				if (isEmpty(name, data) || !DateTime::TryParseExact(data, "dd/mm/yyyy", nullptr, Globalization::DateTimeStyles::None, date))
				{
					app->logger->warn("Invalid date \"" + name + "\": wrong format (\"" + data + "\")");
					MessageBox::Show("La date est invalide !\n\"dd/mm/yyyy\"", "Erreur", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return "";
				}
				return date.ToString("yyyy-mm-dd");
			}

		private:
			App()
			{
			}

			void toastMessageThread(Object^ args);
	};
}
