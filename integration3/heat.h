#ifndef HEAT_H
#define HEAT_H



#include <QString>
#include <QSqlQueryModel>
#include <QWidget>

class heat
{
public:
    heat();
    heat(int,int,QString);



    int getIDT();
    int getIDS();
    QString getETAT();



    void setIDT(int);
    void setIDS(int);
    void setETAT(QString);




    QSqlQueryModel* check();
    QSqlQueryModel* check_overheat();



 private:
    int IDT,IDS;
    QString ETAT;


};

#endif // HEAT_H

