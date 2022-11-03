#include "salles.h"
#include<QSqlQuery>
#include<QtDebug>
#include <QSqlQuery>
Salles::Salles()
{

}
Salles::Salles(int IDSALLE,int CAPSALLE ,QString HOSALLE,QString HFSALLE,QString LISTE_MATERIEL)
{this->IDSALLE=IDSALLE; this->CAPSALLE=CAPSALLE; this->HOSALLE=HOSALLE; this->HFSALLE=HFSALLE; this->LISTE_MATERIEL=LISTE_MATERIEL;}
int Salles::getIDSALLE(){return IDSALLE;}
int Salles::getCAPSALLE(){return CAPSALLE;}
QString Salles::getHOSALLE(){return HOSALLE;}
QString Salles::getHFSALLE(){return HFSALLE;}
QString Salles::getLISTE_MATERIEL(){return LISTE_MATERIEL;}
void Salles::setIDSALLE(int IDSALLE){this->IDSALLE=IDSALLE;}
void Salles::setCAPSALLE(int CAPSALLE){this->CAPSALLE=CAPSALLE;}
void Salles::setHOSALLE(QString HOSALLE){this->HOSALLE=HOSALLE;}
void Salles::setHFSALLE(QString HFSALLE){this->HFSALLE=HFSALLE;}
void Salles::setLISTE_MATERIEL(QString LISTE_MATERIEL){this->LISTE_MATERIEL=LISTE_MATERIEL;}
bool Salles::ajouter()
{

    QSqlQuery query;
    QString IDSALLE_string= QString::number(IDSALLE);
    QString CAPSALLE_string= QString::number(CAPSALLE);

          query.prepare("INSERT INTO SALLES (IDSALLE, CAPSALLE , HOSALLE, HFSALLE, LISTE_MATERIEL) "
                        "VALUES (:IDSALLE,  :CAPSALLE, :HOSALLE , :HFSALLE ,:LISTE_MATERIEL)");
          query.bindValue(":IDSALLE", IDSALLE_string);
          query.bindValue(":CAPSALLE", CAPSALLE_string);
          query.bindValue(":HOSALLE", HOSALLE);
          query.bindValue(":HFSALLE", HFSALLE);
          query.bindValue(":LISTE_MATERIEL",LISTE_MATERIEL);



    return query.exec();
}
bool Salles::supprimer(int IDSALLE)
{


    QSqlQuery query;
    QString IDSALLE_string= QString::number(IDSALLE);

          query.prepare("DELETE FROM SALLES    WHERE IDSALLE=:IDSALLE");
          query.addBindValue( IDSALLE_string);


    return query.exec();
}
QSqlQueryModel* Salles::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM SALLES");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDSALLE"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("CAPSALLE"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("HOSALLE"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("HFSALLE"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("LISTE_MATERIEL"));
    return model;
}
bool Salles::modifier(int IDSALLE)
{
    QSqlQuery query;
    QString IDSALLE_string= QString::number(IDSALLE);
    QString CAPSALLE_string= QString::number(CAPSALLE);


    query.prepare("UPDATE SALLES SET IDSALLE=:IDSALLE, CAPSALLE=:CAPSALLE, HOSALLE=:HOSALLE ,HFSALLE=:HFSALLE, LISTE_MATERIEL=:LISTE_MATERIEL "
                  " WHERE IDSALLE=:IDSALLE");

    query.bindValue(":IDSALLE", IDSALLE_string);
    query.bindValue(":CAPSALLE", CAPSALLE_string);
    query.bindValue(":HOSALLE", HOSALLE);
    query.bindValue(":HFSALLE", HFSALLE);
    query.bindValue(":LISTE_MATERIEL",LISTE_MATERIEL);
    return    query.exec();
}

