#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "employee.h"
#include "statistic.h"


namespace Ui { class MainWindow; }




class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_ajouterButton_4_clicked();

    void on_supprimerButton_5_clicked();







void on_modifierButton_4_clicked();



    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();



    void on_pushButton_9_clicked();

private:
    Ui::MainWindow *ui;

    Employee e;
    Statistic *statistic;

};
#endif // MAINWINDOW_H
