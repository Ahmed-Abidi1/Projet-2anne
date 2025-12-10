#include "mate_inter.h"
#include "ui_mate_inter.h"
#include "vehicule_inter.h"
#include "espace_inter.h"
#include "employe_inter.h"
#include "materiel.h"
#include <QMessageBox>
#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QDateTime>
#include <QPrinter>
#include <QPainter>
#include <QTextDocument>
#include <QFileDialog>
#include <QSqlQuery>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QProgressBar>
#include <QRandomGenerator>


mate_inter::mate_inter(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::mate_inter)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/samar/OneDrive/Bureau/projet C++/logo.png");
    ui->logo->setPixmap(pix.scaled(90,90,Qt::KeepAspectRatio));

    employeWindow = nullptr;
    vehiculeWindow = nullptr;
    espaceWindow = nullptr;
    materielfonc = new mate_fonc(this);

    // Initialize table with headers but no data
    QStringList headers;
    headers << "Code Barre" << "Nom" << "Type" << "Etat" << "Quantité";
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->setRowCount(0); // Start with empty table

    // Connect functionality buttons
    connect(ui->valider, &QPushButton::clicked, this, &mate_inter::on_valider_clicked);
    connect(ui->annuler, &QPushButton::clicked, this, &mate_inter::on_annuler_clicked);
    connect(ui->recherche, &QPushButton::clicked, this, &mate_inter::on_recherche_clicked);
    connect(ui->trier, &QPushButton::clicked, this, &mate_inter::on_trier_clicked);
    connect(ui->supprimer, &QPushButton::clicked, this, &mate_inter::on_supprimer_clicked);
    connect(ui->modifier, &QPushButton::clicked, this, &mate_inter::on_modifier_clicked);
    connect(ui->exportToPDF, &QPushButton::clicked, this, &mate_inter::on_exportToPDF_clicked);
}

mate_inter::~mate_inter()
{
    delete ui;
}

void mate_inter::on_fonction_clicked()
{
    hide();
    if (materielfonc) {
        materielfonc->show();
    }
}

void mate_inter::on_ges_appar_clicked()
{
    hide();
    parentWidget()->show();
}

void mate_inter::on_ges_vehic_clicked()
{
    hide();
    vehiculeWindow = new vehicule_inter(this);
    vehiculeWindow->show();
}

void mate_inter::on_ges_es_vert_clicked()
{
    hide();
    espaceWindow = new espace_inter(this);
    espaceWindow->show();
}

void mate_inter::on_ges_emp_clicked()
{
    hide();
    employeWindow = new employe_inter(this);
    employeWindow->show();
}

bool mate_inter::containsOnlyLettersAndSpaces(const QString &str)
{
    if (str.isEmpty()) return true;
    QRegularExpression regex("^[a-zA-Z\\sÀ-ÿ]+$");
    return regex.match(str).hasMatch();
}

bool mate_inter::containsOnlyLettersAndNumbers(const QString &str)
{
    if (str.isEmpty()) return true;
    QRegularExpression regex("^[a-zA-Z0-9]+$");
    return regex.match(str).hasMatch();
}

bool mate_inter::containsOnlyNumbers(const QString &str)
{
    if (str.isEmpty()) return true;
    QRegularExpression regex("^[0-9]+$");
    return regex.match(str).hasMatch();
}

bool mate_inter::validateInputs()
{
    // For modification: get code_barre from idmodsup field
    QString code_barre = ui->idmodsup->text().trimmed();
    QString nom = ui->id->text().trimmed();
    QString type = ui->numtel->text().trimmed();
    QString etat = ui->numapp->text().trimmed();
    QString qtiteText = ui->add->text().trimmed();

    // Check required fields for modification
    if (code_barre.isEmpty()) {
        QMessageBox::warning(this, "Champs obligatoires",
                             "Le code barre est obligatoire pour la modification!");
        return false;
    }

    // Validate code barre (letters and numbers only)
    if (!containsOnlyLettersAndNumbers(code_barre)) {
        QMessageBox::warning(this, "Erreur de saisie",
                             "Le code barre ne doit contenir que des lettres et des chiffres!");
        return false;
    }

    if (code_barre.length() > 100) {
        QMessageBox::warning(this, "Erreur", "Le code barre est trop long (max 100 caractères)!");
        return false;
    }

    // Validate nom (letters and spaces only) - only if provided
    if (!nom.isEmpty() && !containsOnlyLettersAndSpaces(nom)) {
        QMessageBox::warning(this, "Erreur de saisie",
                             "Le nom ne doit contenir que des lettres et des espaces!");
        return false;
    }

    if (!nom.isEmpty() && nom.length() > 100) {
        QMessageBox::warning(this, "Erreur", "Le nom est trop long (max 100 caractères)!");
        return false;
    }

    // Validate type (letters and numbers only)
    if (!type.isEmpty() && !containsOnlyLettersAndNumbers(type)) {
        QMessageBox::warning(this, "Erreur de saisie",
                             "Le type ne doit contenir que des lettres et des chiffres!");
        return false;
    }

    if (type.length() > 100) {
        QMessageBox::warning(this, "Erreur", "Le type est trop long (max 100 caractères)!");
        return false;
    }

    // Validate etat (letters and spaces only)
    if (!etat.isEmpty() && !containsOnlyLettersAndSpaces(etat)) {
        QMessageBox::warning(this, "Erreur de saisie",
                             "L'état ne doit contenir que des lettres et des espaces!");
        return false;
    }

    if (etat.length() > 50) {
        QMessageBox::warning(this, "Erreur", "L'état est trop long (max 50 caractères)!");
        return false;
    }

    // Validate qtite (numbers only) - only if provided
    if (!qtiteText.isEmpty() && !containsOnlyNumbers(qtiteText)) {
        QMessageBox::warning(this, "Erreur de saisie", "La quantité doit contenir uniquement des chiffres!");
        return false;
    }

    if (!qtiteText.isEmpty()) {
        bool ok;
        int qtite = qtiteText.toInt(&ok);
        if (!ok || qtite < 0) {
            QMessageBox::warning(this, "Erreur de saisie", "La quantité doit être un nombre positif!");
            return false;
        }
    }

    return true;
}

bool mate_inter::validateInputsForAdd()
{
    // For adding: no code_barre needed, it will be generated
    QString nom = ui->id->text().trimmed();
    QString type = ui->numtel->text().trimmed();
    QString etat = ui->numapp->text().trimmed();
    QString qtiteText = ui->add->text().trimmed();

    // Check required fields
    if (nom.isEmpty()) {
        QMessageBox::warning(this, "Champs obligatoires",
                             "Le nom est obligatoire!");
        return false;
    }

    // Validate nom (letters and spaces only)
    if (!containsOnlyLettersAndSpaces(nom)) {
        QMessageBox::warning(this, "Erreur de saisie",
                             "Le nom ne doit contenir que des lettres et des espaces!");
        return false;
    }

    if (nom.length() > 100) {
        QMessageBox::warning(this, "Erreur", "Le nom est trop long (max 100 caractères)!");
        return false;
    }

    // Validate type (letters and numbers only)
    if (!type.isEmpty() && !containsOnlyLettersAndNumbers(type)) {
        QMessageBox::warning(this, "Erreur de saisie",
                             "Le type ne doit contenir que des lettres et des chiffres!");
        return false;
    }

    if (type.length() > 100) {
        QMessageBox::warning(this, "Erreur", "Le type est trop long (max 100 caractères)!");
        return false;
    }

    // Validate etat (letters and spaces only)
    if (!etat.isEmpty() && !containsOnlyLettersAndSpaces(etat)) {
        QMessageBox::warning(this, "Erreur de saisie",
                             "L'état ne doit contenir que des lettres et des espaces!");
        return false;
    }

    if (etat.length() > 50) {
        QMessageBox::warning(this, "Erreur", "L'état est trop long (max 50 caractères)!");
        return false;
    }

    // Validate qtite (numbers only)
    if (!qtiteText.isEmpty() && !containsOnlyNumbers(qtiteText)) {
        QMessageBox::warning(this, "Erreur de saisie", "La quantité doit contenir uniquement des chiffres!");
        return false;
    }

    bool ok;
    int qtite = qtiteText.isEmpty() ? 0 : qtiteText.toInt(&ok);
    if (!ok || qtite < 0) {
        QMessageBox::warning(this, "Erreur de saisie", "La quantité doit être un nombre positif!");
        return false;
    }

    return true;
}

QString mate_inter::generateBarcode()
{
    // Generate a unique barcode using timestamp and random number
    QString timestamp = QDateTime::currentDateTime().toString("yyyyMMddhhmmss");
    int randomNum = QRandomGenerator::global()->bounded(100000, 999999);
    return QString("MAT-%1-%2").arg(randomNum).arg(timestamp);
}

void mate_inter::on_valider_clicked()
{
    qDebug() << "=== VALIDER CLICKED ===";

    // Validate inputs for adding (no barcode needed)
    if (!validateInputsForAdd()) {
        qDebug() << "Validation failed";
        return;
    }

    qDebug() << "Validation passed, proceeding with addition";

    QString nom = ui->id->text().trimmed();
    QString type = ui->numtel->text().trimmed();
    QString etat = ui->numapp->text().trimmed();
    int qtite = ui->add->text().toInt();

    // Generate barcode automatically
    QString code_barre = generateBarcode();

    Materiel m(code_barre, nom, type, etat, qtite);
    bool test = m.ajouter();

    if (test) {
        qDebug() << "Material added successfully";
        QMessageBox::information(this, "Succès",
                                 QString("Matériel ajouté avec succès!\nCode barre généré: %1").arg(code_barre));
        clearAddFields();

        QString notification = QString("Matériel ajouté - Code: %1, Nom: %2, Type: %3, État: %4, Quantité: %5")
                                   .arg(code_barre)
                                   .arg(nom)
                                   .arg(type)
                                   .arg(etat)
                                   .arg(qtite);
        addNotification(notification);

        return;
    } else {
        qDebug() << "Failed to add material";
        QMessageBox::critical(this, "Erreur",
                              "Erreur lors de l'ajout du matériel!\n"
                              "Vérifiez que le code barre n'existe pas déjà.");
    }
}

void mate_inter::on_annuler_clicked()
{
    clearAddFields();
}

void mate_inter::on_recherche_clicked()
{
    QString code_barre = ui->idrech->text().trimmed();
    Materiel m;

    if (code_barre.isEmpty()) {
        ui->tableWidget->setRowCount(0);
        QMessageBox::information(this, "Recherche", "Veuillez saisir un code barre pour rechercher.");
    } else {
        m.rechercher(ui->tableWidget, code_barre);

        if (ui->tableWidget->rowCount() == 0) {
            QMessageBox::information(this, "Recherche",
                                     "Aucun matériel trouvé avec le code barre: " + code_barre);
        }
    }
}

void mate_inter::on_trier_clicked()
{
    QString critere = ui->tripar->currentText();
    Materiel m;
    m.trier(ui->tableWidget, critere);

    if (ui->tableWidget->rowCount() == 0) {
        QMessageBox::information(this, "Tri", "Aucun matériel à trier.");
    }
}

void mate_inter::on_supprimer_clicked()
{
    QString code_barre = ui->idmodsup->text().trimmed();

    if (code_barre.isEmpty()) {
        QMessageBox::warning(this, "Champ vide", "Veuillez saisir un code barre!");
        return;
    }

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation",
                                  "Voulez-vous vraiment supprimer le matériel avec le code barre:\n"
                                      + code_barre + "?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        Materiel m;
        bool test = m.supprimer(code_barre);

        if (test) {
            QMessageBox::information(this, "Succès", "Matériel supprimé avec succès!");
            ui->idmodsup->clear();
            addNotification(QString("Matériel supprimé - Code barre: %1").arg(code_barre));
        } else {
            QMessageBox::critical(this, "Erreur", "Erreur lors de la suppression!\nMatériel non trouvé.");
        }
    }
}

void mate_inter::on_modifier_clicked()
{
    qDebug() << "=== MODIFIER CLICKED ===";

    QString code_barre = ui->idmodsup->text().trimmed();

    if (code_barre.isEmpty()) {
        QMessageBox::warning(this, "Champ vide", "Veuillez saisir un code barre!");
        return;
    }

    // Check if the material exists
    Materiel m_check;
    if (!m_check.existe(code_barre)) {
        QMessageBox::warning(this, "Non trouvé", "Aucun matériel trouvé avec ce code barre!");
        return;
    }

    // Get the new data from input fields
    QString new_nom = ui->id->text().trimmed();
    QString new_type = ui->numtel->text().trimmed();
    QString new_etat = ui->numapp->text().trimmed();
    QString new_qtiteText = ui->add->text().trimmed();

    // Check if at least one field is filled for modification
    if (new_nom.isEmpty() && new_type.isEmpty() && new_etat.isEmpty() && new_qtiteText.isEmpty()) {
        QMessageBox::warning(this, "Aucune modification",
                             "Veuillez saisir au moins un champ à modifier!");
        return;
    }

    // Validate only the fields that are not empty
    if (!new_nom.isEmpty()) {
        if (!containsOnlyLettersAndSpaces(new_nom)) {
            QMessageBox::warning(this, "Erreur de saisie", "Le nom ne doit contenir que des lettres et des espaces!");
            return;
        }
        if (new_nom.length() > 100) {
            QMessageBox::warning(this, "Erreur", "Le nom est trop long (max 100 caractères)!");
            return;
        }
    }

    if (!new_type.isEmpty()) {
        if (!containsOnlyLettersAndNumbers(new_type)) {
            QMessageBox::warning(this, "Erreur de saisie", "Le type ne doit contenir que des lettres et des chiffres!");
            return;
        }
        if (new_type.length() > 100) {
            QMessageBox::warning(this, "Erreur", "Le type est trop long (max 100 caractères)!");
            return;
        }
    }

    if (!new_etat.isEmpty()) {
        if (!containsOnlyLettersAndSpaces(new_etat)) {
            QMessageBox::warning(this, "Erreur de saisie", "L'état ne doit contenir que des lettres et des espaces!");
            return;
        }
        if (new_etat.length() > 50) {
            QMessageBox::warning(this, "Erreur", "L'état est trop long (max 50 caractères)!");
            return;
        }
    }

    if (!new_qtiteText.isEmpty()) {
        if (!containsOnlyNumbers(new_qtiteText)) {
            QMessageBox::warning(this, "Erreur de saisie", "La quantité doit contenir uniquement des chiffres!");
            return;
        }

        bool ok;
        int new_qtite = new_qtiteText.toInt(&ok);
        if (!ok || new_qtite < 0) {
            QMessageBox::warning(this, "Erreur de saisie", "La quantité doit être un nombre positif!");
            return;
        }
    }

    // Prepare confirmation message with only the fields that will be changed
    QString confirmationMessage = "Voulez-vous vraiment modifier le matériel avec le code barre:\n" + code_barre + "?\n\n";
    QString changesMessage = "Changements:\n";

    if (!new_nom.isEmpty()) changesMessage += "Nom: " + new_nom + "\n";
    if (!new_type.isEmpty()) changesMessage += "Type: " + new_type + "\n";
    if (!new_etat.isEmpty()) changesMessage += "État: " + new_etat + "\n";
    if (!new_qtiteText.isEmpty()) changesMessage += "Quantité: " + new_qtiteText + "\n";

    if (changesMessage == "Changements:\n") {
        changesMessage = "Aucun changement spécifié";
    }

    confirmationMessage += changesMessage;

    // Ask for confirmation
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation de modification",
                                  confirmationMessage,
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        qDebug() << "Proceeding with modification";

        // Create Materiel object with the data that will be changed
        QString final_nom = new_nom.isEmpty() ? "" : new_nom;
        QString final_type = new_type.isEmpty() ? "" : new_type;
        QString final_etat = new_etat.isEmpty() ? "" : new_etat;
        int final_qtite = new_qtiteText.isEmpty() ? 0 : new_qtiteText.toInt();

        Materiel m(code_barre, final_nom, final_type, final_etat, final_qtite);
        bool test = m.modifier(code_barre);

        if (test) {
            qDebug() << "Material modified successfully";
            QMessageBox::information(this, "Succès", "Matériel modifié avec succès!");
            clearAddFields();
            ui->idmodsup->clear();

            QString notificationMessage = "Matériel modifié - Code: " + code_barre;
            if (!new_nom.isEmpty()) notificationMessage += ", Nouveau nom: " + new_nom;
            if (!new_type.isEmpty()) notificationMessage += ", Type: " + new_type;
            if (!new_etat.isEmpty()) notificationMessage += ", État: " + new_etat;
            if (!new_qtiteText.isEmpty()) notificationMessage += ", Quantité: " + new_qtiteText;

            addNotification(notificationMessage);
        } else {
            qDebug() << "Failed to modify material";
            QMessageBox::critical(this, "Erreur", "Erreur lors de la modification du matériel!");
        }
    }
}

void mate_inter::clearAddFields()
{
    ui->id->clear();
    ui->numtel->clear();
    ui->numapp->clear();
    ui->add->clear();
}

void mate_inter::refreshTable()
{
    Materiel m;
    m.afficher(ui->tableWidget);
}

void mate_inter::addNotification(const QString &message)
{
    if (materielfonc) {
        materielfonc->addNotification(message);
    } else {
        qWarning() << "mate_fonc window not initialized. Notification skipped:" << message;
    }
}

void mate_inter::on_exportToPDF_clicked()
{
    // Get all materials from database
    QSqlQuery query;
    QString queryStr = "SELECT CODE_BARRE, NOM_MATR, TYPE_MAT, ETAT, QTITE FROM MATERIEL ORDER BY NOM_MATR";

    if (!query.exec(queryStr)) {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la récupération des données: " + query.lastError().text());
        return;
    }

    QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", "liste_materiels.pdf", "Fichiers PDF (*.pdf)");
    if (fileName.isEmpty()) return;

    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    printer.setPageSize(QPageSize(QPageSize::A4));

    QPainter painter;
    if (!painter.begin(&printer)) {
        QMessageBox::critical(this, "Erreur", "Impossible de créer le PDF");
        return;
    }

    // Simple fonts
    QFont titleFont("Arial", 16, QFont::Bold);
    QFont headerFont("Arial", 10, QFont::Bold);
    QFont dataFont("Arial", 9);

    int y = 100;
    int rowHeight = 25;
    int colSpacing = 15;

    // Column positions
    int col1 = 50;   // Code Barre
    int col2 = 200;  // Nom
    int col3 = 350;  // Type
    int col4 = 500;  // Etat
    int col5 = 650;  // Quantité

    // Title
    painter.setFont(titleFont);
    painter.drawText(50, y, "LISTE DES MATÉRIELS");
    y += 50;

    // Headers with underline
    painter.setFont(headerFont);
    painter.drawText(col1, y, "CODE BARRE");
    painter.drawText(col2, y, "NOM");
    painter.drawText(col3, y, "TYPE");
    painter.drawText(col4, y, "ETAT");
    painter.drawText(col5, y, "QUANTITE");

    // Draw line under headers
    y += 10;
    painter.drawLine(50, y, 750, y);
    y += 20;

    // Data rows
    painter.setFont(dataFont);
    int rowCount = 0;

    while (query.next()) {
        // Check for page break
        if (y > 700) {
            printer.newPage();
            y = 100;

            // Redraw headers on new page
            painter.setFont(headerFont);
            painter.drawText(col1, y, "CODE BARRE");
            painter.drawText(col2, y, "NOM");
            painter.drawText(col3, y, "TYPE");
            painter.drawText(col4, y, "ETAT");
            painter.drawText(col5, y, "QUANTITE");

            y += 30;
            painter.setFont(dataFont);
        }

        // Draw row data
        painter.drawText(col1, y, query.value(0).toString());
        painter.drawText(col2, y, query.value(1).toString());
        painter.drawText(col3, y, query.value(2).toString());
        painter.drawText(col4, y, query.value(3).toString());
        painter.drawText(col5, y, query.value(4).toString());

        y += rowHeight;
        rowCount++;
    }

    // Footer with total
    y += 20;
    painter.setFont(headerFont);
    painter.drawText(50, y, QString("Total: %1 matériel(s)").arg(rowCount));

    painter.end();

    // Notification
    addNotification(QString("Export PDF - %1 matériels").arg(rowCount));
    QMessageBox::information(this, "Succès", QString("PDF créé: %1 matériels exportés").arg(rowCount));
}
