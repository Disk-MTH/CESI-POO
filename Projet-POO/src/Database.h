#pragma once

using namespace System;
using namespace System::Data::SqlClient;

namespace Projet_POO
{
	public ref class Database sealed
	{
		public:
			void connect();
			void disconnect();
			Boolean isConnected();
			Data::DataSet^ query(String^ sql);
			int execute(String^ sql);
			int insert(String^ sql);

			SqlConnection^ connection;
			Boolean connected;
	};
}
