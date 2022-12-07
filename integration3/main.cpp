#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile stylesheetfile("C:\\Users\\msi\\Documents\\projectgds\\Toolery.qss");
        stylesheetfile.open(QFile::ReadOnly);
        QString styleSheet=QLatin1String(stylesheetfile.readAll());
        a.setStyleSheet(styleSheet);
    MainWindow w;
    w.show();
    Connection c;
    bool test=c.createconnect();
    if(test)
    {w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



    return a.exec();
}




