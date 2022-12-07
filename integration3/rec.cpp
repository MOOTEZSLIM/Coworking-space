#include "rec.h"
#include "ui_rec.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QImage>
#include<QTextStream>
#include<QTextDocument>
#include<QPrintDialog>
#include <QPrinter>
#include <QPainter>
#include <QDialog>
#include<QPdfWriter>
#include <QtCharts/QChartView>
#include <QMainWindow>
rec::rec(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rec)
{
    ui->setupUi(this);
    ui->cinr->setValidator(new QIntValidator(0,99999999,this));
    ui->code_r->setValidator(new QIntValidator(0,99999999,this));
    ui->cin_de_client->setValidator(new QIntValidator(0,99999999,this));
    ui->cin_emp_ab->setValidator(new QIntValidator(0,99999999,this));
    ui->tablerec->setModel(X.afficher());
    ui->tableView_c->setModel(Y.check());
    ui->modiftable->setModel(X.afficher());

}


rec::~rec()
{
    delete ui;
}

void rec::on_pb_ajouter_avie_clicked()
{
    int CIN=ui->cinr->text().toInt();
     int CODER=ui->code_r->text().toInt();
     QString TYPE=ui->type_de_reclamation->text();
     int CINC=ui->cin_de_client->text().toInt();
     QString SATIS=ui->sat_de_client->text();
     QString FB=ui->feed_back->text();
     Reclamation R(CODER,CIN,TYPE,CINC,SATIS,FB);

     if((FB.isEmpty())||(SATIS.isEmpty())||(TYPE.isEmpty()))
     {
         QMessageBox msgBox ;
         msgBox.setText("empty") ;
    msgBox.exec();
     }

     else if ((ui->cinr->text().isEmpty())|| (ui->code_r->text().isEmpty())||(ui->cin_de_client->text().isEmpty()))

     {
         QMessageBox msgBox ;
         msgBox.setText("cin empty") ;
    msgBox.exec();
     }


     else if (R.ajouterc())
     {
         R.afficher();
       QMessageBox msgBox ;
       msgBox.setText("AJOUTER C DONE") ;
       msgBox.exec();
       ui->tablerec->setModel(X.afficher());
       ui->cinr->clear();
       ui->code_r->clear();
       ui->type_de_reclamation->clear();
       ui->cin_de_client->clear();
       ui->sat_de_client->clear();
       ui->feed_back->clear();
  } else
     {
         QMessageBox msgBox;
         msgBox.setText("AJOUTER C FAILED") ;
         msgBox.exec();

     }

}

void rec::on_pb_ajouter_salle_clicked()
{
    int CIN=ui->cinr->text().toInt();
      int CODER=ui->code_r->text().toInt();
      QString TYPE=ui->type_de_reclamation->text();
      int IDS=ui->id_salle->text().toInt();
      QString INCONV=ui->inconv->text();
      Reclamation R(CODER,CIN,TYPE,IDS,INCONV);


      if((INCONV.isEmpty())||(TYPE.isEmpty()))
      {
          QMessageBox msgBox ;
          msgBox.setText("empty") ;
     msgBox.exec();
      }

      else if ((ui->cinr->text().isEmpty())|| (ui->code_r->text().isEmpty())||(ui->id_salle->text().isEmpty()))

      {
          QMessageBox msgBox ;
          msgBox.setText("cin empty") ;
          msgBox.exec();
      }




     else if (R.ajouters())
      {

        QMessageBox msgBox ;
        msgBox.setText("AJOUTER S DONE") ;
        msgBox.exec();
       ui->tablerec->setModel(X.afficher());
       ui->cinr->clear();
       ui->code_r->clear();
       ui->type_de_reclamation->clear();
       ui->id_salle->clear();
       ui->inconv->clear();

   } else
      {
          QMessageBox msgBox;
          msgBox.setText("AJOUTER s FAILED") ;
          msgBox.exec();

      }
}

void rec::on_pb_ajouter_employee_clicked()
{
    int CIN=ui->cinr->text().toInt();
       int CODER=ui->code_r->text().toInt();
       QString TYPE=ui->type_de_reclamation->text();
       int CEA=ui->cin_emp_ab->text().toInt();
       QString RDA=ui->justi->text();
       Reclamation R(CODER,CIN,TYPE,CEA,RDA);

       if((RDA.isEmpty())||(TYPE.isEmpty()))
       {
           QMessageBox msgBox ;
           msgBox.setText("empty") ;
           msgBox.exec();
       }

       else if ((ui->cinr->text().isEmpty())|| (ui->code_r->text().isEmpty())||(ui->cin_emp_ab->text().isEmpty()))

       {
           QMessageBox msgBox ;
           msgBox.setText("cin empty") ;
           msgBox.exec();

       }


       else if (R.ajoutere())
       {
         QMessageBox msgBox ;
         msgBox.setText("AJOUTER E DONE") ;
         msgBox.exec();
         ui->tablerec->setModel(X.afficher());
         ui->cinr->clear();
                ui->code_r->clear();
                ui->type_de_reclamation->clear();
                ui->cin_emp_ab->clear();
                ui->justi->clear();

    } else
       {
           QMessageBox msgBox;
           msgBox.setText("AJOUTER E FAILED") ;
           msgBox.exec();

       }
}

void rec::on_pb_ajouter_spons_clicked()
{
    int CIN=ui->cinr->text().toInt();
    int CODER=ui->code_r->text().toInt();
    QString TYPE=ui->type_de_reclamation->text();
    QString NOMSP=ui->nom_sp->text();
    QString RAIS=ui->rais_sp->text();
    Reclamation R(CODER,CIN,TYPE,NOMSP,RAIS);

    if((NOMSP.isEmpty())||(RAIS.isEmpty())||(TYPE.isEmpty()))
    {
        QMessageBox msgBox ;
        msgBox.setText("empty") ;
        msgBox.exec();
    }

    else if ((ui->cinr->text().isEmpty())|| (ui->code_r->text().isEmpty()))

    {
        QMessageBox msgBox ;
        msgBox.setText("cin empty") ;
        msgBox.exec();
    }


    else if (R.ajoutersp())
    {
      QMessageBox msgBox ;
      msgBox.setText("AJOUTER SP DONE") ;
      msgBox.exec();
      ui->tablerec->setModel(X.afficher());
      ui->code_r->clear();
      ui->cinr->clear();
      ui->type_de_reclamation->clear();
      ui->nom_sp->clear();
      ui->rais_sp->clear();
  }

    else
    {
        QMessageBox msgBox;
        msgBox.setText("AJOUTER SP FAILED") ;
        msgBox.exec();

    }
}



void rec::on_pb_chercher_clicked()
{
    int CODER=ui->chercher_r->text().toInt();

    ui->affchercher->setModel(X.chercher(CODER));
    ui->chercher_r->clear();
}


void rec::on_solved_toggled(bool checked)
{

    Reclamation R;
    if(checked==true)
    {
        ui->tablerec->setModel(R.tri_solved());}

    else {
        ui->tablerec->setModel(R.afficher());
        }
}

void rec::on_type_toggled(bool checked)
{
    Reclamation R;
    if(checked==true)
    {
        ui->tablerec->setModel(R.tri_type());}

    else {
        ui->tablerec->setModel(R.afficher());

        }
}

void rec::on_PDF_clicked()
{









            QString strStream;
            QTextStream out(&strStream);
            QImage pic ("logo_ESPRIT_Ariana");
            QImage pic2 ("Logo");
            QPainter painter;


            const int rowCount = ui->tablerec->model()->rowCount();
            const int columnCount = ui->tablerec->model()->columnCount();

            out <<  "<html>\n"
                   "<head>\n"

                   "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                   <<  QString("<title>%60 les postes</title>\n").arg("poste")
                  <<  "</head>\n"
                   "<body bgcolor=#ffffff link=#5000A0>\n"
                     "<h2>HTML Image</h2>"
                      "<img src=':/pic/logo_ESPRIT_Ariana.jpg' width='250'height='167'>"
                      "<img src=':/pic/logo.png' width='250'height='166'>"

                   "<table border=1 cellspacing=0 cellpadding=2>\n";
                   out << "<thead><tr bgcolor=#f0f0f0>";

                   for (int column = 0; column < columnCount; column++)
                   if (! ui->tablerec->isColumnHidden(column))
                   out << QString("<th>%1</th>").arg(ui->tablerec->model()->headerData(column, Qt::Horizontal).toString());
                   out << "</tr></thead>\n";

                   for (int row = 0; row < rowCount; row++) {
                        out << "<tr>";
                        for (int column = 0; column < columnCount; column++) {
                          if (!ui->tablerec->isColumnHidden(column)) {
                           QString data = ui->tablerec->model()->data(ui->tablerec->model()->index(row, column)).toString().simplified();
                           out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                              }
                           }
                         out << "</tr>\n";
                           }
                         out <<  "</table>\n"
                                 "</body>\n"
                                 "</html>\n";

              QTextDocument *document = new QTextDocument();
                            document->setHtml(strStream);

             QPrinter printer;
             painter.drawPixmap(25,25,QPixmap(":/pic/logo"));
             painter.drawText(25,100,"ldkjsflkdjflskjflsjdfsljf");

                QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                           if (dialog->exec() == QDialog::Accepted) {

                                document->print(&printer);
                            }

                            delete document;



        }



void rec::on_stat_2_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
                   model->setQuery("select * from RECLAMATION where TYPE_R = 'client'");
                   float dispo1=model->rowCount();

                   model->setQuery("select * from RECLAMATION where TYPE_R = 'employee'");
                   float dispo=model->rowCount();

                   model->setQuery("select * from RECLAMATION where TYPE_R = 'sponsor'");
                   float dispo3=model->rowCount();

                   float total=dispo1+dispo+dispo3;
                       QString a=QString("client" +QString::number((dispo1*100)/total,'f',2)+"%" );
                       QString b=QString("employee  " +QString::number((dispo*100)/total,'f',2)+"%" );
                       QString c=QString("sponsor  " +QString::number((dispo3*100)/total,'f',2)+"%" );
                       QPieSeries *series = new QPieSeries();
                       series->append(a,dispo1);
                       series->append(b,dispo);
                       series->append(c,dispo3);
                   if (dispo1!=0)
                   {QPieSlice *slice = series->slices().at(0);
                       slice->setLabelVisible();
                       slice->setPen(QPen());}
                   if ( dispo!=0)
                   {
                       QPieSlice *slice1 = series->slices().at(1);
                       slice1->setLabelVisible();
                       slice1->setPen(QPen());
                   }
                   if (dispo3!=0)
                   {QPieSlice *slice = series->slices().at(2);
                       slice->setLabelVisible();
                       slice->setPen(QPen());}

                   QChart *chart = new QChart();


                   chart->addSeries(series);
                   chart->setTitle("Nombre: "+ QString::number(total));



                   QChartView *chartView = new QChartView(chart);
                   chartView->setRenderHint(QPainter::Antialiasing);
                   chartView->resize(1300,800);
                   chartView->show();


}




void rec::on_pushButtonplay_clicked()
{
    player= new QMediaPlayer;
    vw=new QVideoWidget;

    auto filename=QFileDialog::getOpenFileName(this,"import mp4 file");
if(filename.isEmpty()){

    QMessageBox::critical(nullptr, QObject::tr("VIDEO"),
                QObject::tr("ADD A VIDEO.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else{
    player->setVideoOutput(vw);
    player->setMedia(QUrl::fromLocalFile(filename));
    vw->setGeometry(100,100,800,600);
    vw->show();
    player->play();
}
}

void rec::on_pushButtonstop_clicked()
{
    player->stop();
    vw->close();
}



void rec::on_camera_clicked()
{


        c= new camera();
        c->show();

}





void rec::on_radioButton_toggled(bool checked)
{
    heat Y;
    if(checked==true)
    {
        ui->tableView_c->setModel(Y.check());
    }

    else {
        ui->tableView_c->setModel(Y.check_overheat());

        }
}

void rec::on_tablerec_clicked(const QModelIndex &index)
{


        selected=ui->tablerec->model()->data(index).toInt();

 }





    void rec::on_pb_delete_rec_clicked()
    {
        if(ui->tablerec->currentIndex().row()==-1)
                   QMessageBox::information(nullptr, QObject::tr("DELETE"),
                                            QObject::tr("choose first\n"
                                                        "Click Ok to exit."), QMessageBox::Ok);
        Reclamation X;
                X.supprimer(selected);
                ui->tablerec->setModel(X.afficher());


    }

void rec::on_modiftable_clicked(const QModelIndex &index)
{
    selectedd=ui->modiftable->model()->data(index).toInt();
}






void rec::on_pb_modify_clicked()
{

    QString CAS=ui->mody_cas->text();
    QString sati=ui->modi_sat->text();
    QString fb=ui->modi_feed->text();
    Reclamation X;
    bool test=X.modify(selectedd,CAS,sati,fb);


    if(ui->modiftable->currentIndex().row()==-1)
               QMessageBox::information(nullptr, QObject::tr("Modify"),
                                        QObject::tr("choose first \n"
                                                    "Click Ok to exit."), QMessageBox::Ok);

    if((fb.isEmpty())||(sati.isEmpty())||(CAS.isEmpty()))
    {
        QMessageBox msgBox ;
        msgBox.setText("empty") ;
   msgBox.exec();
    }

    else if (test)
    {
      QMessageBox msgBox ;
      msgBox.setText("DONE") ;
      msgBox.exec();
      ui->tablerec->setModel(X.afficher());
      ui->modiftable->setModel(X.afficher());
      ui->mody_cas->clear();
      ui->modi_sat->clear();
      ui->modi_feed->clear();
  }

    else
    {
        QMessageBox msgBox;
        msgBox.setText("FAILED") ;
        msgBox.exec();

    }
}










void rec::on_pushButtonmenu_clicked()
{
    close();
    MainWindow *w = new MainWindow();
    w->setWindowTitle("MainWindow");
    w->show();
}
