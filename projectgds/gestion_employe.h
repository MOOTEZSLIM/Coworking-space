#ifndef GESTION_EMPLOYE_H
#define GESTION_EMPLOYE_H



#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QString>


class gestion_employe
{

    QString id,nom,prenom,sexe,adresse,etatc;
    int  age,numero;

public:
    gestion_employe();
    gestion_employe(QString,QString,QString,QString,int,QString,QString,int);


    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
    bool modifier();
    QSqlQueryModel * rechercher(QString);
      QSqlQueryModel * Trier();
};


#endif // GESTION_EMPLOYE_H
