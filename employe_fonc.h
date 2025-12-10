#ifndef EMPLOYE_FONC_H
#define EMPLOYE_FONC_H

#include <QDialog>
#include <QModelIndex>
#include <QSqlQueryModel> // Ajouté pour QSqlQueryModel

#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>

#include <QChartView>
#include <QBarSet>
#include <QBarSeries>
#include <QChart>
#include <QBarCategoryAxis>
#include <QValueAxis>

#include <QSqlQuery>

#include <QMainWindow>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

#include "vehicule_inter.h"
#include "espace_inter.h"
#include "mate_inter.h"

namespace Ui {
class employe_fonc;
}

class employe_fonc : public QDialog
{
    Q_OBJECT

public:
    explicit employe_fonc(QWidget *parent = nullptr);
    ~employe_fonc();


private slots:
    void on_valider_clicked();
    void on_supprimer_clicked();
    void on_modifier_clicked();
    void on_recherche_clicked();
    void on_trier_clicked();
    void on_annuler_clicked();
    void on_tableWidget_clicked(const QModelIndex &index);
    void on_export_2_clicked();   // Bouton PDF
    void on_pushButton_trier_clicked();

    void on_ges_appar_clicked();
    void on_ges_vehic_clicked();
    void on_ges_es_vert_clicked();
    void on_ges_mat_clicked();

private:
    Ui::employe_fonc *ui;
    // DÉCLARATION DE LA FONCTION UTILITAIRE
    void remplirTableau(QSqlQueryModel *model);
    void statistiquesSalaire();

    vehicule_inter *vehiculeWindow;
    espace_inter *espaceWindow;
    mate_inter *materielWindow;
};

#endif
