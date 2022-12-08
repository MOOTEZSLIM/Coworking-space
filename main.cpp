#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QLabel>
#include "connection.h"
#include "login.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Connection c;
    QSqlQuery query;
    login l;
    l.setWindowTitle("Login");

    bool test=c.createconnect();
    if(test)
    {
        l.show();
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Cooworking Space"), QObject::tr("Connection failed.\n"
                                                                                    "Click Cancel to exit."), QMessageBox::Cancel);


    return a.exec();
}
