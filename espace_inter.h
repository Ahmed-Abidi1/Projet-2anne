#ifndef ESPACE_INTER_H
#define ESPACE_INTER_H

#include <QDialog>
#include <QList>
#include "espace_fonc.h"
#include "espace.h"
#include "espace_modifier.h"

class vehicule_inter;
class mate_inter;
class employe_inter;

namespace Ui {
class espace_inter;
}

class espace_inter : public QDialog
{
    Q_OBJECT

public:
    explicit espace_inter(QWidget *parent = nullptr);
    ~espace_inter();

private slots:
    void on_pushButton_2_clicked();
    void on_ges_appar_clicked();
    void on_ges_vehic_clicked();
    void on_ges_mat_clicked();
    void on_ges_emp_clicked();
    void on_fonction_clicked();
    void on_ges_es_vert_clicked();
    void on_valider_clicked();
    void on_annuler_clicked();
    void on_recherche_clicked();
    void on_trier_clicked();
    void on_modifier_clicked();
    void on_supprimer_clicked();
    void on_pdf_clicked();  // <--- Ajout du slot ici

private:
    void afficherEspaces(const QList<Espace>& espaces);
    Ui::espace_inter *ui;
    Espace_fonc *espaceFonc;
    vehicule_inter *vehiculeWindow;
    mate_inter *materielWindow;
    employe_inter *employeWindow;
    espace_modifier *modifierWindow;
    QList<Espace> currentEspaces;
};

#endif // ESPACE_INTER_H
