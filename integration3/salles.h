#ifndef SALLES_H
#define SALLES_H
#include <QString>
#include <QSqlQueryModel>
#include <QTableView>
class Salles
{
public:
    Salles();
    Salles(int,int,QString,QString,QString);
    int getIDSALLE();
    int getCAPSALLE();
    QString getHOSALLE();
    QString getHFSALLE();
    QString getLISTE_MATERIEL();
    void setIDSALLE(int);
    void setCAPSALLE(int);
    void setHOSALLE(QString);
    void setHFSALLE(QString);
    void setLISTE_MATERIEL(QString);
    bool ajouter();
    bool supprimer(int);
    bool modifier(int);
    bool PDF();
    QSqlQueryModel* afficher();
    QSqlQueryModel* rechercher(QString R);
    QSqlQueryModel* trierIDSALLE();
    QSqlQueryModel* trierCAPSALLE();
    QSqlQueryModel* trierHOSALLE();
private:
    QString LISTE_MATERIEL,HOSALLE,HFSALLE;
    int CAPSALLE,IDSALLE;





};

#endif // SALLES_H
