#include "client.h"
#include <QString>
#include <QSqlQuery>
#include<QSqlError>
#include <QDebug>
#include <QObject>

client::client()
{
 nom="";cin=0 ;prenom="";}

client::client(QString nom,QString prenom,int cin,QString typeab,int nbrab,int prix){
     this->nom=nom; this->cin=cin; this->prenom=prenom;this->typeab=typeab;this->nbrab=nbrab;this->prix=prix;}
QString client::getnom(){return nom;}
int client::getcin(){return cin;}
QString client::getprenom(){return prenom;}
QString client::gettypeab(){return typeab;}
int client::getnbrab(){return nbrab;}
int client::getprix(){return prix;}
//setter
void client::setcin(int cin){this->cin=cin;}
void client::setnom(QString nom){this->nom=nom;}
void client::setprenom(QString prenom){this->prenom;}
void client::settypeab(QString typeab){this->typeab;}
void client::setnbrab(int nbrab){this->nbrab;}
void client::setprix(int prix){this->prix;}
bool client::ajouter(){
bool test =true ;
    QSqlQuery query;
          query.prepare("INSERT INTO CLIENTT (NOM,PRENOM,CIN,TYPEAB,NBRAB,PRIX) "
                        "VALUES (:nom, :prenom, :cin, :typeab, :nbrab, :prix)");
          query.bindValue(":cin",cin);
          query.bindValue(":prenom",prenom);
          query.bindValue(":nom",nom);
          query.bindValue(":typeab",typeab);
          query.bindValue(":nbrab",nbrab);
          query.bindValue(":prix",prix);
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
           model->setHeaderData(3, Qt::Horizontal,QObject::tr("TYPEAB"));
           model->setHeaderData(4, Qt::Horizontal,QObject::tr("NBRAB"));
           model->setHeaderData(5, Qt::Horizontal,QObject::tr("PRIX"));



           return model;


}

bool client::supprimer(int cin){
    QSqlQuery query;
    query.prepare("Delete from CLIENTT where cin=:CIN");
    query.bindValue(":CIN",cin);
    return query.exec();
}





bool client::modifier(QString nom,QString prenom,int cin,QString typeab, int nbrab,int prix)
{
    QSqlQuery query;

    query.prepare("UPDATE CLIENTT SET nom=:NOM, prenom=:PRENOM, typeab=:TYPEAB,nbrab=:NBRAB, prix=:PRIX  WHERE cin=:CIN");

    query.bindValue(":NOM", nom);
    query.bindValue(":PRENOM", prenom);
    query.bindValue(":CIN", cin);
    query.bindValue(":TYPEAB", typeab);
    query.bindValue(":NBRAB", nbrab);
    query.bindValue(":PRIX",prix);
    return  query.exec();
    }




QSqlQueryModel* client::trierParCin()
{
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM CLIENTT ORDER BY CIN ASC");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("TYPEAB"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("NBRAB"));
    model->setHeaderData(5, Qt::Horizontal,QObject::tr("PRIX"));


    return model;
}
QSqlQueryModel* client::trierParNom()
{
    QSqlQueryModel *model= new QSqlQueryModel;
        QSqlQuery *q=new QSqlQuery();
        q->prepare("select * from CLIENTT order by NOM  asc");
        q->exec();
        model->setQuery(*q);
        return  model;
}
QSqlQueryModel* client::trierParPre()
{
    QSqlQueryModel *model= new QSqlQueryModel;
        QSqlQuery *q=new QSqlQuery();
        q->prepare("select * from CLIENTT order by PRENOM  asc");
        q->exec();
        model->setQuery(*q);
        return  model;
}

QSqlQueryModel* client::trierParNbrab()
{
    QSqlQueryModel *model= new QSqlQueryModel;
        QSqlQuery *q=new QSqlQuery();
        q->prepare("select * from CLIENTT order by NBRAB  asc");
        q->exec();
        model->setQuery(*q);
        return  model;
}

bool client::RechercheParCIN(int CINrech)
    {
        QSqlQuery query;
        //QSqlRecord CIN = query.record();
        QString str= QString::number(CINrech);

        query.prepare("SELECT * FROM CLIENTT WHERE cin=:CIN");
        query.bindValue(":CIN",str);
        query.exec();

        if (query.next())
        {
            return true;
             qDebug()<<"client existe";

        }
        else
        {
            qDebug()<<"client n'existe pas";
            return false;
        }
    }


    QSqlQueryModel *client::afficherparCIN(int CIN)
        {
        QSqlQueryModel * model= new QSqlQueryModel();

         QString ASMA= QString::number(CIN);

        QSqlQuery *q = new QSqlQuery;
         q->prepare("SELECT * from CLIENTT where CIN LIKE '%"+ASMA+"%'");
          q->addBindValue(ASMA);
           q->exec();
             model->setQuery(*q);


            return model;
        }
QSqlQueryModel *client ::tarif()
{QSqlQuery query;
     QSqlQueryModel *model= new QSqlQueryModel;
    client c;


        query.prepare("UPDATE CLIENTT SET prix:=PRIX where NBRAB>=2 ");
        int x = prix-10;
        query.bindValue(":PRIX", x);
        query.exec();
        model->setQuery(query);


        return  model;
}

