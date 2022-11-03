#include "client.h"
#include <QString>
#include <QSqlQuery>
#include<QSqlError>
#include <QDebug>
#include <QObject>
client::client()
{
 nom="";cin=0 ;prenom="";}

client::client(QString nom,QString prenom,int cin){
     this->nom=nom; this->cin=cin; this->prenom=prenom;}
QString client::getnom(){return nom;}
int client::getcin(){return cin;}
QString client::getprenom(){return prenom;}
//setter
void client::setcin(int cin){this->cin=cin;}
void client::setnom(QString nom){this->nom=nom;}
void client::setprenom(QString prenom){this->prenom;}
bool client::ajouter(){
bool test =true ;
    QSqlQuery query;
          query.prepare("INSERT INTO CLIENTT (NOM,PRENOM,CIN) "
                        "VALUES (:nom, :prenom, :cin)");
          query.bindValue(":cin",cin);
          query.bindValue(":prenom",prenom);
          query.bindValue(":nom",nom);
          query.exec();
          qDebug() <<query.lastError();
    return  test;
};

QSqlQueryModel* client::afficher(){
    QSqlQueryModel* model=new QSqlQueryModel();


    model->setQuery("SELECT* FROM CLIENTT");
           model->setHeaderData(0, Qt::Horizontal,QObject::tr("NOM"));
           model->setHeaderData(1, Qt::Horizontal,QObject::tr("PRENOM"));
           model->setHeaderData(2, Qt::Horizontal,QObject::tr("CIN"));




           return model;


}

bool client::supprimer(int cin){
    QSqlQuery query;
    query.prepare("Delete from CLIENTT where cin=:CIN");
    query.bindValue(":CIN",cin);
    return query.exec();
}





bool client::modifier(QString nom,QString prenom,int cin)
{
    QSqlQuery query;

    query.prepare("UPDATE CLIENTT SET nom=:NOM, prenom=:PRENOM  WHERE cin=:CIN");

    query.bindValue(":NOM", nom);
    query.bindValue(":PRENOM", prenom);
    query.bindValue(":CIN", cin);

    return  query.exec();
    }
