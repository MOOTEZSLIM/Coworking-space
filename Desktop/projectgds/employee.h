#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QString>


class Employee
{

    QString id,nom,prenom,sexe,adresse,etatc;
    int  age,numero;

public:
    Employee();
    Employee(QString,QString,QString,QString,int,QString,QString,int);


    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
    bool modifier();
    QSqlQueryModel * rechercher(QString);
      QSqlQueryModel * Trier();
};

#endif // EMPLOYEE_H
