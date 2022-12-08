#ifndef CLIENT_H
#define CLIENT_H
#include<QString>
#include <QSqlQueryModel>

class client
{
public:
    client();
    client (QString,QString,int,QString,int,int);

    QString getnom();
    QString getprenom();
    int getcin();
    QString gettypeab();
    int getnbrab();
    int getprix();

    void setnom(QString);
    void setprenom(QString);
    void setcin(int);
    void settypeab(QString);
    void setnbrab(int);
    void setprix(int);

    bool ajouter();
    QSqlQueryModel*afficher();
    bool supprimer(int);
    bool modifier (QString,QString,int,QString,int,int);
    QSqlQueryModel *trierParCin();
    QSqlQueryModel *trierParNom();
    QSqlQueryModel *trierParPre();
    QSqlQueryModel *trierParNbrab();
    bool RechercheParCIN(int CINrech);
    QSqlQueryModel *afficherparCIN(int CIN);
    QSqlQueryModel *tarif();

private:
    QString nom,prenom,typeab;
    int cin,nbrab,prix;
};

#endif // CLIENT_H
