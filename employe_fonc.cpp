#include <QTextDocument>
#include <QPrinter>
#include <QFileDialog>
#include "employe_fonc.h"
#include "ui_employe_fonc.h"
#include "connection.h"
#include "employe.h"
#include "vehicule_inter.h"
#include "espace_inter.h"
#include "mate_inter.h"

#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QPixmap>
#include <QTableWidgetItem>
#include <QRegularExpression> // Pour la validation des champs
#include <QHeaderView>        // Pour l'ajustement du tableau

#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QChart>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>




employe_fonc::employe_fonc(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::employe_fonc)


{
    ui->setupUi(this);

    // AJOUT : Ajuster les colonnes pour qu'elles prennent tout l'espace disponible
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Connexion au clic du tableau
    connect(ui->tableWidget, &QTableWidget::clicked,
            this, &employe_fonc::on_tableWidget_clicked);

    // Appel initial pour afficher tous les employés au démarrage
    on_recherche_clicked();

    statistiquesSalaire();
}

employe_fonc::~employe_fonc()
{
    delete ui;
}

// Fonction utilitaire pour remplir le QTableWidget à partir du QSqlQueryModel
void employe_fonc::remplirTableau(QSqlQueryModel *model)
{
    ui->tableWidget->setRowCount(model->rowCount());
    ui->tableWidget->setColumnCount(model->columnCount());

    // Définir les en-têtes (récupérés du modèle)
    QStringList headers;
    for (int i = 0; i < model->columnCount(); ++i) {
        headers << model->headerData(i, Qt::Horizontal).toString();
    }
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    // Copier les données du modèle vers le QTableWidget
    for (int r = 0; r < model->rowCount(); ++r) {
        for (int c = 0; c < model->columnCount(); ++c) {
            ui->tableWidget->setItem(
                r, c,
                new QTableWidgetItem(model->data(model->index(r, c)).toString())
                );
        }
    }

    // ui->tableWidget->resizeColumnsToContents(); // Commenté car on utilise QHeaderView::Stretch
    delete model; // Libérer la mémoire du modèle
}


void employe_fonc::on_valider_clicked()
{
    // --- 1. Récupération des données ---
    QString id_str = ui->id->text();
    QString nom = ui->nom->text();
    QString prenom = ui->prenom->text();
    QString email = ui->mail->text();
    QString tel = ui->tel->text();
    QString poste = ui->poste->text();
    QString salaire_str = ui->salaire->text();

    // --- 2. Validation des champs vides ---
    if (id_str.isEmpty() || nom.isEmpty() || prenom.isEmpty() || email.isEmpty() ||
        tel.isEmpty() || poste.isEmpty() || salaire_str.isEmpty())
    {
        QMessageBox::warning(this, "Champs manquants",
                             "Veuillez remplir tous les champs.");
        return;
    }

    // --- 3. Validation Spécifique des Données ---

    // Validation ID (doit être un nombre entier positif)
    bool ok_id;
    int id = id_str.toInt(&ok_id);
    if (!ok_id || id <= 0) {
        QMessageBox::critical(this, "Erreur de saisie", "L'ID doit être un nombre entier positif.");
        return;
    }

    // Validation Nom et Prénom (doivent contenir uniquement des lettres, espaces, tirets)
    // Inclut les caractères accentués français
    QRegularExpression alpha_regex("^[a-zA-Zàâäéèêëîïôöùûüÿçñ'\\s-]+$");
    if (!alpha_regex.match(nom).hasMatch()) {
        QMessageBox::critical(this, "Erreur de saisie", "Le Nom ne doit contenir que des lettres et des espaces.");
        return;
    }
    if (!alpha_regex.match(prenom).hasMatch()) {
        QMessageBox::critical(this, "Erreur de saisie", "Le Prénom ne doit contenir que des lettres et des espaces.");
        return;
    }

    // Validation Email (format de base)
    QRegularExpression email_regex("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b", QRegularExpression::CaseInsensitiveOption);
    if (!email_regex.match(email).hasMatch()) {
        QMessageBox::critical(this, "Erreur de saisie", "Le format de l'Email est invalide.");
        return;
    }

    // Validation Téléphone (chiffres, espaces, tirets, parenthèses, et + pour l'indicatif)
    QRegularExpression tel_regex("^\\+?[0-9\\s\\-()]{8,20}$");
    if (!tel_regex.match(tel).hasMatch()) {
        QMessageBox::critical(this, "Erreur de saisie", "Le numéro de Téléphone est invalide.");
        return;
    }

    // Validation Salaire (doit être un nombre décimal positif)
    bool ok_salaire;
    double salaire = salaire_str.toDouble(&ok_salaire);
    if (!ok_salaire || salaire <= 0) {
        QMessageBox::critical(this, "Erreur de saisie", "Le Salaire doit être un nombre positif.");
        return;
    }

    // --- 4. Création de l'objet et Ajout ---
    Employe e(id, nom, prenom, email, tel, poste, salaire);

    if (e.ajouter()) {
        QMessageBox::information(this, "Succès", "Employé ajouté.");
        on_annuler_clicked();
        on_recherche_clicked(); // Rafraîchir le tableau
    } else {
        QMessageBox::critical(this, "Erreur", "ID existe déjà ou erreur d'insertion.");
    }
}

void employe_fonc::on_supprimer_clicked()
{
    if (ui->id2->text().isEmpty()) {
        QMessageBox::warning(this, "Erreur",
                             "Veuillez saisir un ID à supprimer.");
        return;
    }

    int id = ui->id2->text().toInt();

    if (QMessageBox::question(this, "Confirmation",
                              "Supprimer employé ID " + QString::number(id) + " ?")
        == QMessageBox::Yes)
    {
        Employe e;
        if (e.supprimer(id)) {
            QMessageBox::information(this, "Succès", "Employé supprimé");
            ui->id2->clear();
            on_recherche_clicked(); // Rafraîchir le tableau
        } else {
            QMessageBox::critical(this, "Erreur", "Suppression échouée.");
        }
    }
}

void employe_fonc::on_modifier_clicked()
{
    // --- 1. Récupération et Validation de l'ID de Modification ---
    QString id_str = ui->id2->text();

    if (id_str.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Sélectionnez un employé à modifier.");
        return;
    }

    bool ok_id;
    int id = id_str.toInt(&ok_id);
    if (!ok_id || id <= 0) {
        QMessageBox::critical(this, "Erreur de saisie", "L'ID de modification est invalide.");
        return;
    }

    // --- 2. Récupération et Validation des Nouveaux Champs ---
    QString nom = ui->nom->text();
    QString prenom = ui->prenom->text();
    QString email = ui->mail->text();
    QString tel = ui->tel->text();
    QString poste = ui->poste->text();
    QString salaire_str = ui->salaire->text();

    // Validation des champs vides
    if (nom.isEmpty() || prenom.isEmpty() || email.isEmpty() ||
        tel.isEmpty() || poste.isEmpty() || salaire_str.isEmpty())
    {
        QMessageBox::warning(this, "Champs manquants",
                             "Veuillez remplir tous les champs de modification.");
        return;
    }

    // Validation Nom et Prénom
    QRegularExpression alpha_regex("^[a-zA-Zàâäéèêëîïôöùûüÿçñ'\\s-]+$");
    if (!alpha_regex.match(nom).hasMatch() || !alpha_regex.match(prenom).hasMatch()) {
        QMessageBox::critical(this, "Erreur de saisie", "Le Nom et le Prénom ne doivent contenir que des lettres.");
        return;
    }

    // Validation Email
    QRegularExpression email_regex("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b", QRegularExpression::CaseInsensitiveOption);
    if (!email_regex.match(email).hasMatch()) {
        QMessageBox::critical(this, "Erreur de saisie", "Le format de l'Email est invalide.");
        return;
    }

    // Validation Salaire
    bool ok_salaire;
    double salaire = salaire_str.toDouble(&ok_salaire);
    if (!ok_salaire || salaire <= 0) {
        QMessageBox::critical(this, "Erreur de saisie", "Le Salaire doit être un nombre positif.");
        return;
    }

    // --- 3. Exécution de la Modification ---
    Employe e(id, nom, prenom, email, tel, poste, salaire);

    if (e.modifier(id)) {
        QMessageBox::information(this, "Succès", "Employé modifié.");
        on_recherche_clicked(); // Rafraîchir le tableau
    } else {
        QMessageBox::critical(this, "Erreur", "Modification échouée.");
    }
}

// Utilise la nouvelle fonction afficher() avec le filtre
void employe_fonc::on_recherche_clicked()
{
    QString idr = ui->idrech->text();
    Employe e;

    // Si le champ de recherche est vide, afficher tout. Sinon, filtrer par ID.
    QSqlQueryModel *model = e.afficher(idr);

    remplirTableau(model);
}

// Utilise la nouvelle fonction afficher() avec le tri
void employe_fonc::on_trier_clicked()
{
    QString tri = ui->tripar->currentText();
    QString colonneTri;

    if (tri == "Poste") {
        colonneTri = "POSTE";
    } else if (tri == "Salaire") {
        colonneTri = "SALAIRE DESC"; // Tri descendant pour le salaire
    } else {
        QMessageBox::warning(this, "Erreur de Tri", "Veuillez sélectionner un critère de tri valide.");
        return;
    }

    Employe e;
    QSqlQueryModel *model = e.afficher("", colonneTri);

    remplirTableau(model);
}

void employe_fonc::on_annuler_clicked()
{
    ui->id->clear();
    ui->nom->clear();
    ui->prenom->clear();
    ui->salaire->clear();
    ui->mail->clear();
    ui->tel->clear();
    ui->poste->clear();
    ui->idrech->clear();
    ui->id2->clear();
}

void employe_fonc::on_tableWidget_clicked(const QModelIndex &index)
{
    int row = index.row();

    ui->id->setText(ui->tableWidget->item(row, 0)->text());
    ui->nom->setText(ui->tableWidget->item(row, 1)->text());
    ui->prenom->setText(ui->tableWidget->item(row, 2)->text());
    ui->mail->setText(ui->tableWidget->item(row, 3)->text());
    ui->tel->setText(ui->tableWidget->item(row, 4)->text());
    ui->poste->setText(ui->tableWidget->item(row, 5)->text());
    ui->salaire->setText(ui->tableWidget->item(row, 6)->text());

    ui->id2->setText(ui->tableWidget->item(row, 0)->text());
}

void employe_fonc::on_export_2_clicked()
{
    // 1. Ouvrir une boîte de dialogue pour choisir le nom du fichier
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", QString(), "*.pdf");
    if (fileName.isEmpty())
        return;

    // 2. Préparer le document PDF
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPageSize(QPageSize::A4); // CORRECTION DE setPaperSize -> setPageSize
    printer.setOutputFileName(fileName);

    QTextDocument doc;
    QString html = "<h1>Liste des Employés</h1> ";

    // 3. Récupérer les données du tableau
    int rowCount = ui->tableWidget->rowCount(); // Déclaration explicite
    int colCount = ui->tableWidget->columnCount(); // Déclaration explicite

    // Créer la structure HTML du tableau
    html += "<table border=1 cellspacing=0 cellpadding=5>";

    // En-têtes
    html += "<thead><tr>";
    for (int c = 0; c < colCount; c++) {
        html += "<th>" + ui->tableWidget->horizontalHeaderItem(c)->text() + "</th>";
    }
    html += "</tr></thead>";

    // Corps du tableau
    html += "<tbody>";
    for (int r = 0; r < rowCount; r++) {
        html += "<tr>";
        for (int c = 0; c < colCount; c++) {
            QTableWidgetItem *item = ui->tableWidget->item(r, c);
            html += "<td>" + (item ? item->text() : "") + "</td>";
        }
        html += "</tr>";
    }
    html += "</tbody></table>";

    // 4. Écrire le HTML dans le document et imprimer
    doc.setHtml(html);
    doc.print(&printer);

    QMessageBox::information(this, "Exportation PDF", "Le tableau a été exporté avec succès vers : " + fileName);
}

void employe_fonc::statistiquesSalaire()
{
    QSqlQuery query("SELECT salaire, nom FROM employe ORDER BY salaire DESC");

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur SQL", query.lastError().text());
        return;
    }

    QBarSet *set = new QBarSet("Salaires");
    QStringList categories;

    while (query.next()) {
        *set << query.value("salaire").toDouble();
        categories << query.value("nom").toString();  // Pour mettre le nom sur l'axe X
    }

    QBarSeries *series = new QBarSeries();
    series->append(set);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques des salaires");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);

    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Salaire (DT)");

    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // --- Ajouter au layout déjà existant ---
    ui->Layout->addWidget(chartView);
}

void employe_fonc::on_ges_appar_clicked()
{
    hide();
    parentWidget()->show();
}

void employe_fonc::on_ges_vehic_clicked()
{
    hide();
    vehiculeWindow = new vehicule_inter(this);
    vehiculeWindow->show();
}

void employe_fonc::on_ges_es_vert_clicked()
{
    hide();
    espaceWindow = new espace_inter(this);
    espaceWindow->show();
}

void employe_fonc::on_ges_mat_clicked()
{
    hide();
    materielWindow = new mate_inter(this);
    materielWindow->show();
}
