#ifndef STAT_SALLE_H
#define STAT_SALLE_H

#include <QDialog>

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

#include <QChartView>
#include <QBarSeries>
#include <QBarSet>
#include <QLegend>
#include <QBarCategoryAxis>
#include <QHorizontalStackedBarSeries>
#include <QLineSeries>
#include <QCategoryAxis>
#include <QPieSeries>
#include <QPieSlice>
QT_CHARTS_USE_NAMESPACE

namespace Ui {
class stat_salle;
}

class stat_salle : public QDialog
{
    Q_OBJECT

public:
    explicit stat_salle(QWidget *parent = nullptr);
    ~stat_salle();

    QChartView *chartView ;
    void choix_bar();
    void choix_pie();


private:
    Ui::stat_salle *ui;
};

#endif // STAT_SALLE_H
