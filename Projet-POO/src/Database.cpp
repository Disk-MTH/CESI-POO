#include "Database.h"

Database::Database()
{
    try
    {
        String^ connectionString = "Data Source=127.0.0.1,1433;Initial Catalog = database;User ID=sa;Password=4pQ4ZVpJz22g6z";
        connection_ = gcnew SqlConnection(connectionString);
        connection_->Open();
        Console::WriteLine("Database has been connected");
    }
    catch (Exception^ exception)
    {
        Console::WriteLine("Database connection failed");
        Console::WriteLine(exception->ToString());
    }
}

Database::~Database()
{
    connection_->Close();
    Console::WriteLine("Database has been disconnected");
}

Data::DataSet^ Database::query(String^ sql)
{
    log(sql);
    SqlDataAdapter^ dataAdapter = gcnew SqlDataAdapter(sql, this->connection_);
    Data::DataSet^ dataSet = gcnew Data::DataSet();
    dataAdapter->Fill(dataSet);
    return dataSet;
}

int Database::execute(String^ sql)
{
    log(sql);
    SqlCommand^ command = gcnew SqlCommand(sql, this->connection_);
    return command->ExecuteNonQuery();
}

int Database::insert(String^ sql)
{
    log(sql);
    SqlCommand^ command = gcnew SqlCommand(sql + ";SELECT @@IDENTITY", this->connection_);
    return Decimal::ToInt32(safe_cast<Decimal>(command->ExecuteScalar()));
}