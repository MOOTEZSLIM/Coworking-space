#ifndef ENVOI_SMS_H
#define ENVOI_SMS_H

#include <QDialog>

namespace Ui {
class envoi_sms;
}

class envoi_sms : public QDialog
{
    Q_OBJECT

public:
    explicit envoi_sms(QWidget *parent = nullptr);
    ~envoi_sms();

private:
    Ui::envoi_sms *ui;
};

#endif // ENVOI_SMS_H
