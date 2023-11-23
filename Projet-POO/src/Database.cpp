﻿#include "Database.h"

using namespace Projet_POO;

void Database::connect()
{
    try
    {
        String^ connectionString = "Data Source=127.0.0.1,1433;Initial Catalog = databas;User ID=sa;Password=4pQ4ZVpJz22g6z";
        connection = gcnew SqlConnection(connectionString);
        connection->Open();
        connected = true;
        Console::WriteLine("Database has been connected");
    }
    catch (Exception^ exception)
    {
        connected = false;
        Console::WriteLine("Database connection failed");
        Console::WriteLine(exception->ToString());
    }
}

void Database::disconnect()
{
    try
    {
        connection->Close();
        connected = false;
        Console::WriteLine("Database has been disconnected");
    }
    catch (Exception^ exception)
    {
        connected = false;
        Console::WriteLine("Database disconnection failed");
        Console::WriteLine(exception->ToString());
    }
}

Boolean Database::isConnected()
{
    return connected;
}

Data::DataSet^ Database::query(String^ sql)
{
    SqlDataAdapter^ dataAdapter = gcnew SqlDataAdapter(sql, this->connection);
    Data::DataSet^ dataSet = gcnew Data::DataSet();
    dataAdapter->Fill(dataSet);
    return dataSet;
}

int Database::execute(String^ sql)
{
    SqlCommand^ command = gcnew SqlCommand(sql, this->connection);
    return command->ExecuteNonQuery();
}

int Database::insert(String^ sql)
{
    SqlCommand^ command = gcnew SqlCommand(sql + ";SELECT @@IDENTITY", this->connection);
    return Decimal::ToInt32(safe_cast<Decimal>(command->ExecuteScalar()));
}