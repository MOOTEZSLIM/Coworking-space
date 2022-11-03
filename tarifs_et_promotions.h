#ifndef TARIFS_ET_PROMOTIONS_H
#define TARIFS_ET_PROMOTIONS_H

#include <QDialog>

namespace Ui {
class Tarifs_et_promotions;
}

class Tarifs_et_promotions : public QDialog
{
    Q_OBJECT

public:
    explicit Tarifs_et_promotions(QWidget *parent = nullptr);
    ~Tarifs_et_promotions();

private:
    Ui::Tarifs_et_promotions *ui;
};

#endif // TARIFS_ET_PROMOTIONS_H
