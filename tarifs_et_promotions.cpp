#include "tarifs_et_promotions.h"
#include "ui_tarifs_et_promotions.h"

Tarifs_et_promotions::Tarifs_et_promotions(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tarifs_et_promotions)
{
    ui->setupUi(this);
}

Tarifs_et_promotions::~Tarifs_et_promotions()
{
    delete ui;
}
