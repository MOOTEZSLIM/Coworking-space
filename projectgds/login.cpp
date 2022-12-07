
#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include <QSqlQuery>
#include <qmessagebox.h>

login::login(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::login)
{
    ui->setupUi(this);
    int ret=A.connect_arduino(); // lancer la connexion à arduino
            switch(ret){
            case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
                break;
            case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
               break;
            case(-1):qDebug() << "arduino is not available";
            }
             QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
             //le slot update_label suite à la reception du signal readyRead (reception des données).

}
void login::update_label()
{data="";
while(A.getdata().size()<5)
{
     data=A.read_from_arduino();
     break;
}


  if(data!="")
  {qDebug()<<"id :"+data;
      if(A.chercherid(data)!=-1)
      {
QMessageBox::information(this,"search","existe");
          qDebug()<<"valdie";
          A.write_to_arduino("1");
          MainWindow *w = new MainWindow();
          w->setWindowTitle("Cooworking Space");
          w->show();
      }
      else
      { A.write_to_arduino("0"); qDebug()<<"invaldie"; ;
      QMessageBox::information(this,"search","n'existe pas");}


  }
}
login::~login()
{
  delete ui;
}

void login::on_pushButton_5_clicked()
{
    int count=0;
    QString Username,Password;

    Username=ui->lineEdit_username->text();
    Password=ui->lineEdit_password->text();
    ui->label_status->setText("correct");
    ui->label_status->setText("correct");
    MainWindow *w = new MainWindow();
    w->setWindowTitle("Cooworking Space");
    w->show();
   /*
  QSqlQuery  qry;
  qry.prepare("select * from USERS where USERNAME='"+Username+ "' and PASSWORD='"+Password+"'");
  if (qry.exec())
  {
    while(qry.next()){count++;}
    if (count==1)
    {
        ui->label_status->setText("correct");
        MainWindow *w = new MainWindow();
        w->setWindowTitle("Cooworking Space");
        w->show();
    }
    if (count<1)
        ui->label_status->setText("incorrect password or username!");

 }*/
}
