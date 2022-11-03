#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QIntValidator>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     ui->cin->setValidator(new QIntValidator(0,99999999,this));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ajouter_clicked()
{

    QString nom=ui->nom->text();
    QString prenom=ui->prenom->text();
    int cin=ui->cin->text().toInt();
    client c(nom,prenom,cin);
    bool test= c.ajouter();
    if (test){
        QMessageBox::information(nullptr, QObject::tr(" OK"),
                    QObject::tr("Ajout successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->table->setModel(c.afficher());


    }
    else
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                    QObject::tr("Ajout failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}





void MainWindow::on_suppri_clicked()
{ client c1;
    c1.setcin(ui->cin->text().toInt());
    bool test=c1.supprimer(c1.getcin());
    if (test){
        QMessageBox::information(nullptr, QObject::tr(" OK"),
                    QObject::tr("Delete successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->table->setModel(c.afficher());

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                    QObject::tr("Delete failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_modifier_clicked()
{
    client c3;
        QString nom=ui->nom->text();
        QString prenom=ui->prenom->text();
        int cin=ui->cin->text().toInt();
         bool test=c3.modifier(nom,prenom,cin);
         if (test){
             QMessageBox::information(nullptr, QObject::tr(" OK"),
                         QObject::tr("modifier successful.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
           ui->table->setModel(c.afficher());
         }
         else
         {QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                         QObject::tr("modifier failed.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);}
}
