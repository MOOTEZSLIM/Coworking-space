#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QString>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
public:
    void setcin (QString n);
    void setnom (QString n);
    void setprenom (QString n);
public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_ajouter_clicked();
private:
client c;
};

#endif // DIALOG_H
