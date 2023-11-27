#pragma once

#include "Database.h"
#include "Logger.h"
#include "gui/other/ToastMessage.h"

using namespace Projet_POO;
using namespace Drawing;
using namespace Windows::Forms;

namespace Projet_POO
{
	public ref class App sealed
	{
		public:
			static App^ app = gcnew App();

			Database^ db;
			Logger^ logger;
			ToastMessage^ toast;

			void launch(array<String^>^ args);
			void toastMessage(Form^ parent, String^ message, Color color, int duration);
		
		private:
			App()
			{
			}
		
			void toastMessageThread(Object^ args);
	};
}
