#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QMessageBox>
#include "appar_fonction.h"
#include "vehicule_inter.h"
#include "espace_inter.h"
#include "mate_inter.h"
#include "employe_inter.h"
#include "appartement.h"
#include "appar_modifier.h"
#include "arduinomonitor.h"  // ADD THIS

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_fonction_clicked();
    void on_ges_vehic_clicked();
    void on_ges_es_vert_clicked();
    void on_ges_mat_clicked();
    void on_ges_emp_clicked();
    void on_valider_clicked();
    void on_annuler_clicked();
    void on_recherche_clicked();
    void on_trier_clicked();
    void on_modifier_clicked();
    void on_supprimer_clicked();
    void on_pdf_clicked();

private:
    void afficherAppartements(const QList<Appartement>& appartements);
    QMessageBox* createStyledMessageBox(QMessageBox::Icon icon, const QString& title, const QString& text, QMessageBox::StandardButtons buttons = QMessageBox::Ok);
    void setupArduinoMonitor();
    void autoConnectToArduino();

    Ui::MainWindow *ui;
    appar_fonction *apparWindow;
    vehicule_inter *vehiculeWindow;
    espace_inter *espaceWindow;
    mate_inter *materielWindow;
    employe_inter *employeWindow;
    appar_modifier *modifierWindow;
    QList<Appartement> currentAppartements;
    ArduinoMonitor *arduinoMonitor;  // ADD THIS
};

#endif // MAINWINDOW_H
