#ifndef ESPACE_MODIFIER_H
#define ESPACE_MODIFIER_H

#include <QDialog>
#include <QString>

namespace Ui {
class espace_modifier;
}

class espace_modifier : public QDialog
{
    Q_OBJECT

public:
    explicit espace_modifier(QWidget *parent = nullptr);
    ~espace_modifier();
    
    void chargerEspace(QString nomEspace);

signals:
    void espaceModifie();

private slots:
    void on_modifier_clicked();
    void on_annuler_clicked();

private:
    Ui::espace_modifier *ui;
    QString currentNom;
};

#endif // ESPACE_MODIFIER_H
