
#define MAINWINDOW_H

#include <QMainWindow>
#include "reclamation.h"
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QMediaPlayer>
#include <QVideoWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

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



private:
    Ui::MainWindow *ui;
    Reclamation X;
    QStringList files;
    QMediaPlayer* player;
    QVideoWidget* vw;
    QMediaPlaylist* m_playlist;

};
