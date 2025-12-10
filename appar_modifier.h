#ifndef APPAR_MODIFIER_H
#define APPAR_MODIFIER_H

#include <QDialog>
#include <QString>
#include <QMessageBox>

namespace Ui {
class appar_modifier;
}

class appar_modifier : public QDialog
{
    Q_OBJECT

public:
    explicit appar_modifier(QWidget *parent = nullptr);
    ~appar_modifier();
    
    void chargerAppartement(QString idAppartement);

signals:
    void appartementModifie();

private slots:
    void on_modifier_clicked();
    void on_annuler_clicked();

private:
    QMessageBox* createStyledMessageBox(QMessageBox::Icon icon, const QString& title, const QString& text, QMessageBox::StandardButtons buttons = QMessageBox::Ok);
    Ui::appar_modifier *ui;
    QString currentId;
};

#endif // APPAR_MODIFIER_H
