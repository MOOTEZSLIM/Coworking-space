#include "reservation.h"
#include<QSqlQuery>
#include<QtDebug>
#include <QSqlQuery>
#include<QPdfWriter>
#include<QPainter>
#include<QTableView>
#include <QStringList>
#include <QSqlDatabase>
#include <QFile>
#include <QSqlRecord>


Reservation::Reservation()
{

}
Reservation::Reservation(int IDCLIENT_AR,QString NOM_CLIENTAR,int IDSALLE_AR,QString HEURE_AR)
{this->IDCLIENT_AR=IDCLIENT_AR; this->NOM_CLIENTAR=NOM_CLIENTAR; this->IDSALLE_AR=IDSALLE_AR; this->HEURE_AR=HEURE_AR; }
int Reservation::getIDCLIENT_AR(){return IDCLIENT_AR;}
QString Reservation::getNOM_CLIENTAR(){return NOM_CLIENTAR;}
int Reservation::getIDSALLE_AR(){return IDSALLE_AR;}
QString Reservation::getHEURE_AR(){return HEURE_AR;}
void Reservation::setIDCLIENT_AR(int IDCLIENT_AR ){this->IDCLIENT_AR=IDCLIENT_AR;}
void Reservation::setNOM_CLIENTAR(QString NOM_CLIENTAR ){this->NOM_CLIENTAR=NOM_CLIENTAR;}
void Reservation::setIDSALLE_AR(int IDSALLE_AR ){this->IDSALLE_AR=IDSALLE_AR;}
void Reservation::setHEURE_AR(QString HEURE_AR ){this->HEURE_AR=HEURE_AR;}

bool Reservation::ajouter()
{

    QSqlQuery query;
    QString IDCLIENT_AR_string= QString::number(IDCLIENT_AR);
    QString IDSALLE_AR_string= QString::number(IDSALLE_AR);

          query.prepare("INSERT INTO RESARD (IDCLIENT_AR, NOM_CLIENTAR , IDSALLE_AR, HEURE_AR) "
                        "VALUES (:IDCLIENT_AR, :NOM_CLIENTAR , :IDSALLE_AR, :HEURE_AR)");
          query.bindValue(":IDCLIENT_AR", IDCLIENT_AR_string);
          query.bindValue(":NOM_CLIENTAR", NOM_CLIENTAR);
          query.bindValue(":IDSALLE_AR", IDSALLE_AR_string);
          query.bindValue(":HEURE_AR", HEURE_AR);




    return query.exec();
}
QSqlQueryModel* Reservation::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM RESARD");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDCLIENT_AR"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_CLIENTAR"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("IDSALLE_AR"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr(" HEURE_AR "));
    return model;
}
bool Reservation::supprimer(int IDCLIENT_AR)
{


    QSqlQuery query;
    QString IDCLIENT_AR_string= QString::number(IDCLIENT_AR);

          query.prepare("DELETE FROM RESARD   WHERE IDCLIENT_AR=:IDCLIENT_AR");
          query.addBindValue(IDCLIENT_AR_string);


    return query.exec();
}



