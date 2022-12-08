#ifndef WORKSPACE_H
#define WORKSPACE_H

#include <QMainWindow>
#include "stat_salle.h"
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QSerialPort>
#include "arduino.h"
#include <QByteArray>
namespace Ui {
class workspace;
}

class workspace : public QMainWindow
{
    Q_OBJECT

public:
    explicit workspace(QWidget *parent = nullptr);
    ~workspace();


    void show_tables();

private slots:
    void on_ajouter_clicked();

    void on_modifier_clicked();

    void on_pushButton_rech_clicked();

    void on_rb_id_toggled(bool checked);

    void on_rb_cap_toggled(bool checked);

    void on_rb_ho_toggled(bool checked);

    void on_pushButton_PDF_clicked();

    void on_pushButton_EXCEL_clicked();

    void on_imp_clicked();

    void on_tableView_S_clicked(const QModelIndex &index);

    void on_supprimer_2_clicked();

    void on_pushButton_27_clicked();

    void sendMail();

    void mailSent(QString);

    void on_send_clicked();

    void on_pushButtonSTAT_clicked();

    void on_pushButtonplay_clicked();

    void on_pushButtonstop_clicked();

    void on_ajouter_ard_clicked();

    void on_ajouter_sa_clicked();




    void update_label();
    void on_pushButton_clicked();

    void on_pushButtonmenu_clicked();

private:
    Ui::workspace *ui;
       int selected=0;
       QStringList files;
       stat_salle *s;
       QMediaPlayer* player;
       QVideoWidget* vw;
       QMediaPlaylist* m_playlist;
Arduino A;
    QByteArray data;
       QSerialPort * serial;
           QString portname;
           quint16 vendorId;
           quint16 productId;
           bool arduino_available;
           void arduino_init();




};

#endif // WORKSPACE_H
