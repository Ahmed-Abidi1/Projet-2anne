#ifndef MATE_INTER_H
#define MATE_INTER_H

#include <QDialog>
#include "mate_fonc.h"
#include <QTimer>

class vehicule_inter;
class espace_inter;
class employe_inter;

namespace Ui {
class mate_inter;
}

class mate_inter : public QDialog
{
    Q_OBJECT

public:
    explicit mate_inter(QWidget *parent = nullptr);
    ~mate_inter();

private slots:
    void on_fonction_clicked();

    void on_ges_appar_clicked();

    void on_ges_vehic_clicked();

    void on_ges_es_vert_clicked();

    void on_ges_emp_clicked();

    void on_valider_clicked();
    void on_annuler_clicked();
    void on_recherche_clicked();
    void on_trier_clicked();
    void on_supprimer_clicked();
    void on_modifier_clicked();

    void on_exportToPDF_clicked();

private:
    Ui::mate_inter *ui;
    mate_fonc *materielfonc;
    vehicule_inter *vehiculeWindow;
    espace_inter *espaceWindow;
    employe_inter *employeWindow;

    void clearAddFields();
    void refreshTable();
    bool validateInputs();
    bool validateInputsForAdd();  // New function for adding materials
    bool containsOnlyLettersAndSpaces(const QString &str);
    bool containsOnlyLettersAndNumbers(const QString &str);
    bool containsOnlyNumbers(const QString &str);
    void addNotification(const QString &message);
    QString generateBarcode();  // Function to generate barcode
};

#endif // MATE_INTER_H
