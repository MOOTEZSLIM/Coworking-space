#include "gestion_employe.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QtDebug>
#include <QObject>
#include <QMessageBox>
#include "employe.h"
gestion_employe::gestion_employe()
{

}

gestion_employe::gestion_employe(QString id,QString nom,QString prenom,QString sexe,int age,QString adresse,QString etatc,int num)
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->sexe=sexe;
    this->age=age;
    this->adresse=adresse;
    this->etatc=etatc;
    this->numero=num;
}

bool gestion_employe::ajouter()
{
    QSqlQuery query;
    QString id_string =  id;
    QString age_string = QString::number(age);
    QString num_string = QString::number(numero);

    query.prepare("insert into EMPLOYEE(ID,NOM,PRENOM,SEXE,AGE,ADRESSE,ETAT_CIVIL,NUMERO)"
                  "values (:id,:nom,:prenom,:sexe,:age,:adresse,:etatc,:numero)");

    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":sexe",sexe);
    query.bindValue(":age",age);
    query.bindValue(":adresse",adresse);
    query.bindValue(":etatc",etatc);
    query.bindValue(":numero",numero);

    return query.exec();

}

bool gestion_employe::supprimer(QString id)
{
    QSqlQuery query;
        query.prepare(" Delete from EMPLOYEE where id=:id ");
        query.bindValue(":id", id);
   return query.exec();
}

QSqlQueryModel * gestion_employe :: afficher()
{
    QSqlQueryModel *model=new QSqlQueryModel();

         model->setQuery("SELECT * FROM EMPLOYEE");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("sexe"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("age"));
         model->setHeaderData(5, Qt::Horizontal, QObject::tr("adresse"));
         model->setHeaderData(6, Qt::Horizontal, QObject::tr("etatc"));
         model->setHeaderData(7, Qt::Horizontal, QObject::tr("numero"));
    return model;
}


bool gestion_employe::modifier( )
{


     QSqlQuery query;
     QString id_string = id;
     QString age_string = QString::number(age);
     QString num_string = QString::number(numero);

         query.prepare("UPDATE EMPLOYEE SET ID=:id, NOM=:nom, PRENOM=:prenom, SEXE=:sexe,AGE=:age, ADRESSE=:adresse,ETAT_CIVIL=:etatc, NUMERO=:numero where ID=:id");
         query.bindValue(":id", id_string);
         query.bindValue(":nom", nom);
         query.bindValue(":prenom", prenom);
         query.bindValue(":age",age_string);
         query.bindValue(":sexe", sexe);
         query.bindValue(":adresse",adresse);
         query.bindValue(":etatc",etatc);
         query.bindValue(":numero",num_string);

    return query.exec();
}


QSqlQueryModel * gestion_employe::rechercher(QString rech)
 {


       QSqlQuery query;
      QSqlQueryModel*model1=new QSqlQueryModel();


       query.prepare("SELECT * FROM EMPLOYEE WHERE  ID   LIKE'%"+rech+"%'");

       query.exec();
       model1->setQuery(query);
       return model1;

 }


QSqlQueryModel *gestion_employe::Trier()
  {
      QSqlQueryModel * model= new QSqlQueryModel();
              model->setQuery("SELECT * FROM EMPLOYEE ORDER BY ID");
              return model;

  }




