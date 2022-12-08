#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "connection.h"
#include "employee.h"
 #include"QTextDocument"
#include "QTextEdit"
#include "QMainWindow"
#include "QTextStream"
#include <QDesktopServices>
#include <QPainter>
#include <QPrinter>
#include <QPdfWriter>
#include <QFileDialog>
#include <QIntValidator>
#include "statistic.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView_9->setModel(e.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ajouterButton_4_clicked()
{
    //Récupération des données
    QString id=ui->lineEdit_id_5->text() ;
    QString nom=ui->lineEdit_nom_4->text();
    QString prenom=ui->lineEdit_prenom_4->text();
    QString sexe=ui->lineEdit_sexe_4->text();
    int age=ui->lineEdit_age_4->text().toInt();
    QString adresse=ui->lineEdit_adresse_4->text();
    QString etatc=ui->lineEdit_etat_4->text();
    int numero=ui->lineEdit_num_4->text().toInt();

    Employee e(id,nom,prenom,sexe,age,adresse,etatc,numero);

    bool test=e.ajouter();

    if (test)
    {
            QMessageBox::information(nullptr,QObject::tr("Cooworking Space"),
                                 QObject::tr("Ajout effectué\n"
                                             "Cliquez sur annuler pour quitter."),QMessageBox::Cancel);

    }
    else
    {

            QMessageBox::critical(nullptr,QObject::tr("Cooworking Space"),
                                  QObject::tr("Ajout non effectué\n"
                                              "Cliquez sur annuler pour quitter."),QMessageBox::Cancel);
    }



}




void MainWindow::on_supprimerButton_5_clicked()
{
    QString id=ui->supprimer_par_id_5->text();
    bool test=e.supprimer(id);

    if(test)
    {
            QMessageBox::information(nullptr,QObject::tr("Cooworking Space"),
                                  QObject::tr("Suppression effectuée\n"
                                              "Cliquez sur annuler pour quitter."),QMessageBox::Cancel);

    }
    else
    {
            QMessageBox::critical(nullptr,QObject::tr("Cooworking Space"),
                                  QObject::tr("Suppression non effectuée.\n"
                                              "Cliquez sur annuler pour quitter."),QMessageBox::Cancel);
        }

}





/*void MainWindow::on_modifierButton_4_clicked()
{
    int id=ui->lineEdit_id_5->text().toInt();
    QString nom=ui->lineEdit_nom_4->text();
    QString prenom=ui->lineEdit_prenom_4->text();
    QString sexe=ui->lineEdit_sexe_4->text();
     int age=ui->lineEdit_age_4->text().toInt();
    QString adresse=ui->lineEdit_adresse_4->text();
    QString etat=ui->lineEdit_etat_4->text();
    int numero=ui->lineEdit_num_4->text().toInt();
      Employee e(id,nom,prenom,sexe,age,adresse,etat,numero);
    bool test=e.modifier();
    QMessageBox msgBox;
    if (test)
      {  msgBox.setText("modifier avec succes");
   ui->tableView_9->setModel(e.afficher());

    }
    else
        msgBox.setText("echec de modifier ");
    msgBox.exec();
}


*/

void MainWindow::on_pushButton_clicked()
{
 ui->tableView_9->setModel(e.afficher());
}

void MainWindow::on_modifierButton_4_clicked()
{

        QString id=ui->lineEdit_id_6->text();
        QString nom=ui->lineEdit_nom_5->text();
        QString prenom=ui->lineEdit_prenom_5->text();
        QString sexe=ui->lineEdit_sexe_5->text();
         int age=ui->lineEdit_age_5->text().toInt();
        QString adresse=ui->lineEdit_adresse_5->text();
        QString etat=ui->lineEdit_etat_5->text();
        int numero=ui->lineEdit_num_5->text().toInt();

            Employee e(id,nom,prenom,sexe,age,adresse,etat,numero);

            bool test=e.modifier();


            if(test){
                ui->tableView_9->setModel(e.afficher());
                QMessageBox::information(nullptr, QObject::tr("Modification Effectué"),

                                    QObject::tr(" Modifié.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
             }


            else
            {
                QMessageBox::critical(nullptr, QObject::tr("non effectué"),
                            QObject::tr("non modifié !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
            }

    }


void MainWindow::on_pushButton_3_clicked()
{
    Employee e;
                      QString rech =ui->lineEdit_id_rech->text();
                      ui->tableView_9->setModel(e.rechercher(rech));
}

void MainWindow::on_pushButton_2_clicked()
{
    Employee e;
         ui->tableView_9->setModel(e.Trier());
}

void MainWindow::on_pushButton_4_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),"/home/Desktop",QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    QPdfWriter pdf(dir+"/Liste.pdf");
    QPainter painter(&pdf);
    int i = 4000;
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 30));
    painter.drawText(1200,1200,"Liste des employees");
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 50));
    painter.setFont(QFont("Arial", 9));
    painter.setPen(Qt::blue);
    painter.drawText(300,3300,"ID");
    painter.drawText(1300,3300,"Nom");
    painter.drawText(2300,3300,"Prenom");
    painter.drawText(3300,3300,"Sexe");
    painter.drawText(4300,3300,"Age");
    painter.drawText(5300,3300,"Adresse");
    painter.drawText(6300,3300,"Etat Civil");
    painter.drawText(7300,3300,"Numero");

            QSqlQuery query;
            query.prepare("SELECT * FROM EMPLOYEE");
            query.exec();
            while (query.next())
            {
                painter.drawText(300,i,query.value(0).toString());
                painter.drawText(1300,i,query.value(1).toString());
                painter.drawText(2300,i,query.value(2).toString());
                painter.drawText(3300,i,query.value(3).toString());
                painter.drawText(4300,i,query.value(4).toString());
                painter.drawText(5300,i,query.value(5).toString());
                painter.drawText(6300,i,query.value(6).toString());
                painter.drawText(7300,i,query.value(7).toString());
                i = i +500;
            }
                int reponse = QMessageBox::question(this, "Génerer PDF", "PDF Enregistré.\nVous voulez l'affichez ?", QMessageBox::Yes |  QMessageBox::No);
                if (reponse == QMessageBox::Yes)
                {
                    QDesktopServices::openUrl(QUrl::fromLocalFile(dir+"/Liste.pdf"));
                    painter.end();
                }
                else
                {
                    painter.end();
                }

    }

void MainWindow::on_pushButton_9_clicked()
{
    statistic = new Statistic(this);
    statistic->setWindowTitle("Statistiques");
    statistic->show();
}
