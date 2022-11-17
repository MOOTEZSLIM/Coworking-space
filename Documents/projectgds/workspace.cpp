#include "workspace.h"
#include "ui_workspace.h"
#include "stat_salle.h"
#include <QMessageBox>
#include "salles.h"
#include <QMainWindow>
#include <QSqlQuery>
#include "exportexcel.h"
#include <QFileDialog>
#include <QPrintDialog>
#include <QPrinter>
#include <QTextStream>
#include <QTableView>
#include <QSortFilterProxyModel>
#include "qrcode.h"
#include <QSvgRenderer>
#include <QPainter>
#include "qrwidget.h"
#include <iostream>
#include <fstream>
#include "smtp.h"
using qrcodegen::QrCode;
using qrcodegen::QrSegment;


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
               // ui->lineEdit_cap_2->clear();
                //ui->timeEdit_ho_2->clear();
                ui->timeEdit_hf_2->clear();
                ui->lineEdit_lm_2->clear();



   }

}







void workspace::on_pushButton_rech_clicked()
{
        Salles S;
        QString search=ui->lineEdit_R->text();
        ui->tableView_S->setModel(S.rechercher(search));
}

void workspace::on_rb_id_toggled(bool checked)
{
    Salles S;
    if (checked == true){
               ui->tableView_S->setModel(S.trierIDSALLE());
           } else {
                ui->tableView_S->setModel(S.afficher());
           }
}

void workspace::on_rb_cap_toggled(bool checked)
{
    Salles S;
    if (checked == true){
               ui->tableView_S->setModel(S.trierCAPSALLE());
           } else {
                ui->tableView_S->setModel(S.afficher());
           }
}

void workspace::on_rb_ho_toggled(bool checked)
{
    Salles S;
    if (checked == true){
               ui->tableView_S->setModel(S.trierHOSALLE());
           } else {
                ui->tableView_S->setModel(S.afficher());
           }
}



void workspace::on_pushButton_PDF_clicked()
{
    Salles S;
        bool test=false;
        test=S.PDF();
        if(test)

            {
            ui->tableView_S->setModel(S.afficher());
            QMessageBox::information(nullptr, QObject::tr("créé"),

                                QObject::tr(" PDF créé.\n"

                                            "Click Cancel to exit."), QMessageBox::Cancel);}
        else

            {

                QMessageBox::critical(nullptr, QObject::tr("non créé"),

                            QObject::tr("PDF non créé !.\n"

                                        "Click Cancel to exit."), QMessageBox::Cancel);



    }

}

void workspace::on_pushButton_EXCEL_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                    tr("Excel Files (*.xls)"));
    if (fileName.isEmpty())
        return;

    exportExcel obj(fileName, "mydata", ui->tableView_S);

    //colums to export
               obj.addField(0, "IDSALLE", "char(20)");
               obj.addField(1, "CAPSALLE", "char(20)");
               obj.addField(2, "HOSALLE", "char(20)");
               obj.addField(3, "HFSALLE", "char(20)");
               obj.addField(4, "LISTE_MATERIEL", "char(40)");



    int retVal = obj.export2Excel();
    if( retVal > 0)
    {
        QMessageBox::information(this, tr("Done"),
                                 QString(tr("%1 records exported!")).arg(retVal)
                                 );
    }
}



void workspace::on_imp_clicked()
{
    QString strStream;
    QTextStream out(&strStream);



    const int rowCount = ui->tableView_S->model()->rowCount();
    const int columnCount = ui->tableView_S->model()->columnCount();

    out <<  "<html>\n"
           "<head>\n"

           "<meta Content=\"Text/html; charset=Windows-1251\">\n"
           <<  QString("<title>%60 les postes</title>\n").arg("poste")
          <<  "</head>\n"
           "<body bgcolor=#ffffff link=#5000A0>\n"
           "<table border=1 cellspacing=0 cellpadding=2>\n";
           out << "<thead><tr bgcolor=#f0f0f0>";
           for (int column = 0; column < columnCount; column++)
           if (! ui->tableView_S->isColumnHidden(column))
           out << QString("<th>%1</th>").arg(ui->tableView_S->model()->headerData(column, Qt::Horizontal).toString());
           out << "</tr></thead>\n";

           for (int row = 0; row < rowCount; row++) {
                out << "<tr>";
                for (int column = 0; column < columnCount; column++) {
                  if (!ui->tableView_S->isColumnHidden(column)) {
                   QString data = ui->tableView_S->model()->data(ui->tableView_S->model()->index(row, column)).toString().simplified();
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
void workspace::show_tables(){

    Salles tmp;
    QSortFilterProxyModel *proxy;
    proxy = new QSortFilterProxyModel();

 //definir la source (tableau original)
    proxy->setSourceModel(tmp.afficher());

 //pour la recherche
    proxy->setFilterCaseSensitivity(Qt::CaseInsensitive); // S=s (pas de difference entre majiscule et miniscule)
    proxy->setFilterKeyColumn(-1); // chercher dans tout le tableau (-1) ou donner le numero de la colone
   //remplissage tableau avec le masque
    ui->tableView_S->setModel(proxy);

}



void workspace::on_tableView_S_clicked(const QModelIndex &index)
{
    selected=ui->tableView_S->model()->data(index).toInt();
}

void workspace::on_supprimer_2_clicked()
{
    Salles p;
    p.supprimer(selected);

    //refresh du tableau (affichage)
     show_tables();
}


void workspace::on_pushButton_27_clicked()
{
    {
        if(ui->tableView_S->currentIndex().row()==-1)
                   QMessageBox::information(nullptr, QObject::tr("Suppression"),
                                            QObject::tr("Veuillez Choisir un identifiant.\n"
                                                        "Click Ok to exit."), QMessageBox::Ok);
               else
               {

                    int IDSALLE=ui->tableView_S->model()->data(ui->tableView_S->model()->index(ui->tableView_S->currentIndex().row(),0)).toInt();
                    const QrCode qr = QrCode::encodeText(std::to_string(IDSALLE).c_str(), QrCode::Ecc::LOW);
                    std::ofstream myfile;
                    myfile.open ("qrcode.svg") ;
                    myfile << qr.toSvgString(1);
                    myfile.close();
                    QPixmap pix( QSize(90, 90) );
                    QPainter pixPainter( &pix );
                    QSvgRenderer svgRenderer(QString("qrcode.svg"));
                    svgRenderer.render( &pixPainter );
                    ui->QRCODE_3->setPixmap(pix);

               }
    }
}


void workspace::sendMail()
{
    Smtp* smtp = new Smtp(ui->uname->text(), ui->paswd->text(), ui->server->text(), ui->port->text().toUShort());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}


void workspace::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}


void workspace::on_send_clicked()
{
    sendMail();
}

void workspace::on_pushButtonSTAT_clicked()
{
    s = new stat_salle();

   s->setWindowTitle("statistique ComboBox");
   s->choix_pie();
   s->show();
}

void workspace::on_pushButtonplay_clicked()
{
    player= new QMediaPlayer;
    vw=new QVideoWidget;

    auto filename=QFileDialog::getOpenFileName(this,"import mp4 file");
if(filename.isEmpty()){

    QMessageBox::critical(nullptr, QObject::tr("VIDEO"),
                QObject::tr("AJOUTER UN VIDEO.\n"
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

void workspace::on_pushButtonstop_clicked()
{
    player->stop();
    vw->close();

}
