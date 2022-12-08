#ifndef EMPLOYE_H
#define EMPLOYE_H




#include <QMainWindow>
#include "gestion_employe.h"
#include "statistic.h"


namespace Ui {
class employe;
}

class employe : public QDialog
{
    Q_OBJECT

public:
    employe(QWidget *parent = nullptr);
    ~employe();

private slots:

    void on_ajouterButton_4_clicked();

    void on_supprimerButton_5_clicked();







void on_modifierButton_4_clicked();



    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();



    //void on_pushButton_9_clicked();
void on_statsmed_clicked();
void on_pushButtonmenu_clicked();
private:
    Ui::employe *ui;

     gestion_employe e;
    Statistic *statistic;

};


#endif // EMPLOYE_H
