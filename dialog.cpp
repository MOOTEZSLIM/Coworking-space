#include "dialog.h"
#include "ui_dialog.h"
#include "sponsors.h"
#include <QMessageBox>
#include <QIntValidator>


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
//ui->le_datecr->setValidator(new QIntValidator(0, 99999999, this));
ui->tab_sponsors->setModel(S.afficher());
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pb_ajouter_clicked()
{
    QString datecre=ui->le_datecr->text();
    QString noms=ui->le_nomsoc->text();
    QString type_sponsor=ui->le_prdspon->text();
    QString periodes=ui->le_prdspon->text();
    Sponsors S (datecre,noms,type_sponsor,periodes);

    bool test=S.ajouter();
        if(test)
        {
            // ui->tableView_S->setModel(S.afficher());
            QMessageBox::information(nullptr, QObject::tr("database is open"),
                        QObject::tr("ajout effectué.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
    }
       else
            QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                        QObject::tr("ajout non effectué.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);



}


void Dialog::on_pb_supprimer_clicked()
{
    Sponsors S1; S1.setnoms(ui->le_noms_supp->text());
    bool test=S1.supprimer(S1.getnoms());
    if(test)
    {
        // ui->tableView_S->setModel(S.afficher());
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("suppression effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
   else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("suppression non effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialog::on_pb_modifier_clicked()
{
    QString noms=ui->le_noms_mod->text();
      QString datecre=ui->le_datecre_mod->text();
        QString type_sponsor=ui->le_typesponsor_mod->text();
        QString periodes=ui->le_periodes_mod->text();

       S=Sponsors(noms,datecre,type_sponsor,periodes);

        bool test=S.modifier(noms);
        if(test)
            {

                QMessageBox::information(nullptr,QObject::tr(" OK"),
                                         QObject::tr("Modification effectuée\n"
                                                     "Click Cancel to exit."),QMessageBox::Cancel);

    //ui->tab_empolye->setModel(E.afficher());
            }
            else
               QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                                         QObject::tr("Modification non effectué\n"
                                                     "Click Cancel to exit."),QMessageBox::Cancel);
            ui->le_noms_mod->clear();
            ui->le_datecre_mod->clear();
            ui->le_typesponsor_mod->clear();
            ui->le_periodes_mod->clear();

}
