#ifndef CLIENT_H
#define CLIENT_H
#include<QString>
#include <QSqlQueryModel>

class client
{
public:
    client();
    client (QString,QString,int);

    QString getnom();
    QString getprenom();
    int getcin();
    void setnom(QString);
    void setprenom(QString);
    void setcin(int);
    bool ajouter();
    QSqlQueryModel*afficher();
    bool supprimer(int);
    bool modifier (QString,QString,int);
private:
    QString nom,prenom;
    int cin;
};

#endif // CLIENT_H
