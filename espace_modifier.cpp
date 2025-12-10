#include "espace_modifier.h"
#include "ui_espace_modifier.h"
#include "espace.h"
#include <QMessageBox>

espace_modifier::espace_modifier(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::espace_modifier)
{
    ui->setupUi(this);
    
    ui->nom->setReadOnly(true);
    
}

espace_modifier::~espace_modifier()
{
    delete ui;
}

void espace_modifier::chargerEspace(QString nomEspace)
{
    currentNom = nomEspace;
    
    Espace espace;
    if (!espace.rechercher(nomEspace))
    {
        QMessageBox::warning(this, "Erreur", "Impossible de charger les données de l'espace.");
        return;
    }

    ui->nom->setText(espace.getNom());
    ui->sup->setText(espace.getSup());
    ui->local->setText(espace.getLocal());
    ui->amen->setText(espace.getAmen());
    ui->equip->setText(espace.getEquip());
    ui->veg->setText(espace.getVeg());
    ui->sec->setText(espace.getSec());
    ui->prox->setText(espace.getProx());
    ui->frequ->setText(espace.getFrequ());
    
}

void espace_modifier::on_modifier_clicked()
{
    QString sup = ui->sup->text();
    QString local = ui->local->text();
    QString amen = ui->amen->text();
    QString equip = ui->equip->text();
    QString veg = ui->veg->text();
    QString sec = ui->sec->text();
    QString prox = ui->prox->text();
    QString frequ = ui->frequ->text();
    
    if (sup.isEmpty() || local.isEmpty() || amen.isEmpty() || equip.isEmpty() || veg.isEmpty() || sec.isEmpty() || prox.isEmpty() || frequ.isEmpty())
    {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs obligatoires.");
        return;
    }
    
    Espace espace;
    espace.setNom(currentNom);
    espace.setSup(sup);
    espace.setLocal(local);
    espace.setAmen(amen);
    espace.setEquip(equip);
    espace.setVeg(veg);
    espace.setSec(sec);
    espace.setProx(prox);
    espace.setFrequ(frequ);
    
    if (espace.modifier())
    {
        QMessageBox::information(this, "Succès", "Espace modifié avec succès.");
        emit espaceModifie();
        this->close();
    }
    else
    {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la modification de l'espace.");
    }
}

void espace_modifier::on_annuler_clicked()
{
    this->close();
}
