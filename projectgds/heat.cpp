#include "heat.h"

heat::heat()
{
IDT=0;IDS=0;ETAT=" ";
}


heat::heat (int IDT,int IDS,QString ETAT)
    {
        this->IDT=IDT;
        this->IDS=IDS;
        this->ETAT=ETAT;


     }







int heat:: getIDT(){return IDT;}
int heat::getIDS(){return IDS;}
QString heat:: getETAT(){return ETAT;}




void heat:: setIDT(int IDT){ this->IDT=IDT;}
void heat:: setIDS(int IDS){ this->IDS=IDS;}
void heat:: setETAT(QString ETAT){this->ETAT=ETAT;}










QSqlQueryModel*heat::check()

{

      QSqlQueryModel*model=new QSqlQueryModel();
      model->setQuery("SELECT*FROM HEAT ");
      model->setHeaderData(12, Qt::Horizontal,QObject::tr("IDT"));
      model->setHeaderData(1, Qt::Horizontal,QObject::tr("IDS"));
      model->setHeaderData(2, Qt::Horizontal,QObject::tr("ETAT"));
      model->setHeaderData(2, Qt::Horizontal,QObject::tr("TEMP"));

    return model;
}


QSqlQueryModel*heat::check_overheat()

{

      QSqlQueryModel*model=new QSqlQueryModel();
      model->setQuery("SELECT*FROM HEAT WHERE ETAT='overheat'");
      model->setHeaderData(12, Qt::Horizontal,QObject::tr("IDT"));
      model->setHeaderData(1, Qt::Horizontal,QObject::tr("IDS"));
      model->setHeaderData(2, Qt::Horizontal,QObject::tr("ETAT"));
      model->setHeaderData(2, Qt::Horizontal,QObject::tr("TEMP"));



    return model;
}
