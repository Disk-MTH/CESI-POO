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
        App::app->logger->log("Database has been " + Logger::green + "connected");
    }
    catch (Exception^ exception)
    {
        connected = false;
        App::app->logger->error("Database connection failed");
        App::app->logger->error(exception);
    }
}

void Database::disconnect()
{
    try
    {
        connection->Close();
        connected = false;
        App::app->logger->log("Database has been " + Logger::red + "disconnected");
    }
    catch (Exception^ exception)
    {
        connected = false;
        App::app->logger->error("Database disconnection failed");
        App::app->logger->error(exception);
    }
}

bool^ Database::isConnected()
{
    return connected;
}

DataSet^ Database::query(String^ sql)
{
    App::app->logger->debug("Sql: " + Logger::magenta + "query");
    App::app->logger->debug(sql);
    SqlDataAdapter^ dataAdapter = gcnew SqlDataAdapter(sql, this->connection);
    DataSet^ dataSet = gcnew DataSet();
    dataAdapter->Fill(dataSet);
    return dataSet;
}

String^ Database::execute(String^ sql)
{
    App::app->logger->debug("Sql: " + Logger::magenta + "execute");
    App::app->logger->debug(sql);
    auto command = gcnew SqlCommand(sql, this->connection);
    return command->ExecuteNonQuery().ToString();
}

String^ Database::insert(String^ sql)
{
    sql += ";SELECT @@IDENTITY";
    App::app->logger->debug("Sql: " + Logger::magenta + "insert");
    App::app->logger->debug(sql);
    auto command = gcnew SqlCommand(sql, this->connection);
    return command->ExecuteScalar()->ToString();
}