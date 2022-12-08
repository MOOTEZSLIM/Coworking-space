#include "sponsors.h"
#include<QSqlQuery>
#include<QDebug>
#include<QSqlQueryModel>
#include<QObject>
#include <QtDebug>
#include <iostream>
#include "connection.h"
#include <QPdfWriter>
#include <qpdfwriter.h>
#include <QPainter>

Sponsors::Sponsors()
{
datecre=" "; noms=" "; type_sponsor=" ";periodes=" ";
}
Sponsors::Sponsors(QString datecre,QString noms,QString type_sponsor,QString periodes)
{this->datecre=datecre; this->noms=noms; this->type_sponsor=type_sponsor; this->periodes=periodes;}
QString Sponsors::getdatecre() {return datecre;}
QString Sponsors::getnoms() {return noms ;}
QString Sponsors::gettype_sponsor() {return type_sponsor ;}
QString Sponsors::getperiodes() {return periodes ;}
void Sponsors::setdatecre(QString datecre){this->datecre=datecre;}
void Sponsors::setnoms(QString noms){this->noms=noms;}
void Sponsors::settype_sponsor(QString type_sponsor){this->type_sponsor=type_sponsor;}
void Sponsors::setperiodes(QString periodes){this->periodes=periodes;}
bool Sponsors::ajouter()
{

    QSqlQuery query;
    query.prepare("INSERT INTO SPONSORS (NOMS,DATECRE,TYPE_SPONSOR,PERIODES) "
                        "VALUES (:noms, :datecre, :type_sponsor ,:periodes)");

          query.bindValue(0, noms);
          query.bindValue(1, datecre);
          query.bindValue(2, type_sponsor);
          query.bindValue(3, periodes);
     return  query.exec();


}
bool Sponsors::supprimer(QString noms)
{
    QSqlQuery query;
    query.prepare("Delete from SPONSORS where noms=:noms");

          query.bindValue(0, noms);

     return  query.exec();



}
QSqlQueryModel* Sponsors::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();



model->setQuery("SELECT* FROM SPONSORS");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom de société"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date de création"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type de sponsoring"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Période de sponsoring"));




    return model;

}


bool Sponsors::modifier(QString noms)
 {


   QSqlQuery query;


    query.prepare("update  SPONSORS set noms=:noms,  datecre=:datecre, type_sponsor=:type_sponsor,periodes=:periodes where noms=:noms " );
    query.bindValue(":noms",noms);
    query.bindValue(":datecre", datecre);
    query.bindValue(":type_sponsor", type_sponsor);
     query.bindValue(":periodes", periodes);



   return  query.exec();

}

QSqlQueryModel* Sponsors::recherche(QString noms)
{
    QSqlQueryModel* model=new QSqlQueryModel();
    QString query = "SELECT * FROM SPONSORS ";
    if((noms != "") ){
        query = query + "WHERE noms LIKE '%" + noms +"%' ";

    }

    model->setQuery(query);

    model->setHeaderData(1,Qt::Horizontal, QObject::tr("noms"));



    return model;
}

QSqlQueryModel* Sponsors::trier()
{
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM SPONSORS ORDER BY noms ASC");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("noms"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("datecre"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("type_sponsor"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("periodes"));




    return model;
}





QSqlQueryModel* Sponsors::trierperiodes()
{
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM SPONSORS ORDER BY periodes ASC");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("noms"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("datecre"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("type_sponsor"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("periodes"));




    return model;
}

