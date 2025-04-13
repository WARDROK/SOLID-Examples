#include <iostream>
#include <memory>
#include <string>

// Abstract interface for a Database connection.
// Both high-level and low-level modules depend on this abstraction.
class IDatabase
{
public:
    virtual bool connect(const std::string &connectionString) = 0;
    virtual void disconnect() = 0;
    virtual void query(const std::string &queryString) = 0;
    virtual ~IDatabase() = default;
};

// Concrete implementation
class MySQLDatabase : public IDatabase
{
public:
    bool connect(const std::string &connectionString) override
    {
        std::cout << "Connecting to MySQL database with: " << connectionString << std::endl;
        // Simulate a succesfull connection.
        return true;
    }
    void disconnect() override
    {
        std::cout << "Disconnecting from MySQL database" << std::endl;
    }
    void query(const std::string &queryString) override
    {
        std::cout << "Executing MySQL query: " << queryString << std::endl;
    }
};

// Another concrete implementation
class SQLiteDatabase : public IDatabase
{
public:
    bool connect(const std::string &connectionString) override
    {
        std::cout << "Connecting to SQLite database with: " << connectionString << std::endl;
        // Simulate a successful connection.
        return true;
    }
    void disconnect() override
    {
        std::cout << "Disconnecting from SQLite database" << std::endl;
    }
    void query(const std::string &queryString) override
    {
        std::cout << "Executing SQLite query: " << queryString << std::endl;
    }
};

// High-level module that depends on the IDatabase abstraction.
class DataManager
{
public:
    // The database dependency is injected via the constructor.
    explicit DataManager(std::unique_ptr<IDatabase> db) : database_(std::move(db)) {}

    void performDataOperations()
    {
        if (database_->connect("Data Source=...;User=...;Password=..."))
        {
            database_->query("Select * FROM Users");
            database_->disconnect();
        }
        else
        {
            std::cerr << "Failed to connect to the database." << std::endl;
        }
    }

private:
    std::unique_ptr<IDatabase> database_;
};

int main()
{
    // Swap the logger by choosing a different concrete implementation.
    // For instance, to use a MySQL database:
    std::unique_ptr<IDatabase> db = std::make_unique<MySQLDatabase>();

    // Or to use a SQLite database instead, uncomment the following line:
    // std::unique_ptr<IDatabase> db = std::make_unique<SQLiteDatabase>();

    DataManager manager(std::move(db));
    manager.performDataOperations();

    return 0;
}