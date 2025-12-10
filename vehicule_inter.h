#ifndef VEHICULE_INTER_H
#define VEHICULE_INTER_H

#include <QDialog>
#include "vehicule_fonc.h"
#include "mate_inter.h"
#include "vehicules.h"
#include <QTableWidgetItem>

class espace_inter;
class employe_inter;

namespace Ui {
class vehicule_inter;
}

class vehicule_inter : public QDialog
{
    Q_OBJECT

public:
    explicit vehicule_inter(QWidget *parent = nullptr);
    ~vehicule_inter();

private slots:
    void on_fonction_clicked();
    void on_ges_appar_clicked();
    void on_ges_es_vert_clicked();
    void on_ges_mat_clicked();
    void on_ges_emp_clicked();
    void on_validerV_clicked();
    void on_annulerV_clicked();
    void on_modifierV_clicked();
    void on_supprimerV_clicked();
    void on_tableWidgetv_itemClicked(QTableWidgetItem *item);
    void on_recherche_clicked();

    void on_trier_clicked();

    void on_pdf_clicked();

private:
    Ui::vehicule_inter *ui;
    vehicule_fonc *vehiculefonc;
    espace_inter *espaceWindow;
    mate_inter *materielWindow;
    employe_inter *employeWindow;

    int selectedVehiculeId = -1;
    int selectedEmployeId = 0;

    void refreshTable();
    void clearVehiculeFields();
    void loadEmployesCombo();

    bool checkIdVehicule(const QString &idText, int &idValue);
    bool checkNumSerie(const QString &numSerie);
    bool checkLocalisation(const QString &loc);
    bool checkMarque(const QString &marque);
    bool checkModele(const QString &modele);
    bool checkProprietaire(const QString &prop);
};

#endif // VEHICULE_INTER_H
