#include "appar_modifier.h"
#include "ui_appar_modifier.h"
#include "appartement.h"
#include <QMessageBox>
#include <QPushButton>
#include <QLabel>

appar_modifier::appar_modifier(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::appar_modifier)
{
    ui->setupUi(this);
    
    ui->id->setReadOnly(true);
    
    ui->checkBox->setText("Occupé");
}

appar_modifier::~appar_modifier()
{
    delete ui;
}

QMessageBox* appar_modifier::createStyledMessageBox(QMessageBox::Icon icon, const QString& title, const QString& text, QMessageBox::StandardButtons buttons)
{
    QMessageBox* msgBox = new QMessageBox(this);
    msgBox->setIcon(icon);
    msgBox->setWindowTitle(title);
    msgBox->setText(text);
    msgBox->setStandardButtons(buttons);
    
    // Set text color to black and font to Franklin Gothic Heavy
    QString styleSheet = QString(
        "QMessageBox {"
        "    color: black;"
        "    font-family: 'Franklin Gothic Heavy', 'Franklin Gothic', Arial, sans-serif;"
        "    font-weight: bold;"
        "}"
        "QMessageBox QLabel {"
        "    color: black;"
        "    font-family: 'Franklin Gothic Heavy', 'Franklin Gothic', Arial, sans-serif;"
        "    font-weight: bold;"
        "}"
        "QMessageBox QPushButton {"
        "    background-color: #23B27A;"
        "    color: rgb(0, 85, 0);"
        "    border: none;"
        "    padding: 8px 20px;"
        "    border-radius: 4px;"
        "    font-family: 'Franklin Gothic Heavy', 'Franklin Gothic', Arial, sans-serif;"
        "    font-weight: bold;"
        "    min-width: 80px;"
        "}"
        "QMessageBox QPushButton:hover {"
        "    background-color: #1e9d6a;"
        "}"
        "QMessageBox QPushButton:pressed {"
        "    background-color: #1a8a5c;"
        "}"
    );
    
    msgBox->setStyleSheet(styleSheet);
    
    return msgBox;
}

void appar_modifier::chargerAppartement(QString idAppartement)
{
    currentId = idAppartement;
    
    Appartement appart;
    if (!appart.rechercher(idAppartement))
    {
        QMessageBox* msgBox = createStyledMessageBox(QMessageBox::Warning, "Erreur", "Impossible de charger les données de l'appartement.");
        msgBox->exec();
        msgBox->deleteLater();
        return;
    }
    
    ui->id->setText(appart.getId());
    ui->numtel->setText(appart.getNumTel());
    ui->numapp->setText(appart.getNumApp());
    ui->add->setText(appart.getAdresse());
    ui->ss->setText(appart.getNbrPieces());
    ui->prix->setText(QString::number(appart.getPrix()));
    
    QString etage = appart.getEtage();
    int index = ui->etage->findText(etage);
    if (index >= 0)
    {
        ui->etage->setCurrentIndex(index);
    }
    
    QString etat = appart.getEtat();
    if (etat == "Occupé")
    {
        ui->checkBox->setChecked(true);
    }
    else
    {
        ui->checkBox->setChecked(false);
    }
}

void appar_modifier::on_modifier_clicked()
{
    QString numtel = ui->numtel->text();
    QString numapp = ui->numapp->text();
    QString adresse = ui->add->text();
    QString etage = ui->etage->currentText();
    QString nbrPieces = ui->ss->text();
    QString prixText = ui->prix->text();
    
    if (numtel.isEmpty() || numapp.isEmpty() || adresse.isEmpty() || nbrPieces.isEmpty() || prixText.isEmpty())
    {
        QMessageBox* msgBox = createStyledMessageBox(QMessageBox::Warning, "Erreur", "Veuillez remplir tous les champs obligatoires.");
        msgBox->exec();
        msgBox->deleteLater();
        return;
    }
    
    if (etage == "Ajouter étage")
    {
        QMessageBox* msgBox = createStyledMessageBox(QMessageBox::Warning, "Erreur", "Veuillez sélectionner un étage.");
        msgBox->exec();
        msgBox->deleteLater();
        return;
    }
    
    bool prixOk;
    int prix = prixText.toInt(&prixOk);
    if (!prixOk)
    {
        QMessageBox* msgBox = createStyledMessageBox(QMessageBox::Warning, "Erreur", "Le prix doit être un nombre valide.");
        msgBox->exec();
        msgBox->deleteLater();
        return;
    }
    
    QString etat = ui->checkBox->isChecked() ? "Occupé" : "Disponible";
    
    Appartement appart;
    appart.setId(currentId);
    appart.setNumTel(numtel);
    appart.setNumApp(numapp);
    appart.setAdresse(adresse);
    appart.setEtage(etage);
    appart.setNbrPieces(nbrPieces);
    appart.setEtat(etat);
    appart.setPrix(prix);
    
    if (appart.modifier())
    {
        QMessageBox* msgBox = createStyledMessageBox(QMessageBox::Information, "Succès", "Appartement modifié avec succès.");
        msgBox->exec();
        msgBox->deleteLater();
        emit appartementModifie();
        this->close();
    }
    else
    {
        QMessageBox* msgBox = createStyledMessageBox(QMessageBox::Critical, "Erreur", "Erreur lors de la modification de l'appartement.");
        msgBox->exec();
        msgBox->deleteLater();
    }
}

void appar_modifier::on_annuler_clicked()
{
    this->close();
}
