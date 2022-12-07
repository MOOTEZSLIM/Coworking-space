#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "sponsors.h"
#include <QTcpSocket>
#include <QValidator>


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:


    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();


    void on_pb_modifier_clicked();


    void on_pb_rech_clicked();

    void on_radioButton_toggled(bool checked);



    void on_radioButton_3_toggled(bool checked);

    void on_pb_pdf_clicked();

    void on_pb_logo_clicked();

    void on_pb_stat_clicked();





    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
    Sponsors S;
    QTcpSocket *mSocket;

    QByteArray data;




};

#endif // DIALOG_H

