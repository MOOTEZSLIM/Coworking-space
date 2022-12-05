#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    close();
    workspace *w = new workspace();
    w->setWindowTitle("my workspace");
    w->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    close();
    rec *w = new rec();
    w->setWindowTitle("rec");
    w->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    close();
    Dialog *w = new Dialog();
    w->setWindowTitle("my workspace");
    w->show();
}
