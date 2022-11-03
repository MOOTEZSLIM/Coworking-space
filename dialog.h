#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "sponsors.h"
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


private:
    Ui::Dialog *ui;
    Sponsors S;

};

#endif // DIALOG_H
