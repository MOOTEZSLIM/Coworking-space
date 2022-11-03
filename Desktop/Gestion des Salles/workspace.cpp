#include "workspace.h"
#include "ui_workspace.h"
#include <QMessageBox>
#include "salles.h"
#include <QMainWindow>
#include <QSqlQuery>




workspace::workspace(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::workspace)
{
    ui->setupUi(this);
    Salles Etmp;
    ui->tableView_S->setModel(Etmp.afficher());
    ui->lineEdit_cap_2->setValidator(new QIntValidator(1, 100, this));
    ui->lineEdit_cap->setValidator(new QIntValidator(1, 100, this));
    QRegularExpression rx("[1-9]\\d{0,3}",
                   QRegularExpression::CaseInsensitiveOption);
    ui->lineEdit_id->setValidator(new QRegularExpressionValidator(rx, this));

    QRegularExpression rx1("[1-9]\\d{0,3}",
                   QRegularExpression::CaseInsensitiveOption);
    ui->lineEdit_id_2->setValidator(new QRegularExpressionValidator(rx, this));
}


workspace::~workspace()
{
    delete ui;
}

void workspace::on_ajouter_clicked()
{
    int IDSALLE=ui->lineEdit_id->text().toInt();
    int CAPSALLE=ui->lineEdit_cap->text().toInt();
    QString HOSALLE=ui->timeEdit_ho->text();
    QString HFSALLE=ui->timeEdit_hf->text();
    QString LISTE_MATERIEL=ui->lineEdit_lm->toPlainText();
    Salles S(IDSALLE,CAPSALLE,HOSALLE,HFSALLE,LISTE_MATERIEL);
    bool test=S.ajouter();

      if(IDSALLE==0){
           QMessageBox::critical(nullptr, QObject::tr("PROBLEME AJOUT"),
                       QObject::tr("Ecriver ID.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
       }



      else if(test)
    {
         ui->tableView_S->setModel(S.afficher());
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("ajout effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->lineEdit_id->clear();
        ui->lineEdit_cap->clear();
        ui->timeEdit_ho->clear();
        ui->timeEdit_hf->clear();
        ui->lineEdit_lm->clear();

}
   else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("ajout non effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}


void workspace::on_supprimer_clicked()
{


        Salles p;
        bool test=false;
        p.setIDSALLE(ui->lineEdit_S->text().toInt());

        test=p.supprimer(p.getIDSALLE());
        if(p.getIDSALLE()==0){
            QMessageBox::critical(nullptr, QObject::tr("PROBLEME MODIFICIATION"),
                        QObject::tr("Ecriver ID.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
           else if(test)
            {
                ui->tableView_S->setModel(p.afficher());
                QMessageBox::information(nullptr, QObject::tr("database is open"),
                            QObject::tr("suppression effectué.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);


        }
           else
             ui->tableView_S->setModel(p.afficher());
                QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                            QObject::tr("suppression non effectué.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

}



void workspace::on_modifier_clicked()
{


        int IDSALLE=ui->lineEdit_id_2->text().toInt();
        int CAPSALLE= ui->lineEdit_cap_2->text().toInt();
        QString HOSALLE= ui->timeEdit_ho_2->text();
        QString HFSALLE= ui->timeEdit_hf_2->text();
        QString LISTE_MATERIEL=ui->lineEdit_lm_2->toPlainText();
        QSqlQuery query;

        Salles P(IDSALLE,CAPSALLE,HOSALLE,HFSALLE,LISTE_MATERIEL);
        P.setIDSALLE(ui->lineEdit_id_2->text().toInt());
        bool test=P.modifier(P.getIDSALLE());

        if(IDSALLE==0){
             QMessageBox::critical(nullptr, QObject::tr("PROBLEME MODIFICIATION"),
                         QObject::tr("Ecriver ID.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
         }


        else if(test)

            {
            ui->tableView_S->setModel(P.afficher());
            QMessageBox::information(nullptr, QObject::tr("Modefication Effectué"),

                                QObject::tr(" Modifié.\n"

                                            "Click Cancel to exit."), QMessageBox::Cancel);
             ui->lineEdit_id_2->clear();
             ui->lineEdit_cap_2->clear();
             ui->timeEdit_ho_2->clear();
             ui->timeEdit_hf_2->clear();
             ui->lineEdit_lm_2->clear();

        }




        else

            {

                QMessageBox::critical(nullptr, QObject::tr("non effectué"),

                            QObject::tr("non modifié !.\n"

                                        "Click Cancel to exit."), QMessageBox::Cancel);
                ui->lineEdit_id_2->clear();
                ui->lineEdit_cap_2->clear();
                ui->timeEdit_ho_2->clear();
                ui->timeEdit_hf_2->clear();
                ui->lineEdit_lm_2->clear();



   }

}

