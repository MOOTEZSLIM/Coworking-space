#ifndef RECLAMATION_H
#define RECLAMATION_H




#include <QString>
#include <QSqlQueryModel>
#include <QWidget>

class Reclamation
{
public:
    Reclamation();
    Reclamation(int,QString,QString,QString);
    Reclamation(int,int,QString,int,QString);
    Reclamation(int,int,QString,int,QString,QString);
    Reclamation(int,int,QString,QString,QString);
    Reclamation (int,int,int,int,int,QString,QString,QString,QString,QString,QString,QString,QString);

        int getCODER();
        int getCINR();
        int getCIN_E();
        int getID_S();
        int getCIN_C();
        QString getNOM_S();
        QString getTYPE_R();
        QString getES();
        QString getRDA();
        QString getINCONV();
        QString getRDAS();
        QString getFB();
        QString getCAS();





        void setCINR(int);
        void setCIN_E(int);
        void setID_S(int);
        void setCIN_C(int);
        void setNOM_S(QString);
        void setTYPE_R(QString);
        void setES(QString);
        void setRDA(QString);
        void setINCONV(QString);
        void setRDAS(QString);
        void setFB(QString);
        void setCAS(QString);
        void setCODER(int);



        bool ajouterc();
        bool ajouters();
        bool ajoutere();
        bool ajoutersp();
        bool supprimer(int);
        bool modify(int,QString,QString,QString);




        QSqlQueryModel* afficher();
        QSqlQueryModel* chercher(int);
        QSqlQueryModel* tri_solved();
        QSqlQueryModel* tri_type();


private:
    int CINR, CIN_E,ID_S, CIN_C,CODER;
    QString NOM_S,TYPE_R,ES,RDA,INCONV,RDAS,FB,CAS;
};















#endif // RECLAMATION_H
