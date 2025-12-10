
#include "employe_inter.h"
#include "ui_employe_inter.h"
#include "employe_fonc.h"
#include <QMessageBox>

employe_inter::employe_inter(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::employe_inter)
{
    ui->setupUi(this);
}

employe_inter::~employe_inter()
{
    delete ui;
}

void employe_inter::on_loginButton_clicked()
{
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();

    // Validation simple (vous pouvez ajouter une vérification avec la base de données)
    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Erreur de connexion",
                             "Veuillez remplir tous les champs.");
        return;
    }

    // Vérification basique - vous pouvez la remplacer par une vérification en base de données
    if (username == "admin" && password == "admin") {
        QMessageBox::information(this, "Succès",
                                 "Connexion réussie!");

        hide();
        employeWindow = new employe_fonc(this);
        employeWindow->show();
        accept();
    } else {
        QMessageBox::warning(this, "Erreur de connexion",
                             "Nom d'utilisateur ou mot de passe incorrect.");
    }
}

void employe_inter::on_faceIdButton_clicked()
{
    // Simulation de Face ID
    QMessageBox::information(this, "Simulation Face ID",
                             "Face ID simulé avec succès!");

    hide();
    employeWindow = new employe_fonc(this);
    employeWindow->show();
    accept();
}
