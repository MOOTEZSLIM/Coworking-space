
#ifndef LOGIN_H
#define LOGIN_H
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QFileInfo>
#include <QDialog>
#include "arduinoem.h"
namespace Ui {
  class login ;
}

class login : public QDialog
{
  Q_OBJECT

public:
  explicit login(QWidget *parent = nullptr);
  ~login();

public slots:

private:
  Ui::login *ui;
  QByteArray data; // variable contenant les données reçues

     arduinoEm A; // objet temporaire
public:
  QSqlDatabase mydb;
private slots:
      void update_label();
  void on_pushButton_5_clicked();
};

#endif // LOGIN_H
