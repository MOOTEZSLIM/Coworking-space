#include "envoi_sms.h"
#include "ui_envoi_sms.h"

envoi_sms::envoi_sms(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::envoi_sms)
{
    ui->setupUi(this);
}

envoi_sms::~envoi_sms()
{
    delete ui;
}
