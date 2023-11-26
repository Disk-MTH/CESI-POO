#pragma once
#include "Database.h"
#include "gui/ToastMessage.h"

namespace Projet_POO
{
	using namespace Drawing;
	using namespace Windows::Forms;
	
	public ref class App sealed
	{
		public:
			static App^ app = gcnew App();
		
			Database^ db;

			void launch(array<String^>^ args);
		
			static void toastMessage(Form^ parent, String^ message, Color color, int duration)
			{
				ToastMessage^ toast = gcnew ToastMessage(parent, message, color, duration);
				toast->Show();
			}

		private:
			App() {}
	};
}
