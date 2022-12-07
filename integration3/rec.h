#ifndef REC_H
#define REC_H


#include <QMainWindow>
#include "reclamation.h"
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QMediaPlayer>
#include <QVideoWidget>
#include "camera.h"
#include "heat.h"
namespace Ui {
class rec;
}

class rec : public QDialog
{
    Q_OBJECT

public:
    explicit rec(QWidget *parent = nullptr);
    ~rec();


private slots:




    void on_pb_ajouter_avie_clicked();

    void on_pb_ajouter_salle_clicked();

    void on_pb_ajouter_employee_clicked();

    void on_pb_ajouter_spons_clicked();

    void on_pb_delete_rec_clicked();

    void on_pb_modify_clicked();

    void on_pb_chercher_clicked();

    void on_solved_toggled(bool checked);

    void on_type_toggled(bool checked);

    void on_PDF_clicked();

    void on_stat_2_clicked();

    void on_pushButtonplay_clicked();

    void on_pushButtonstop_clicked();



    void on_camera_clicked();




    void on_radioButton_toggled(bool checked);

    void on_tablerec_clicked(const QModelIndex &index);

    void on_modiftable_clicked(const QModelIndex &index);

    void on_pushButtonmenu_clicked();

private:
    Ui::rec *ui;
    int selected=0;
    int selectedd=0;
    Reclamation X;
    QStringList files;
    QMediaPlayer* player;
    QVideoWidget* vw;
    QMediaPlaylist* m_playlist;
    QByteArray data; // variable contenant les données reçues
    heat Y;
    camera *c;
};


#endif // REC_H

