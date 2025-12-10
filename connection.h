#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>
#include <QDebug>
#include <QSqlError>
#include <QMessageBox>
#include <QString>
#include <QSqlQuery>

class Connection
{
public:
    static Connection& getInstance();
    bool createConnection();
    QSqlDatabase getDatabase() { return db; }
    bool migrateSQLiteToOracle();
    bool testConnection(const QString &username, const QString &password);

private:
    QSqlDatabase db;

    // Private helper methods
    void checkODBCDrivers();
    bool setupSQLite();

    // Singleton pattern - prevent copying
    Connection();
    ~Connection();
    Connection(const Connection&) = delete;
    Connection& operator=(const Connection&) = delete;
};

#endif // CONNECTION_H
