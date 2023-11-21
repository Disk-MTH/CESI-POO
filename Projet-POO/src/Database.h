#pragma once

using namespace System;
using namespace System::Data::SqlClient;

public ref class Database sealed
{
    public:
        Database();
        ~Database();

        Boolean isConnected();
        Data::DataSet^ query(String^ sql);
        int execute(String^ sql);
        int insert(String^ sql);

    SqlConnection^ connection;
    Boolean connected;
};