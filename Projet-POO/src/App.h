#pragma once
#include "Database.h"

namespace Projet_POO
{
	public ref class App sealed
	{
		public:
			static App^ app = gcnew App();
		
			Database^ db;

			void launch(array<String^>^ args);

		private:
			App() {}
	};
}
