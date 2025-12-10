#ifndef EMPLOYE_INTER_H
#define EMPLOYE_INTER_H

#include <QDialog>
#include "employe_fonc.h"

namespace Ui {
class employe_inter;
}

class employe_inter : public QDialog
{
    Q_OBJECT

public:
    explicit employe_inter(QWidget *parent = nullptr);
    ~employe_inter();

private slots:
    void on_loginButton_clicked();
    void on_faceIdButton_clicked();

private:
    Ui::employe_inter *ui;

    employe_fonc *employeWindow;
};

#endif
