#pragma once

using namespace System;
using namespace System::Data::SqlClient;

public ref class Database sealed
{
    SqlConnection^ connection_;
    static void Database::log(String^ sql)
    {
        Console::WriteLine("Sql query string: " + sql);
    }
    
    public:
        Database();
        ~Database();
    
        Data::DataSet^ query(String^ sql);
        int execute(String^ sql);
        int insert(String^ sql);
};