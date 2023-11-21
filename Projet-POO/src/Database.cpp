#include "Database.h"

Database::Database()
{
    try
    {
        String^ connectionString = "Data Source=127.0.0.1,1433;Initial Catalog = database;User ID=sa;Password=4pQ4ZVpJz22g6z";
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

Database::~Database()
{
    connection->Close();
    Console::WriteLine("Database has been disconnected");
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