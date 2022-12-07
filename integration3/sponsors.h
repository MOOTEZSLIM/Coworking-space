#ifndef SPONSORS_H
#define SPONSORS_H

#include <QString>
#include <QSqlQueryModel>
#include <QtDebug>

class Sponsors
{
public:
    Sponsors();
    Sponsors(QString,QString,QString,QString);
    QString getdatecre();
    QString getnoms();
    QString gettype_sponsor();
    QString getperiodes();
    void setdatecre(QString);
    void setnoms(QString);
    void settype_sponsor(QString);
    void setperiodes(QString);
    bool ajouter();
     QSqlQueryModel* afficher();
    bool supprimer(QString);
    bool modifier(QString noms);
    QSqlQueryModel* recherche(QString noms);
    QSqlQueryModel* trier();


    QSqlQueryModel* trierperiodes();
    void genererPDF();

private:

    QString noms,datecre,type_sponsor,periodes;
};

#endif // SPONSORS_H
