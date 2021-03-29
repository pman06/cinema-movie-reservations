#ifndef DATABASECONNECTION_H
#define DATABASECONNECTION_H

#include <QSqlDatabase>
#include <QDebug>

class DatabaseConnection
{
public:
    DatabaseConnection();

    QSqlDatabase mydb;

    void connClose()
    {
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connOpen()
    {
        mydb = QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("C:/SQLite/MovieReservation.db");
        if(!mydb.open())
        {   
            return false;
        }
        else
        {
            return true;
        }
    }
};

#endif // DATABASECONNECTION_H
