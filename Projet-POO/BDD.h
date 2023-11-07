#pragma once
#pragma once

using namespace System;
using namespace System::Data::SqlClient;

public ref class BDD
{
public:
    BDD();
    ~BDD();
    System::Data::DataSet^ executeQuery(String^ sql);
    int executeNonQuery(String^ sql);
    int executeInsert(String^ sql);
    SqlConnection^ connection;

};