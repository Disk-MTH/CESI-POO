#pragma once

using namespace System;
using namespace Data;
using namespace SqlClient;

namespace Projet_POO
{
	public ref class Database
	{
		public:
			void connect(Object^ connectionString);
			void disconnect();
			bool^ isConnected();
			DataSet^ query(String^ sql);
			String^ execute(String^ sql);
			String^ insert(String^ sql);

			SqlConnection^ connection;
			Boolean connected;
	};
}
