#include "vehicule_inter.h"
#include "ui_vehicule_inter.h"
#include "espace_inter.h"
#include "employe_inter.h"

#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QRegularExpression>
#include <QSqlQueryModel>
#include <QAbstractItemModel>
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
#include <QPushButton>
#include <QLabel>

vehicule_inter::vehicule_inter(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::vehicule_inter)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/samar/OneDrive/Bureau/projet C++/logo.png");
    ui->logo->setPixmap(pix.scaled(90,90,Qt::KeepAspectRatio));
    
    connect(ui->tableWidgetv, &QTableWidget::itemClicked,
        this, &vehicule_inter::on_tableWidgetv_itemClicked);


    employeWindow = nullptr;
    loadEmployesCombo();
    refreshTable();

}

vehicule_inter::~vehicule_inter()
{
    delete ui;
}

void vehicule_inter::on_fonction_clicked()
{
    hide();
    vehiculefonc = new vehicule_fonc(this);
    vehiculefonc->show();
}


void vehicule_inter::on_ges_appar_clicked()
{
    hide();
    parentWidget()->show();
}


void vehicule_inter::on_ges_es_vert_clicked()
{
    hide();
    espaceWindow = new espace_inter(this);
    espaceWindow->show();
}


void vehicule_inter::on_ges_mat_clicked()
{
    hide();
    materielWindow = new mate_inter(this);
    materielWindow->show();
}

void vehicule_inter::on_ges_emp_clicked()
{
    hide();
    employeWindow = new employe_inter(this);
    employeWindow->show();
}

void vehicule_inter::loadEmployesCombo()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT ID_EMPLOYE FROM EMPLOYE ORDER BY ID_EMPLOYE");

    if (model->lastError().isValid()) {
        qDebug() << "ERREUR MODÈLE:" << model->lastError().text();
        QMessageBox::critical(this, "Erreur", "Impossible de charger les employés: " + model->lastError().text());
        return;
    }

    ui->comboBoxid->setModel(model);
    ui->comboBoxid->setModelColumn(0);

    qDebug() << "Employés chargés dans comboBox:" << model->rowCount();
}

// ===================================================================
// RAFRAÎCHIR LE TABLEAU
// ===================================================================
void vehicule_inter::refreshTable()
{
    ui->tableWidgetv->clearContents();
    ui->tableWidgetv->setRowCount(0);

    QStringList headers = {
        "ID", "Num Série", "Localisation", "Type",
        "Marque", "Modèle", "Propriétaire", "ID Employé"
    };
    ui->tableWidgetv->setColumnCount(8);
    ui->tableWidgetv->setHorizontalHeaderLabels(headers);
    ui->tableWidgetv->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidgetv->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetv->setSelectionMode(QAbstractItemView::SingleSelection);

    QSqlQuery query;
    if (!query.exec("SELECT ID_VEHICULE, NUM_SERIE, LOCALISATION, TYPE, MARQUE, MODELE, PROPRIETAIRE, ID_EMPLOYE "
                    "FROM VEHICULE ORDER BY ID_VEHICULE"))
    {
        qDebug() << "Erreur SQL:" << query.lastError().text();
        QMessageBox::critical(this, "Erreur", "Impossible de charger les véhicules: " + query.lastError().text());
        return;
    }

    int row = 0;
    while (query.next())
    {
        ui->tableWidgetv->insertRow(row);
        for (int col = 0; col < 8; ++col)
        {
            QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
            item->setFlags(item->flags() & ~Qt::ItemIsEditable);
            ui->tableWidgetv->setItem(row, col, item);
        }
        ++row;
    }
}

// ===================================================================
// CLIC SUR LIGNE
// ===================================================================
void vehicule_inter::on_tableWidgetv_itemClicked(QTableWidgetItem *item)
{
    if (!item) return;

    int row = item->row();
    selectedVehiculeId = ui->tableWidgetv->item(row, 0)->text().toInt();

    ui->lineEdit_idVehicule->setText(ui->tableWidgetv->item(row, 0)->text());
    ui->lineEdit_numSerie->setText(ui->tableWidgetv->item(row, 1)->text());
    ui->lineEdit_localisation->setText(ui->tableWidgetv->item(row, 2)->text());
    ui->lineEdit_type->setCurrentText(ui->tableWidgetv->item(row, 3)->text());
    ui->lineEdit_marque->setText(ui->tableWidgetv->item(row, 4)->text());
    ui->lineEdit_modele->setText(ui->tableWidgetv->item(row, 5)->text());
    ui->lineEdit_proprietaire->setText(ui->tableWidgetv->item(row, 6)->text());

    int idEmploye = ui->tableWidgetv->item(row, 7)->text().toInt();
    int index = ui->comboBoxid->findText(QString::number(idEmploye));
    if (index != -1) {
        ui->comboBoxid->setCurrentIndex(index);
    }

    ui->lineEdit_idVehicule->setEnabled(false);
    ui->validerV->setText("Enregistrer les modifications");
}

// ===================================================================
// BOUTON MODIFIER
// ===================================================================
void vehicule_inter::on_modifierV_clicked()
{
    if (selectedVehiculeId == -1) {
        QMessageBox::warning(this, "Sélection", "Sélectionnez un véhicule à modifier.");
        return;
    }

    ui->lineEdit_numSerie->setEnabled(true);
    ui->lineEdit_localisation->setEnabled(true);
    ui->lineEdit_type->setEnabled(true);
    ui->lineEdit_marque->setEnabled(true);
    ui->lineEdit_modele->setEnabled(true);
    ui->lineEdit_proprietaire->setEnabled(true);
    ui->comboBoxid->setEnabled(true);

    ui->validerV->setText("Enregistrer les modifications");
    QMessageBox::information(this, "Modification", "Modifiez les champs puis cliquez sur 'Enregistrer les modifications'.");
}

// ===================================================================
// BOUTON VALIDER
// ===================================================================
void vehicule_inter::on_validerV_clicked()
{
    QString numSerie = ui->lineEdit_numSerie->text().trimmed();
    QString loc = ui->lineEdit_localisation->text().trimmed();
    QString type = ui->lineEdit_type->currentText().trimmed();
    QString marque = ui->lineEdit_marque->text().trimmed();
    QString modele = ui->lineEdit_modele->text().trimmed();
    QString prop = ui->lineEdit_proprietaire->text().trimmed();

    int idEmploye = -1; // Valeur par défaut = aucun employé sélectionné
    int row = ui->comboBoxid->currentIndex();
    if (row >= 0) {
        QAbstractItemModel *model = ui->comboBoxid->model();
        idEmploye = model->data(model->index(row, 0)).toInt();
    }

    qDebug() << "ID employé sélectionné:" << idEmploye;

    if (!checkNumSerie(numSerie)) return;
    if (!checkLocalisation(loc)) return;
    if (type.isEmpty()) { QMessageBox::warning(this, "Type", "Sélectionnez un type."); return; }
    if (!checkMarque(marque)) return;
    if (!checkModele(modele)) return;
    if (!checkProprietaire(prop)) return;

    bool success = false;

    if (selectedVehiculeId == -1)
    {
        int idVehicule = 0;
        QString idText = ui->lineEdit_idVehicule->text().trimmed();
        if (!checkIdVehicule(idText, idVehicule)) return;

        Vehicules v(idVehicule, numSerie, loc, type, marque, modele, prop, idEmploye);
        success = v.ajouter();
        if (success) QMessageBox::information(this, "Succès", "Véhicule ajouté !");
    }
    else
    {
        Vehicules v;
        v.setIdVehicule(selectedVehiculeId);
        v.setNumSerie(numSerie);
        v.setLocalisation(loc);
        v.setType(type);
        v.setMarque(marque);
        v.setModele(modele);
        v.setProprietaire(prop);
        v.setIdEmploye(idEmploye);
        success = v.modifier();
        if (success) QMessageBox::information(this, "Succès", "Véhicule modifié !");
    }

    if (success) {
        clearVehiculeFields();
        refreshTable();
    } else {
        QMessageBox::critical(this, "Erreur", "Opération échouée.");
    }
}

// ===================================================================
// BOUTON ANNULER
// ===================================================================
void vehicule_inter::on_annulerV_clicked()
{
    clearVehiculeFields();
    ui->validerV->setText("Valider");
}

// ===================================================================
// BOUTON SUPPRIMER
// ===================================================================
void vehicule_inter::on_supprimerV_clicked()
{
    if (selectedVehiculeId == -1) {
        QMessageBox::warning(this, "Sélection", "Sélectionnez un véhicule.");
        return;
    }

    auto rep = QMessageBox::question(this, "Confirmer", "Supprimer ?", QMessageBox::Yes | QMessageBox::No);
    if (rep == QMessageBox::Yes && Vehicules::supprimer(selectedVehiculeId)) {
        QMessageBox::information(this, "Succès", "Supprimé.");
        clearVehiculeFields();
        refreshTable();
    }
}

// ===================================================================
// VIDER LES CHAMPS
// ===================================================================
void vehicule_inter::clearVehiculeFields()
{
    ui->lineEdit_idVehicule->clear();
    ui->lineEdit_numSerie->clear();
    ui->lineEdit_localisation->clear();
    ui->lineEdit_type->setCurrentIndex(-1);
    ui->lineEdit_marque->clear();
    ui->lineEdit_modele->clear();
    ui->lineEdit_proprietaire->clear();
    ui->comboBoxid->setCurrentIndex(-1);

    ui->lineEdit_idVehicule->setEnabled(true);
    ui->lineEdit_numSerie->setEnabled(true);
    ui->lineEdit_localisation->setEnabled(true);
    ui->lineEdit_type->setEnabled(true);
    ui->lineEdit_marque->setEnabled(true);
    ui->lineEdit_modele->setEnabled(true);
    ui->lineEdit_proprietaire->setEnabled(true);
    ui->comboBoxid->setEnabled(true);

    selectedVehiculeId = -1;
    ui->validerV->setText("Valider");
}

// ===================================================================
// BOUTON RECHERCHE
// ===================================================================
void vehicule_inter::on_recherche_clicked()
{
    QString rechercheText = ui->rech->text().trimmed(); // Assume a search input lineEditRecherche
    QString searchField = ui->rech_par->currentText(); // Combobox for selecting modele, marque, or type

    ui->tableWidgetv->clearContents();
    ui->tableWidgetv->setRowCount(0);

    QStringList headers = {"ID", "Num Serie", "Localisation", "Type", "Marque", "Modele", "Proprietaire", "ID Employe"};
    ui->tableWidgetv->setColumnCount(8);
    ui->tableWidgetv->setHorizontalHeaderLabels(headers);
    ui->tableWidgetv->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidgetv->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetv->setSelectionMode(QAbstractItemView::SingleSelection);

    QSqlQuery query;
    if (rechercheText.isEmpty()) {
        query.prepare("SELECT ID_VEHICULE, NUM_SERIE, LOCALISATION, TYPE, MARQUE, MODELE, PROPRIETAIRE, ID_EMPLOYE FROM VEHICULE ORDER BY ID_VEHICULE");
    } else {
        if (searchField == "Marque") {
            query.prepare("SELECT ID_VEHICULE, NUM_SERIE, LOCALISATION, TYPE, MARQUE, MODELE, PROPRIETAIRE, ID_EMPLOYE FROM VEHICULE WHERE MARQUE LIKE :recherche ORDER BY MARQUE");
        } else if (searchField == "Modéle") {
            query.prepare("SELECT ID_VEHICULE, NUM_SERIE, LOCALISATION, TYPE, MARQUE, MODELE, PROPRIETAIRE, ID_EMPLOYE FROM VEHICULE WHERE MODELE LIKE :recherche ORDER BY MODELE");
        } else if (searchField == "Type") {
            query.prepare("SELECT ID_VEHICULE, NUM_SERIE, LOCALISATION, TYPE, MARQUE, MODELE, PROPRIETAIRE, ID_EMPLOYE FROM VEHICULE WHERE TYPE LIKE :recherche ORDER BY TYPE");
        } else {
            // Default to search all fields if needed
            query.prepare("SELECT ID_VEHICULE, NUM_SERIE, LOCALISATION, TYPE, MARQUE, MODELE, PROPRIETAIRE, ID_EMPLOYE FROM VEHICULE WHERE MARQUE LIKE :recherche OR MODELE LIKE :recherche OR TYPE LIKE :recherche ORDER BY ID_VEHICULE");
        }
        query.bindValue(":recherche", "%" + rechercheText + "%");
    }

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Impossible deffectuer la recherche: " + query.lastError().text());
        refreshTable();
        return;
    }

    int row = 0;
    while (query.next()) {
        ui->tableWidgetv->insertRow(row);
        for (int col = 0; col < 8; ++col) {
            QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
            item->setFlags(item->flags() & ~Qt::ItemIsEditable);
            ui->tableWidgetv->setItem(row, col, item);
        }
        ++row;
    }

    if (row == 0 && !rechercheText.isEmpty()) {
        QMessageBox::information(this, "Recherche", "Aucun véhicule trouvé avec les critères donnés.");
    }
}

// ===================================================================
// CONTRÔLES
// ===================================================================
bool vehicule_inter::checkIdVehicule(const QString &idText, int &idValue)
{
    if (idText.isEmpty()) { QMessageBox::warning(this, "ID", "Obligatoire."); return false; }
    bool ok;
    idValue = idText.toInt(&ok);
    if (!ok || idValue <= 0) { QMessageBox::warning(this, "ID", "Nombre positif."); return false; }
    if (idText.length() > 8) { QMessageBox::warning(this, "ID", "Max 8 chiffres."); return false; }

    QSqlQuery q;
    q.prepare("SELECT COUNT(*) FROM VEHICULE WHERE ID_VEHICULE = :id");
    q.bindValue(":id", idValue);
    if (!q.exec()) {
        qDebug() << "Erreur SQL checkIdVehicule:" << q.lastError().text();
        QMessageBox::critical(this, "Erreur", "Erreur lors de la vérification de l'ID: " + q.lastError().text());
        return false;
    }
    if (q.next() && q.value(0).toInt() > 0) {
        QMessageBox::warning(this, "ID", "ID déjà utilisé.");
        return false;
    }
    return true;
}

bool vehicule_inter::checkNumSerie(const QString &numSerie)
{
    if (numSerie.length() != 6) { QMessageBox::warning(this, "Num Série", "6 caractères."); return false; }
    QRegularExpression re("^[A-Za-z0-9]{6}$");
    if (!re.match(numSerie).hasMatch()) {
        QMessageBox::warning(this, "Num Série", "Le numéro de série doit contenir uniquement des lettres et chiffres (6 caractères).");
        return false;
    }
    return true;
}

bool vehicule_inter::checkLocalisation(const QString &loc)
{
    if (loc.isEmpty()) { QMessageBox::warning(this, "Localisation", "Obligatoire."); return false; }
    if (loc.length() > 50) { QMessageBox::warning(this, "Localisation", "Max 50."); return false; }
    return true;
}

bool vehicule_inter::checkMarque(const QString &marque)
{
    if (marque.isEmpty()) { QMessageBox::warning(this, "Marque", "Obligatoire."); return false; }
    if (marque.length() > 15) { QMessageBox::warning(this, "Marque", "Max 15."); return false; }
    return true;
}

bool vehicule_inter::checkModele(const QString &modele)
{
    if (modele.isEmpty()) { QMessageBox::warning(this, "Modèle", "Obligatoire."); return false; }
    if (modele.length() > 15) { QMessageBox::warning(this, "Modèle", "Max 15."); return false; }
    return true;
}

bool vehicule_inter::checkProprietaire(const QString &prop)
{
    if (prop.isEmpty()) { QMessageBox::warning(this, "Propriétaire", "Obligatoire."); return false; }
    if (prop.length() > 20) { QMessageBox::warning(this, "Propriétaire", "Max 20."); return false; }
    return true;
}

void vehicule_inter::on_trier_clicked()
{
    QString trierPar = ui->tripar->currentText(); // Combobox with options "Marque", "Modele", "Type"

    ui->tableWidgetv->clearContents();
    ui->tableWidgetv->setRowCount(0);

    QStringList headers = {"ID", "Num Serie", "Localisation", "Type", "Marque", "Modele", "Proprietaire", "ID Employ"};
    ui->tableWidgetv->setColumnCount(8);
    ui->tableWidgetv->setHorizontalHeaderLabels(headers);
    ui->tableWidgetv->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidgetv->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetv->setSelectionMode(QAbstractItemView::SingleSelection);

    QString orderBy;
    if (trierPar == "Marque")
        orderBy = "MARQUE";
    if (trierPar == "Modéle")
        orderBy = "MODELE";
    if (trierPar == "Type")
        orderBy = "TYPE";

    QSqlQuery query;
    if (!query.exec("SELECT ID_VEHICULE, NUM_SERIE, LOCALISATION, TYPE, MARQUE, MODELE, PROPRIETAIRE, ID_EMPLOYE FROM VEHICULE ORDER BY " + orderBy)) {
        QMessageBox::critical(this, "Erreur", "Impossible de trier: " + query.lastError().text());
        refreshTable();
        return;
    }

    int row = 0;
    while (query.next()) {
        ui->tableWidgetv->insertRow(row);
        for (int col = 0; col < 8; ++col) {
            QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
            item->setFlags(item->flags() & ~Qt::ItemIsEditable);
            ui->tableWidgetv->setItem(row, col, item);
        }
        ++row;
    }
}


void vehicule_inter::on_pdf_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Exporter en PDF"), "", "*.pdf");
    if (fileName.isEmpty()) return;
    if (QFileInfo(fileName).suffix().isEmpty()) {
        fileName.append(".pdf");
    }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);

    QTextDocument doc;
    QString html = "<table border='1' cellspacing='0' cellpadding='2'><tr>";
    // Headers
    for (int c = 0; c < ui->tableWidgetv->columnCount(); ++c) {
        html += "<th>" + ui->tableWidgetv->horizontalHeaderItem(c)->text() + "</th>";
    }
    html += "</tr>";

    // Data rows
    for (int r = 0; r < ui->tableWidgetv->rowCount(); ++r) {
        html += "<tr>";
        for (int c = 0; c < ui->tableWidgetv->columnCount(); ++c) {
            QTableWidgetItem *item = ui->tableWidgetv->item(r, c);
            html += "<td>" + (item ? item->text() : "") + "</td>";
        }
        html += "</tr>";
    }
    html += "</table>";

    doc.setHtml(html);
    doc.print(&printer);

    QMessageBox::information(this, tr("Exportation"), tr("Export vers PDF réussi."));
}

