#ifndef CLIE_H
#define CLIE_H
#include <client.h>
#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class Clie; }
QT_END_NAMESPACE

class Clie : public QMainWindow
{
    Q_OBJECT

public:
    Clie(QWidget *parent = nullptr);
    ~Clie();

private slots:
    void on_ajouter_clicked();



    void on_suppri_clicked();

    void on_modifier_clicked();





    void on_radioButton_toggled(bool checked);

    void on_radioButton_2_toggled(bool checked);

    void on_radioButton_3_toggled(bool checked);


    void on_statistique_clicked();


    void on_pb_pdf_clicked();

    void on_pb_rechercher_clicked();

    void on_table_clicked(const QModelIndex &index);

    void on_tarif_clicked();

    void on_radioButton_4_toggled(bool checked);

    void on_WHATS_clicked();

    void on_pushButtonC9_clicked();

private:
    Ui::Clie *ui;
    client c;
        int selected=0;
};
#endif // CLIE_H
