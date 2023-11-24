#include "Database.h"

using namespace Projet_POO;

void Database::connect(Object^ connectionString)
{
    try
    {
        connection = gcnew SqlConnection(safe_cast<String^>(connectionString));
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