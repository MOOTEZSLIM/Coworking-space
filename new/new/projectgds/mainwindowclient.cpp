/*#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QIntValidator>*/


#include "mainwindowclient.h"
#include "ui_mainwindowclient.h"
#include "client.h"
#include <QDateEdit>
#include <QMessageBox>
#include<QIntValidator>
#include<QSqlQuery>
#include <QtPrintSupport/QPrinter>
#include <QPainter>
#include <QPdfWriter>
#include <QTextStream>
#include <QTextDocument>
#include <QDialog>
#include <QLabel>
#include <QSystemTrayIcon>
#include <QSqlQueryModel>
#include <QTextStream>
#include <QTimer>
//#include <QPrintDialog>
#include <QSystemTrayIcon>
#include <QLabel>
//#include <QPrinter>
#include <QPainter>
//#include <QPrintDialog>
#include <QSqlQueryModel>
#include <QDebug>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include "stati.h"
#include <QDesktopServices>
MainWindowclient::MainWindowclient(QWidget *parent)
   : QMainWindow(parent)
   , ui(new Ui::MainWindowclient)
{client c;
   //ui->setupUi(this);
   ui->table->setModel(c.afficher());
   ui->cin->setValidator(new QIntValidator(0,99999999,this));



    QValidator *validator = new QIntValidator(1, 999999, this);

        ui->nom->setValidator(validator);
        ui->prenom->setValidator(validator);
        ui->typeab->setValidator(validator);


        ui->nom->setMaxLength(10);
        ui->prenom->setMaxLength(10);
        ui->typeab->setMaxLength(7);

        ui->nom->setValidator(new QRegExpValidator(QRegExp("[A-Z][a-z]*")));
        ui->prenom->setValidator(new QRegExpValidator(QRegExp("[A-Z][a-z]*")));
        ui->typeab->setValidator(new QRegExpValidator(QRegExp("[A-Z][a-z]*")));

}

MainWindowclient::~MainWindowclient()
{
   delete ui;
}


void MainWindowclient::on_ajouter_clicked()
{

   QString nom=ui->nom->text();
   QString prenom=ui->prenom->text();
   int cin=ui->cin->text().toInt();
   QString typeab=ui->typeab->text();
   int nbrab=ui->nbrab->text().toInt();
   int prix=ui->prix->text().toInt();
   client c(nom,prenom,cin,typeab,nbrab,prix);
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





void MainWindowclient::on_suppri_clicked()
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

void MainWindowclient::on_modifier_clicked()
{
   client c3;
       QString nom=ui->nom->text();
       QString prenom=ui->prenom->text();
       int cin=ui->cin->text().toInt();
       QString typeab=ui->typeab->text();
       int nbrab=ui->nbrab->text().toInt();
       int prix=ui->prix->text().toInt();
       bool test=c3.modifier(nom,prenom,cin,typeab,nbrab,prix);
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



void MainWindowclient::on_radioButton_toggled(bool checked)
{

       if (checked == true){
                  ui->table->setModel(c.trierParCin());
              } else {
                   ui->table->setModel(c.afficher());
              }

}

void MainWindowclient::on_radioButton_2_toggled(bool checked)
{
   if (checked == true){
                 ui->table->setModel(c.trierParNom());
             } else {
                  ui->table->setModel(c.afficher());
             }
}

void MainWindowclient::on_radioButton_3_toggled(bool checked)
{
   if (checked == true){
                 ui->table->setModel(c.trierParPre());
             } else {
                  ui->table->setModel(c.afficher());
             }
}



void MainWindowclient::on_statistique_clicked()
{
   stati s;
   s.exec();
}

void MainWindowclient::on_pb_pdf_clicked()
{
   QPdfWriter pdf("C:/Users/assou/Desktop/pdf/CLIENTT.pdf");

          QPainter painter(&pdf);
          int i = 4000;
                 painter.setPen(Qt::red);
                 painter.setFont(QFont("Arial", 30));
                 painter.drawText(2000,1400,"LISTES DES CLIENTS ");

                 painter.setPen(Qt::black);
                 painter.setFont(QFont("Calibri", 15));
                 painter.drawRect(100,100,9400,2500);
                 painter.drawRect(100,3000,9400,500);


                 painter.setFont(QFont("Calibri", 10));
                 painter.drawText(500,3300,"NOM");
                 painter.drawText(2000,3300,"PRENOM");
                 painter.drawText(3000,3300,"CIN");
                 painter.drawText(4000,3300,"TYPEAB");
                 painter.drawText(6000,3300,"NBRAB");
                 painter.drawText(8500,3300,"PRIX");
                 painter.drawRect(100,3000,9400,9000);

                 QSqlQuery query;
                 query.prepare("select * from CLIENTT");
                 query.exec();
                 while (query.next())
                 {
                     painter.drawText(500,i,query.value(0).toString());
                     painter.drawText(2000,i,query.value(1).toString());
                     painter.drawText(3000,i,query.value(2).toString());
                     painter.drawText(4000,i,query.value(3).toString());
                     painter.drawText(6000,i,query.value(4).toString());
                     painter.drawText(8500,i,query.value(5).toString());

                    i = i + 350;
                 }
                 QMessageBox::information(this, QObject::tr("PDF Enregistré!"),
                 QObject::tr("PDF Enregistré!.\n" "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindowclient::on_pb_rechercher_clicked()
{

       int CIN = ui->le_rechercher->text().toInt();
          bool test=c.RechercheParCIN(CIN);
           if(test)
           {

               QMessageBox::information(nullptr, QObject::tr("CIN existe"),
                           QObject::tr("CIN existe.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
               ui->tab_rechercher->setModel( c.afficherparCIN(CIN));//refresh

               ui->le_rechercher->clear();

           }
           else
               QMessageBox::critical(nullptr, QObject::tr("CIN n'existe pas"),
                           QObject::tr("CIN n'existe pas !.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
               ui->le_rechercher->clear();
}


void MainWindowclient::on_table_clicked(const QModelIndex &index)
{
   selected=ui->table->model()->data(index).toInt();
   QString s = QString::number(selected);


   ui->cin->setText(s);

}

void MainWindowclient::on_tarif_clicked()
{     c.tarif();
   ui->table->setModel(c.afficher());
}

void MainWindowclient::on_radioButton_4_toggled(bool checked)
{
   if (checked == true){
                 ui->table->setModel(c.trierParNbrab());
             } else {
                  ui->table->setModel(c.afficher());
             }
}


void MainWindowclient::on_WHATS_clicked()
{
   QDesktopServices::openUrl(QUrl("https://wa.me/+21621967529", QUrl::TolerantMode));
}

