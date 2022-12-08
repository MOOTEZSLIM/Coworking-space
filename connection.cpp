#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{
    bool test=false;
    QSqlDatabase db= QSqlDatabase::addDatabase("QODBC");
   // db.setDatabaseName("test-bd");
 //   db.setUserName("System");//inserer nom de l'utilisateur
   // db.setPassword("AAbb4444.");//inserer mot de passe de cet utilisateur
    db.setDatabaseName("test");
    db.setUserName("alaa");//inserer nom de l'utilisateur
    db.setPassword("1001");//inserer mot de passe de cet utilisateur
    if (db.open())
    {
        test=true;
    }

    return  test;
}

void Connection::closeConnection()
{
    db.close();
}
