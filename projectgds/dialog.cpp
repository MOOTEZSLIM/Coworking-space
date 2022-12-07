#include "dialog.h"
#include "ui_dialog.h"
#include "sponsors.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QIntValidator>
#include <QSqlQueryModel>
#include <QDebug>
#include <QFileDialog>
#include <QPainter>
#include <QPdfWriter>
#include <qpdfwriter.h>
#include <QPrinter>
#include <QTextDocument>
#include <QPrintDialog>
#include <QTcpSocket>
#include <QTcpServer>
#include <QTextStream>
#include <QLineEdit>
#include <QPieSlice>
#include <QPieSlice>
#include <QPieSeries>
#include <QValidator>
#include "dialog.h"
#include <QIntValidator>
#include "mainwindow.h"
#include <QtCharts>
#include <QChartView>


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
//ui->le_datecr->setValidator(new QIntValidator(0, 99999999, this));
ui->tab_aff->setModel(S.afficher());
        /* ui->le_nomsoc->setValidator(validator);
         ui->le_typespon->setValidator(validator);



         ui->le_nomsoc->setMaxLength(10);
         ui->le_typespon->setMaxLength(10);


         ui->le_nomsoc->setValidator(new QRegExpValidator(QRegExp("[A-Z][a-z]*")));
         ui->le_typespon->setValidator(new QRegExpValidator(QRegExp("[A-Z][a-z]*")));*/

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pb_ajouter_clicked()
{
    QString datecre=ui->le_datecr->text();
    QString noms=ui->le_nomsoc->text();
    QString type_sponsor=ui->le_typespon->text();
    QString periodes=ui->le_prdspon->text();
    Sponsors S (datecre,noms,type_sponsor,periodes);

    bool test=S.ajouter();
        if(test)
        {
            ui->tab_aff->setModel(S.afficher());
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

void Dialog::on_pb_rech_clicked()
{
    QString noms = ui->le_nomsoc->text();

    ui->tab_rech->setModel(S.recherche(noms));


}

void Dialog::on_radioButton_toggled(bool checked)
{
    if (checked == true){
                       ui->tab_rech->setModel(S.trier());
                   } else {
                        ui->tab_rech->setModel(S.afficher());
                   }
}



void Dialog::on_radioButton_3_toggled(bool checked)
{
    if (checked == true){
                       ui->tab_rech->setModel(S.trierperiodes());
                   } else {
                        ui->tab_rech->setModel(S.afficher());
                   }
}

void Dialog::on_pb_pdf_clicked()
{

    {
        QString strStream;
        QTextStream out(&strStream);



        const int rowCount = ui->tab_aff->model()->rowCount();
        const int columnCount = ui->tab_aff->model()->columnCount();

        out <<  "<html>\n"
               "<head>\n"

               "<meta Content=\"Text/html; charset=Windows-1251\">\n"
               <<  QString("<title>%60 les postes</title>\n").arg("poste")
              <<  "</head>\n"
               "<body bgcolor=#ffffff link=#5000A0>\n"
               "<table border=1 cellspacing=0 cellpadding=2>\n";
               out << "<thead><tr bgcolor=#f0f0f0>";
               for (int column = 0; column < columnCount; column++)
               if (! ui->tab_aff->isColumnHidden(column))
               out << QString("<th>%1</th>").arg(ui->tab_aff->model()->headerData(column, Qt::Horizontal).toString());
               out << "</tr></thead>\n";

               for (int row = 0; row < rowCount; row++) {
                    out << "<tr>";
                    for (int column = 0; column < columnCount; column++) {
                      if (!ui->tab_aff->isColumnHidden(column)) {
                       QString data = ui->tab_aff->model()->data(ui->tab_aff->model()->index(row, column)).toString().simplified();
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

            QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                       if (dialog->exec() == QDialog::Accepted) {
                            document->print(&printer);
                        }

                        delete document;

    }
}

void Dialog::on_pb_logo_clicked()
{
    QString filename= QFileDialog::getOpenFileName(this,tr("CHOOSE"),"",tr("Images(*.png *.jpg *.jpeg *.bmp *.gif)"));
            if(QString::compare(filename,QString())!=0)
            {
                QImage image;
                bool valid = image.load(filename);
                if(valid)
                {
                    image= image.scaledToWidth(ui->le_logo->width(), Qt::SmoothTransformation);
                    image= image.scaledToHeight(ui->le_logo->height(), Qt::SmoothTransformation);
                    ui->le_logo->setPixmap(QPixmap::fromImage(image));
                }
                else
                {
                    QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                    QObject::tr("Add Failed !"), QMessageBox::Ok);
                }
            }
}



void Dialog::on_pb_stat_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
                         model->setQuery("select * from SPONSORS where type_sponsor = 'argent'");
                         float dispo1=model->rowCount();

                         model->setQuery("select * from SPONSORS where type_sponsor = 'objet'");
                         float dispo=model->rowCount();

                         model->setQuery("select * from SPONSORS where type_sponsor = 'formation'");
                         float dispo3=model->rowCount();

                         float total=dispo1+dispo+dispo3;
                             QString a=QString("Argent " +QString::number((dispo1*100)/total,'f',2)+"%" );
                             QString b=QString("Objet  " +QString::number((dispo*100)/total,'f',2)+"%" );
                             QString c=QString("formation  " +QString::number((dispo3*100)/total,'f',2)+"%" );
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


void Dialog::on_pushButton_clicked()
{
    close();
    MainWindow *w = new MainWindow();
    w->setWindowTitle("MainWindow");
    w->show();
}
