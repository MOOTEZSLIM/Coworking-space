#include "salles.h"
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
QSqlQueryModel * Salles::rechercher(QString R)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString rech="select *  from SALLES where IDSALLE like '%"+R+"%' or CAPSALLE like '%"+R+"%' or HOSALLE like '%"+R+"%' or HFSALLE like '%"+R+"%' or LISTE_MATERIEL like '%"+R+"%'";

    model->setQuery(rech);
    return model;
}

QSqlQueryModel* Salles::trierIDSALLE()
{
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM SALLES ORDER BY IDSALLE ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDSALLE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("CAPSALLE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("HOSALLE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("HFSALLE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("LISTE_MATERIEL"));

    return model;
}
QSqlQueryModel* Salles::trierCAPSALLE()
{
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM SALLES ORDER BY CAPSALLE ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDSALLE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("CAPSALLE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("HOSALLE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("HFSALLE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("LISTE_MATERIEL"));



    return model;
}
QSqlQueryModel* Salles::trierHOSALLE()
{
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM SALLES ORDER BY HOSALLE ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDSALLE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("CAPSALLE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("HOSALLE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("HFSALLE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("LISTE_MATERIEL"));


    return model;
}
bool Salles::PDF()
{


    QPdfWriter PDFS("C:\\Users\\msi\\Documents\\PDF ET EXEL\\SALLE.pdf");
    QPainter painter(&PDFS);
    const QImage image("C:/Users/msi/Desktop/ex1/logo-color");
    const QPoint imageCoordinates(0,0);
                    int i = 4000;
                    int f=3700;
                    for (int l=0; l<3; ++l) {
                            painter.drawImage(imageCoordinates, image);
                    }
                            painter.setPen(Qt::darkYellow);
                            painter.setFont(QFont("Helvetica", 30, QFont::Bold));
                            painter.drawText(2750,1200,"LISTE DES SALLES");
                            painter.setPen(Qt::black);
                            painter.setFont(QFont("Helvetica", 15));
                            painter.setFont(QFont("Helvetica", 9));
                            painter.drawRect(1600,3000,6600,500);
                            painter.drawText(2200,3300,"IDSALLE");
                            painter.drawText(3300,3300,"CAPSALLE");
                            painter.drawText(4400,3300,"HOSALLE");
                            painter.drawText(5500,3300,"HFSALLE");
                            painter.drawText(6600,3300,"LISTE MATERIEL");


                                QSqlQuery query;

                            query.prepare("select * from SALLES");
                            query.exec();
                            while (query.next())
                              {
                             painter.drawText(2400,i,query.value(0).toString());
                             painter.drawText(3500,i,query.value(1).toString());
                             painter.drawText(4500,i,query.value(2).toString());
                             painter.drawText(5600,i,query.value(3).toString());
                             painter.drawText(6900,i,query.value(4).toString());
                              painter.drawRect(1600,f,6600,500);

                                   i = i + 500;
                                   f = f+500;
      }
 return query.exec();

}






