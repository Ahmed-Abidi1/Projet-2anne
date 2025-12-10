#include "espace_inter.h"
#include "ui_espace_inter.h"
#include "vehicule_inter.h"
#include "mate_inter.h"
#include "employe_inter.h"
#include "espace.h"
#include <QMessageBox>
#include <QSqlError>
#include <algorithm>
#include <QPrinter>
#include <QTextDocument>
#include <QFileDialog>
#include <QTextTable>
#include <QTextCursor>
#include <QTextTableFormat>
#include <QTextFrameFormat>
#include <QFont>
#include <QColor>
#include <QPageSize>

espace_inter::espace_inter(QWidget *parent)
    : QDialog(parent), ui(new Ui::espace_inter),
    modifierWindow(nullptr), employeWindow(nullptr)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/samar/OneDrive/Bureau/projet C++/logo.png");
    ui->logo->setPixmap(pix.scaled(90, 90, Qt::KeepAspectRatio));
}

espace_inter::~espace_inter()
{
    delete ui;
}

void espace_inter::on_pushButton_2_clicked()
{
    hide();
    espaceFonc = new Espace_fonc(this);
    espaceFonc->show();
}

void espace_inter::on_ges_appar_clicked()
{
    hide();
    parentWidget()->show();
}

void espace_inter::on_ges_vehic_clicked()
{
    hide();
    vehiculeWindow = new vehicule_inter(this);
    vehiculeWindow->show();
}

void espace_inter::on_ges_mat_clicked()
{
    hide();
    materielWindow = new mate_inter(this);
    materielWindow->show();
}

void espace_inter::on_ges_emp_clicked()
{
    hide();
    employeWindow = new employe_inter(this);
    employeWindow->show();
}

void espace_inter::on_fonction_clicked()
{
    hide();
    espaceFonc = new Espace_fonc(this);
    espaceFonc->show();
}

void espace_inter::on_ges_es_vert_clicked()
{
    hide();
    parentWidget()->show();
}

void espace_inter::on_valider_clicked()
{
    QString nom = ui->nom->text();
    QString sup = ui->sup->text();
    QString local = ui->local->text();
    QString amen = ui->amen->text();
    QString equip = ui->equip->text();

    Espace espace(nom, sup, local, amen, equip, "", "", "", "");

    if (!espace.estValide()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs obligatoires.");
        return;
    }

    if (espace.ajouter()) {
        QMessageBox::information(this, "Succès", "Espace ajouté avec succès à la base de données.");
        on_annuler_clicked();
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de l'ajout de l'espace.\nVérifiez que l'ID n'existe pas déjà.");
    }
}

void espace_inter::on_annuler_clicked()
{
    ui->nom->clear();
    ui->sup->clear();
    ui->local->clear();
    ui->amen->clear();
    ui->equip->clear();
}

void espace_inter::on_recherche_clicked()
{
    QString critere = ui->repar->currentText();
    QString valeurRecherche = ui->rech->text().trimmed();
    QList<Espace> espaces;

    if (critere == "Aucun")
    {
        espaces = Espace::rechercherTous();
    }
    else if (critere == "Superficie")
    {
        if (valeurRecherche.isEmpty())
        {
            espaces = Espace::rechercherTous();
        }
        else
        {
            espaces = Espace::rechercherParSuperficie(valeurRecherche);
        }
    }
    else if (critere == "Végétation")
    {
        if (valeurRecherche.isEmpty())
        {
            espaces = Espace::rechercherTous();
        }
        else
        {
            espaces = Espace::rechercherParVegetation(valeurRecherche);
        }
    }
    else if (critere == "Sécurité")
    {
        if (valeurRecherche.isEmpty())
        {
            espaces = Espace::rechercherTous();
        }
        else
        {
            espaces = Espace::rechercherParSecurite(valeurRecherche);
        }
    }
    else
    {
        espaces = Espace::rechercherTous();
    }

    currentEspaces = espaces;

    afficherEspaces(espaces);
}

void espace_inter::on_trier_clicked()
{
    QString critere = ui->tripar->currentText();

    if (currentEspaces.isEmpty()) {
        currentEspaces = Espace::rechercherTous();
    }

    if (critere == "Superficie") {
        std::sort(currentEspaces.begin(), currentEspaces.end(),
                  [](const Espace &a, const Espace &b) { return a.getSup() < b.getSup(); });
    } else if (critere == "Végétation") {
        std::sort(currentEspaces.begin(), currentEspaces.end(),
                  [](const Espace &a, const Espace &b) { return a.getVeg() < b.getVeg(); });
    } else if (critere == "Sécurité") {
        std::sort(currentEspaces.begin(), currentEspaces.end(),
                  [](const Espace &a, const Espace &b) { return a.getSec() < b.getSec(); });
    }

    afficherEspaces(currentEspaces);
}

void espace_inter::afficherEspaces(const QList<Espace>& espaces)
{
    ui->res->setRowCount(0);
    ui->res->setRowCount(espaces.size());

    for (int i = 0; i < espaces.size(); ++i)
    {
        const Espace& app = espaces[i];
        ui->res->setItem(i, 0, new QTableWidgetItem(app.getNom()));
        ui->res->setItem(i, 1, new QTableWidgetItem(app.getSup()));
        ui->res->setItem(i, 2, new QTableWidgetItem(app.getLocal()));
        ui->res->setItem(i, 3, new QTableWidgetItem(app.getAmen()));
        ui->res->setItem(i, 4, new QTableWidgetItem(app.getEquip()));
        ui->res->setItem(i, 5, new QTableWidgetItem(app.getVeg()));
        ui->res->setItem(i, 6, new QTableWidgetItem(app.getSec()));
        ui->res->setItem(i, 7, new QTableWidgetItem(app.getProx()));
        ui->res->setItem(i, 8, new QTableWidgetItem(app.getFrequ()));
    }

    ui->res->resizeColumnsToContents();
}

void espace_inter::on_supprimer_clicked()
{
    QString nomEspace = ui->nommodsup->text().trimmed();

    if (nomEspace.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un nom d'espace.");
        return;
    }

    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation",
                                                              "Êtes-vous sûr de vouloir supprimer l'espace avec le nom: " + nomEspace + "?",
                                                              QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        Espace espace;
        if (espace.supprimer(nomEspace)) {
            QMessageBox::information(this, "Succès", "Espace supprimé avec succès.");
            ui->nommodsup->clear();
            if (!currentEspaces.isEmpty()) {
                on_recherche_clicked();
            }
        } else {
            QMessageBox::critical(this, "Erreur", "Erreur lors de la suppression.\nL'espace avec ce nom n'existe peut-être pas.");
        }
    }
}

void espace_inter::on_modifier_clicked()
{
    QString nomEspace = ui->nommodsup->text().trimmed();

    if (nomEspace.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un nom d'espace.");
        return;
    }

    Espace espace;
    if (!espace.rechercher(nomEspace)) {
        QMessageBox::warning(this, "Erreur", "Espace avec ce nom n'existe pas.");
        return;
    }

    if (modifierWindow == nullptr) {
        modifierWindow = new espace_modifier(this);
        connect(modifierWindow, &espace_modifier::espaceModifie, this, [this]() {
            if (!currentEspaces.isEmpty()) {
                on_recherche_clicked();
            }
        });
    }

    modifierWindow->chargerEspace(nomEspace);
    modifierWindow->show();
    modifierWindow->raise();
    modifierWindow->activateWindow();
}

void espace_inter::on_pdf_clicked()
{
    QList<Espace> espaces = Espace::rechercherTous();

    if (espaces.isEmpty()) {
        QMessageBox::information(this, "Export PDF", "Aucun espace à exporter.");
        return;
    }

    QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", "", "Fichiers PDF (*.pdf)");

    if (fileName.isEmpty()) {
        return;
    }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPageSize(QPageSize(QPageSize::A4));
    printer.setOutputFileName(fileName);

    QTextDocument document;
    QTextCursor cursor(&document);

    QTextCharFormat titleFormat;
    titleFormat.setFontPointSize(16);
    titleFormat.setFontWeight(QFont::Bold);
    cursor.setCharFormat(titleFormat);
    cursor.insertText("Liste des Espaces\n\n");

    QTextTableFormat tableFormat;
    tableFormat.setAlignment(Qt::AlignCenter);
    tableFormat.setCellPadding(5);
    tableFormat.setCellSpacing(0);
    tableFormat.setBorder(1);
    tableFormat.setBorderStyle(QTextFrameFormat::BorderStyle_Solid);

    QTextTable *table = cursor.insertTable(espaces.size() + 1, 9, tableFormat);

    QTextCharFormat headerFormat;
    headerFormat.setFontWeight(QFont::Bold);
    headerFormat.setBackground(QColor("#E0E0E0"));

    QStringList headers = {"Nom", "Superficie", "Localisation", "Aménagement", "Équipement", "Végétation", "Sécurité", "Proximité", "Fréquentation"};
    for (int i = 0; i < headers.size(); ++i) {
        QTextTableCell cell = table->cellAt(0, i);
        cell.setFormat(headerFormat);
        cell.firstCursorPosition().insertText(headers[i]);
    }

    for (int i = 0; i < espaces.size(); ++i) {
        const Espace &esp = espaces[i];
        table->cellAt(i + 1, 0).firstCursorPosition().insertText(esp.getNom());
        table->cellAt(i + 1, 1).firstCursorPosition().insertText(esp.getSup());
        table->cellAt(i + 1, 2).firstCursorPosition().insertText(esp.getLocal());
        table->cellAt(i + 1, 3).firstCursorPosition().insertText(esp.getAmen());
        table->cellAt(i + 1, 4).firstCursorPosition().insertText(esp.getEquip());
        table->cellAt(i + 1, 5).firstCursorPosition().insertText(esp.getVeg());
        table->cellAt(i + 1, 6).firstCursorPosition().insertText(esp.getSec());
        table->cellAt(i + 1, 7).firstCursorPosition().insertText(esp.getProx());
        table->cellAt(i + 1, 8).firstCursorPosition().insertText(esp.getFrequ());
    }

    document.print(&printer);

    QMessageBox::information(this, "Export PDF", "Les données ont été exportées avec succès vers :\n" + fileName);
}
