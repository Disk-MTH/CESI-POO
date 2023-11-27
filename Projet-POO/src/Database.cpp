#include "Database.h"
#include "App.h"

using namespace Projet_POO;

void Database::connect(Object^ connectionString)
{
    try
    {
        connection = gcnew SqlConnection(safe_cast<String^>(connectionString));
        connection->Open();
        connected = true;
        App::app->logger->log("Database has been " + Logger::GREEN + "connected");
    }
    catch (Exception^ exception)
    {
        connected = false;
        App::app->logger->error("Database connection failed");
        App::app->logger->error(exception->ToString());
    }
}

void Database::disconnect()
{
    try
    {
        connection->Close();
        connected = false;
        App::app->logger->log("Database has been " + Logger::RED + "disconnected");
    }
    catch (Exception^ exception)
    {
        connected = false;
        App::app->logger->error("Database disconnection failed");
        App::app->logger->error(exception->ToString());
    }
}

Boolean Database::isConnected()
{
    return connected;
}

Data::DataSet^ Database::query(String^ sql)
{
    App::app->logger->debug("Sql: " + Logger::MAGENTA + "query");
    App::app->logger->debug(sql);
    SqlDataAdapter^ dataAdapter = gcnew SqlDataAdapter(sql, this->connection);
    Data::DataSet^ dataSet = gcnew Data::DataSet();
    dataAdapter->Fill(dataSet);
    return dataSet;
}

int Database::execute(String^ sql)
{
    App::app->logger->debug("Sql: " + Logger::MAGENTA + "execute");
    App::app->logger->debug(sql);
    SqlCommand^ command = gcnew SqlCommand(sql, this->connection);
    return command->ExecuteNonQuery();
}

int Database::insert(String^ sql)
{
    App::app->logger->debug("Sql: " + Logger::MAGENTA + "insert");
    App::app->logger->debug(sql);
    SqlCommand^ command = gcnew SqlCommand(sql + ";SELECT @@IDENTITY", this->connection);
    return Decimal::ToInt32(safe_cast<Decimal>(command->ExecuteScalar()));
}