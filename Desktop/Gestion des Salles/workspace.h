#ifndef WORKSPACE_H
#define WORKSPACE_H

#include <QMainWindow>

namespace Ui {
class workspace;
}

class workspace : public QMainWindow
{
    Q_OBJECT

public:
    explicit workspace(QWidget *parent = nullptr);
    ~workspace();

private slots:
    void on_ajouter_clicked();

    void on_supprimer_clicked();

    void on_modifier_clicked();

private:
    Ui::workspace *ui;
};

#endif // WORKSPACE_H
