#include "reclamation.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QMessageBox>

Reclamation::Reclamation()
{
CODER=0;CINR=0;CIN_E=0;ID_S=0;CIN_C=0;NOM_S=" ";TYPE_R=" ";ES=" ";FB=" ";RDA=" ";INCONV=" ";RDAS=" ";CAS=" ";
}

Reclamation:: Reclamation (int CODER,int CINR,int CIN_E,int ID_S,int CIN_C,QString NOM_S,QString TYPE_R,QString ES,QString RDA,QString INCONV ,QString RDAS,QString FB,QString CAS)
    {
        this->CODER=CODER;
        this->CINR=CINR;
        this->CIN_E=CIN_E;
        this->ID_S=ID_S;
        this->CIN_C=CIN_C;
        this->NOM_S=NOM_S;
        this->TYPE_R=TYPE_R;
        this->ES=ES;
        this->RDA=RDA;
        this->INCONV=INCONV;
        this->RDAS=RDAS;
        this->FB=FB;
        this->CAS=CAS;
     }

Reclamation:: Reclamation (int CODER,int CINR,QString TYPE_R,int CIN_C,QString ES,QString FB)
    {
        this->CODER=CODER;
        this->CINR=CINR;
        this->CIN_C=CIN_C;
        this->TYPE_R=TYPE_R;
        this->ES=ES;
        this->FB=FB;

     }


Reclamation:: Reclamation (int CODER,int CINR,QString TYPE_R,int ID_S,QString INCONV)
    {
    this->CODER=CODER;
    this->CINR=CINR;
    this->ID_S=ID_S;
    this->TYPE_R=TYPE_R;
    this->INCONV=INCONV;

    }



Reclamation:: Reclamation (int CODER,int CINR,QString TYPE_R,QString NOM_S  ,QString RDAS)
    {
    this->CODER=CODER;
    this->CINR=CINR;
    this->TYPE_R=TYPE_R;
    this->NOM_S=NOM_S;
    this->RDAS=RDAS;


    }

Reclamation:: Reclamation(int CODER,QString CAS,QString ES,QString FB )
    {
        this->CODER=CODER;
        this->CAS=CAS;
        this->ES=ES;
        this->FB=FB;
    }


  int Reclamation:: getCODER(){return CODER;}
  int Reclamation:: getCINR(){return CINR;}
  int Reclamation:: getCIN_E(){return CIN_E;}
  int Reclamation:: getID_S(){return ID_S;}
  int Reclamation:: getCIN_C(){return CIN_C;}
  QString Reclamation:: getNOM_S(){return NOM_S;}
  QString Reclamation:: getTYPE_R(){return TYPE_R;}
  QString Reclamation:: getES(){return ES;}
  QString Reclamation:: getRDA(){return RDA;}
  QString Reclamation:: getINCONV(){return INCONV;}
  QString Reclamation:: getRDAS(){return RDAS;}
  QString Reclamation:: getFB(){return FB;}
  QString Reclamation:: getCAS(){return CAS;}

  void Reclamation:: setCODER(int CODER){ this->CODER=CODER;;}
  void Reclamation:: setCINR(int CINR){this->CINR=CINR;}
  void Reclamation:: setCIN_E(int CIN_E){this->CIN_E=CIN_E;}
  void Reclamation:: setID_S(int ID_S){this->ID_S=ID_S;}
  void Reclamation:: setCIN_C(int CIN_C){this->CIN_C=CIN_C;}
  void Reclamation:: setNOM_S(QString NOM_S){this->NOM_S=NOM_S;}
  void Reclamation:: setTYPE_R(QString TYPE_R){this->TYPE_R=TYPE_R;}
  void Reclamation:: setES(QString ES){this->ES=ES;}
  void Reclamation:: setRDA(QString RDA){this->RDA=RDA;;}
  void Reclamation:: setINCONV(QString INCONV){this->INCONV=INCONV;}
  void Reclamation:: setRDAS(QString RDAS){this->RDAS=RDAS;}
  void Reclamation:: setFB(QString FB){this->FB=FB;}
  void Reclamation:: setCAS(QString CAS){this->CAS=CAS;}




  bool Reclamation:: ajouterc()
  {

      QSqlQuery query;
            QString CODERR=QString::number(CODER);
            QString CINRS=QString::number(CINR);
            QString CINCS=QString::number(CIN_C);

                query.prepare("INSERT INTO RECLAMATION  (CODER,CINR,TYPE_R,CIN_C,ES,FB,CAS)"
                               "VALUES (:CODER,:CINR, :TYPE_R, :CIN_C, :ES, :FB,:CAS )");
                query.bindValue(":CODER", CODER);
                query.bindValue(":CINR", CINR);
                query.bindValue(":TYPE_R", TYPE_R);
                query.bindValue(":CIN_C", CIN_C);
                query.bindValue(":ES", ES);
                query.bindValue(":FB", FB);
                query.bindValue(":CAS","opinion");



      return query.exec();

  }




  bool Reclamation:: ajouters()
  {

      QSqlQuery query;
            QString CINRS=QString::number(CINR);
            QString CINCS=QString::number(ID_S);
            QString CODERR=QString::number(CODER);

                query.prepare("INSERT INTO RECLAMATION  (CODER,CINR,TYPE_R,ID_S,INCONV,CAS)"
                               "VALUES (:CODER,:CINR, :TYPE_R, :ID_S, :INCONV,:CAS)");
                query.bindValue(":CODER", CODER);
                query.bindValue(":CINR", CINR);
                query.bindValue(":TYPE_R", TYPE_R);
                query.bindValue(":ID_S",ID_S);
                query.bindValue(":INCONV",INCONV);
                query.bindValue(":CAS","UNSOLVED");







      return query.exec();

  }



  bool Reclamation:: ajoutere()
  {

      QSqlQuery query;
            QString CODERR=QString::number(CODER);
            QString CINRS=QString::number(CINR);
            QString CEA=QString::number(CIN_E);

            query.prepare("INSERT INTO RECLAMATION  (CODER,CINR,TYPE_R,CIN_E,RDA,CAS)"
                           "VALUES (:CODER,:CINR, :TYPE_R, :CIN_E, :RDA,:CAS )");
                query.bindValue(":CODER", CODERR);
                query.bindValue(":CINR", CINRS);
                query.bindValue(":TYPE_R", TYPE_R);
                query.bindValue(":CIN_E", CEA);
                query.bindValue(":RDA",RDA);

                query.bindValue(":CAS","UNSOLVED");



      return query.exec();

  }









  bool Reclamation:: ajoutersp()
  {

      QSqlQuery query;
            QString CINRS=QString::number(CINR);


                query.prepare("INSERT INTO RECLAMATION  (CODER,CINR,TYPE_R,NOM_S,RDAS,CAS)"
                               "VALUES (:CODER,:CINR, :TYPE_R, :NOM_SP,:RDAS,:CAS)");
                query.bindValue(":CODER", CODER);
                query.bindValue(":CINR", CINR);
                query.bindValue(":TYPE_R", TYPE_R);
                query.bindValue(":NOM_SP",NOM_S);
                query.bindValue(":RDAS",RDAS);
                query.bindValue(":CAS","UNSOLVED");



      return query.exec();

  }





  QSqlQueryModel*Reclamation::afficher()
  {

      QSqlQueryModel*model=new QSqlQueryModel();

           model->setQuery("SELECT*FROM RECLAMATION ");


           model->setHeaderData(0, Qt::Horizontal,QObject::tr("CINR"));
           model->setHeaderData(1, Qt::Horizontal,QObject::tr("CIN_E"));
           model->setHeaderData(2, Qt::Horizontal,QObject::tr("ID_S"));
           model->setHeaderData(3, Qt::Horizontal,QObject::tr("NOM_S"));
           model->setHeaderData(4, Qt::Horizontal,QObject::tr("TYPE_R"));
           model->setHeaderData(5, Qt::Horizontal,QObject::tr("ES"));
           model->setHeaderData(6, Qt::Horizontal,QObject::tr("RDA"));
           model->setHeaderData(7, Qt::Horizontal,QObject::tr("INCONV"));
           model->setHeaderData(8, Qt::Horizontal,QObject::tr("RDAS"));
           model->setHeaderData(9, Qt::Horizontal,QObject::tr("CIN_C"));
           model->setHeaderData(10, Qt::Horizontal,QObject::tr("FB"));
           model->setHeaderData(11, Qt::Horizontal,QObject::tr("CAS"));
           model->setHeaderData(12, Qt::Horizontal,QObject::tr("CODER"));











    return model;
  }





  bool Reclamation ::supprimer(int CODER)
  {

      QSqlQuery query;
      QString CODERR=QString::number(CODER);
          query.prepare("DELETE FROM RECLAMATION WHERE CODER=:CODER");
          query.addBindValue(CODERR);



       return query.exec();


  }


    QSqlQueryModel*Reclamation::chercher(int CODER)

    {
        QString CODERR=QString::number(CODER);
        QMessageBox msgBox ;
        msgBox.setText(CODERR) ;
        msgBox.exec();
          QSqlQueryModel*model=new QSqlQueryModel();
          model->setQuery("SELECT*FROM RECLAMATION WHERE CODER='"+CODERR+"'");
          model->setHeaderData(0, Qt::Horizontal,QObject::tr("CINR"));
          model->setHeaderData(1, Qt::Horizontal,QObject::tr("CIN_E"));
          model->setHeaderData(2, Qt::Horizontal,QObject::tr("ID_S"));
          model->setHeaderData(3, Qt::Horizontal,QObject::tr("NOM_S"));
          model->setHeaderData(4, Qt::Horizontal,QObject::tr("TYPE_R"));
          model->setHeaderData(5, Qt::Horizontal,QObject::tr("ES"));
          model->setHeaderData(6, Qt::Horizontal,QObject::tr("RDA"));
          model->setHeaderData(7, Qt::Horizontal,QObject::tr("INCONV"));
          model->setHeaderData(8, Qt::Horizontal,QObject::tr("RDAS"));
          model->setHeaderData(9, Qt::Horizontal,QObject::tr("CIN_C"));
          model->setHeaderData(10, Qt::Horizontal,QObject::tr("FB"));
          model->setHeaderData(11, Qt::Horizontal,QObject::tr("CAS"));
          model->setHeaderData(12, Qt::Horizontal,QObject::tr("CODER"));

        return model;
    }





     bool Reclamation ::modify(int CODER,QString CAS,QString ES,QString FB )
     {
         QSqlQuery query;
         query.prepare("UPDATE RECLAMATION SET CAS=:CAS , ES=:ES ,FB=:FB WHERE CODER=:CODER");
         query.bindValue(":CAS",CAS);
         query.bindValue(":CODER",QString::number(CODER));
         query.bindValue(":ES", ES);
         query.bindValue(":FB", FB);
         return query.exec();


     }


     QSqlQueryModel*Reclamation::tri_solved()
     {

         QSqlQueryModel*model=new QSqlQueryModel();

              model->setQuery("SELECT*FROM RECLAMATION ORDER BY CAS ");

              model->setHeaderData(0, Qt::Horizontal,QObject::tr("CINR"));
              model->setHeaderData(1, Qt::Horizontal,QObject::tr("CIN_E"));
              model->setHeaderData(2, Qt::Horizontal,QObject::tr("ID_S"));
              model->setHeaderData(3, Qt::Horizontal,QObject::tr("NOM_S"));
              model->setHeaderData(4, Qt::Horizontal,QObject::tr("TYPE_R"));
              model->setHeaderData(5, Qt::Horizontal,QObject::tr("ES"));
              model->setHeaderData(6, Qt::Horizontal,QObject::tr("RDA"));
              model->setHeaderData(7, Qt::Horizontal,QObject::tr("INCONV"));
              model->setHeaderData(8, Qt::Horizontal,QObject::tr("RDAS"));
              model->setHeaderData(9, Qt::Horizontal,QObject::tr("CIN_C"));
              model->setHeaderData(10, Qt::Horizontal,QObject::tr("FB"));
              model->setHeaderData(11, Qt::Horizontal,QObject::tr("CAS"));
              model->setHeaderData(12, Qt::Horizontal,QObject::tr("CODER"));
       return model;
     }



     QSqlQueryModel*Reclamation::tri_type()
     {
         QSqlQueryModel*model=new QSqlQueryModel();

              model->setQuery("SELECT*FROM RECLAMATION ORDER BY TYPE_R ");
              model->setHeaderData(0, Qt::Horizontal,QObject::tr("CINR"));
              model->setHeaderData(1, Qt::Horizontal,QObject::tr("CIN_E"));
              model->setHeaderData(2, Qt::Horizontal,QObject::tr("ID_S"));
              model->setHeaderData(3, Qt::Horizontal,QObject::tr("NOM_S"));
              model->setHeaderData(4, Qt::Horizontal,QObject::tr("TYPE_R"));
              model->setHeaderData(5, Qt::Horizontal,QObject::tr("ES"));
              model->setHeaderData(6, Qt::Horizontal,QObject::tr("RDA"));
              model->setHeaderData(7, Qt::Horizontal,QObject::tr("INCONV"));
              model->setHeaderData(8, Qt::Horizontal,QObject::tr("RDAS"));
              model->setHeaderData(9, Qt::Horizontal,QObject::tr("CIN_C"));
              model->setHeaderData(10, Qt::Horizontal,QObject::tr("FB"));
              model->setHeaderData(11, Qt::Horizontal,QObject::tr("CAS"));
              model->setHeaderData(12, Qt::Horizontal,QObject::tr("CODER"));

        return model;
     }



























