#ifndef RESERVATION_H
#define RESERVATION_H

#include <QString>
#include <QSqlQueryModel>
#include <QTableView>

class Reservation
{
public:
    Reservation();
    Reservation(int,QString,int,QString);
    int getIDCLIENT_AR();
    QString getNOM_CLIENTAR();
    int getIDSALLE_AR();
    QString getHEURE_AR();
    void setIDCLIENT_AR(int);
    void setNOM_CLIENTAR(QString);
    void setIDSALLE_AR(int);
    void setHEURE_AR(QString);
    bool ajouter();
     bool supprimer(int);
    QSqlQueryModel* afficher();


private:
    QString NOM_CLIENTAR,HEURE_AR ;
    int IDSALLE_AR,IDCLIENT_AR;


};

#endif // RESERVATION_H
