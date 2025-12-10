#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "appartement.h"
#include <QDebug>
#include <QTimer>

#include <QPixmap>
#include <QMessageBox>
#include <QTableWidgetItem>
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
#include <QPushButton>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , arduinoMonitor(new ArduinoMonitor(this))
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/samar/OneDrive/Bureau/projet C++/logo.png");
    ui->logo->setPixmap(pix.scaled(90,90,Qt::KeepAspectRatio));
    apparWindow = nullptr;
    modifierWindow = nullptr;
    employeWindow = nullptr;

    // Setup Arduino monitor with auto-connect
    setupArduinoMonitor();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupArduinoMonitor()
{
    // Connect Arduino monitor signals
    connect(arduinoMonitor, &ArduinoMonitor::dataReceived,
            this, [this](const QString &codeBarre, float temperature, float humidity, const QString &status) {
                qDebug() << "=== ARDUINO DATA RECEIVED ===";
                qDebug() << "Time:" << QDateTime::currentDateTime().toString("hh:mm:ss");
                qDebug() << "Temperature:" << temperature << "°C";
                qDebug() << "Humidity:" << humidity << "%";
                qDebug() << "Status:" << status;
                qDebug() << "===========================";
            });

    connect(arduinoMonitor, &ArduinoMonitor::statusChanged,
            this, [this](const QString &codeBarre, const QString &oldStatus, const QString &newStatus) {
                qDebug() << "Database status changed for" << codeBarre << ":" << oldStatus << "->" << newStatus;
            });

    connect(arduinoMonitor, &ArduinoMonitor::connectionStatusChanged,
            this, [this](bool connected) {
                if (connected) {
                    qDebug() << "✅ Arduino CONNECTED successfully";
                } else {
                    qDebug() << "❌ Arduino DISCONNECTED";
                    // Try to reconnect after 5 seconds
                    QTimer::singleShot(5000, this, &MainWindow::autoConnectToArduino);
                }
            });

    connect(arduinoMonitor, &ArduinoMonitor::errorOccurred,
            this, [this](const QString &error) {
                qDebug() << "Arduino error:" << error;
            });

    // Auto-connect to Arduino after 2 seconds
    QTimer::singleShot(2000, this, &MainWindow::autoConnectToArduino);
}

void MainWindow::autoConnectToArduino()
{
    // Only try to connect if not already connected
    if (arduinoMonitor->isConnected()) {
        qDebug() << "Arduino already connected";
        return;
    }

    qDebug() << "=== AUTO-CONNECTING TO ARDUINO ON COM12 ===";

    // First, try COM12 specifically
    qDebug() << "Trying COM12 first...";
    bool connected = arduinoMonitor->connectToArduino("COM12");

    if (connected) {
        qDebug() << "✅ Successfully connected to Arduino on COM12";
        return;
    }

    qDebug() << "Failed to connect to COM12. Searching for other COM ports...";

    // Get available COM ports
    QStringList ports = ArduinoMonitor::getAvailablePorts();

    if (ports.isEmpty()) {
        qDebug() << "No COM ports found. Will retry in 10 seconds...";
        QTimer::singleShot(10000, this, &MainWindow::autoConnectToArduino);
        return;
    }

    qDebug() << "Found COM ports:" << ports;

    // Try other ports
    for (const QString &port : ports) {
        // Skip COM12 since we already tried it
        if (port == "COM12") continue;

        qDebug() << "Trying to connect to port:" << port;
        connected = arduinoMonitor->connectToArduino(port);
        if (connected) {
            qDebug() << "✅ Successfully connected to Arduino on port:" << port;
            return;
        } else {
            qDebug() << "Failed to connect to port:" << port;
        }
    }

    qDebug() << "Failed to connect to any COM port. Will retry in 10 seconds...";
    QTimer::singleShot(10000, this, &MainWindow::autoConnectToArduino);
}

QMessageBox* MainWindow::createStyledMessageBox(QMessageBox::Icon icon, const QString& title, const QString& text, QMessageBox::StandardButtons buttons)
{
    QMessageBox* msgBox = new QMessageBox(this);
    msgBox->setIcon(icon);
    msgBox->setWindowTitle(title);
    msgBox->setText(text);
    msgBox->setStandardButtons(buttons);

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

void MainWindow::on_fonction_clicked()
{
    hide();
    apparWindow = new appar_fonction(this);
    apparWindow->show();
}


void MainWindow::on_ges_vehic_clicked()
{
    hide();
    vehiculeWindow = new vehicule_inter(this);
    vehiculeWindow->show();
}


void MainWindow::on_ges_es_vert_clicked()
{
    hide();
    espaceWindow = new espace_inter(this);
    espaceWindow->show();
}


void MainWindow::on_ges_mat_clicked()
{
    hide();
    materielWindow = new mate_inter(this);
    materielWindow->show();
}

void MainWindow::on_valider_clicked()
{
    QString id = ui->id->text();
    QString numtel = ui->numtel->text();
    QString numapp = ui->numapp->text();
    QString add = ui->add->text();
    QString etage = ui->etage->currentText();
    QString ss = ui->ss->text();
    QString prixText = ui->prix->text();

    Appartement appart(id, numtel, numapp, add, etage, ss);

    if (!prixText.isEmpty())
    {
        bool ok;
        int prix = prixText.toInt(&ok);
        if (ok && prix >= 0)
        {
            appart.setPrix(prix);
        }
        else
        {
            QMessageBox* msgBox = createStyledMessageBox(QMessageBox::Warning, "Erreur", "Le prix doit être un nombre positif valide.");
            msgBox->exec();
            msgBox->deleteLater();
            return;
        }
    }

    if (!appart.estValide())
    {
        QString errorMsg = "Veuillez remplir tous les champs obligatoires et sélectionner un étage.";

        bool ok;
        if (id.isEmpty())
        {
            errorMsg = "L'ID appartement est obligatoire.";
        }
        else if (numtel.isEmpty())
        {
            errorMsg = "Le numéro de téléphone est obligatoire.";
        }
        else
        {
            numtel.toInt(&ok);
            if (!ok)
            {
                errorMsg = "Le numéro de téléphone doit être un nombre valide.";
            }
            else if (numapp.isEmpty())
            {
                errorMsg = "Le numéro d'appartement est obligatoire.";
            }
            else
            {
                numapp.toInt(&ok);
                if (!ok)
                {
                    errorMsg = "Le numéro d'appartement doit être un nombre valide.";
                }
                else if (ss.isEmpty())
                {
                    errorMsg = "Le nombre de pièces est obligatoire.";
                }
                else
                {
                    ss.toInt(&ok);
                    if (!ok)
                    {
                        errorMsg = "Le nombre de pièces doit être un nombre valide.";
                    }
                    else if (add.isEmpty())
                    {
                        errorMsg = "L'adresse est obligatoire.";
                    }
                    else if (etage.isEmpty() || etage == "Ajouter étage")
                    {
                        errorMsg = "Veuillez sélectionner un étage.";
                    }
                }
            }
        }

        QMessageBox* msgBox = createStyledMessageBox(QMessageBox::Warning, "Erreur", errorMsg);
        msgBox->exec();
        msgBox->deleteLater();
        return;
    }

    if (appart.ajouter())
    {
        QMessageBox* msgBox = createStyledMessageBox(QMessageBox::Information, "Succès", "Appartement ajouté avec succès à la base de données.");
        msgBox->exec();
        msgBox->deleteLater();
        on_annuler_clicked();
    }
    else
    {
        QMessageBox* msgBox = createStyledMessageBox(QMessageBox::Critical, "Erreur", "Erreur lors de l'ajout de l'appartement.\nVérifiez que l'ID n'existe pas déjà.");
        msgBox->exec();
        msgBox->deleteLater();
    }
}

void MainWindow::on_annuler_clicked()
{
    ui->id->clear();
    ui->numtel->clear();
    ui->numapp->clear();
    ui->add->clear();
    ui->etage->setCurrentIndex(0);
    ui->ss->clear();
    ui->prix->clear();
}

void MainWindow::on_recherche_clicked()
{
    QString critere = ui->repar->currentText();
    QString valeurRecherche = ui->rech->text().trimmed();
    QList<Appartement> appartements;

    if (critere == "Aucun")
    {
        appartements = Appartement::rechercherTous();
    }
    else if (critere == "Etage")
    {
        if (valeurRecherche.isEmpty())
        {
            appartements = Appartement::rechercherTous();
        }
        else
        {
            appartements = Appartement::rechercherParEtage(valeurRecherche);
        }
    }
    else if (critere == "Nombre de piéce")
    {
        if (valeurRecherche.isEmpty())
        {
            appartements = Appartement::rechercherTous();
        }
        else
        {
            appartements = Appartement::rechercherParNbrPieces(valeurRecherche);
        }
    }
    else if (critere == "Etat")
    {
        if (valeurRecherche.isEmpty())
        {
            appartements = Appartement::rechercherTous();
        }
        else
        {
            appartements = Appartement::rechercherParEtat(valeurRecherche);
        }
    }
    else
    {
        appartements = Appartement::rechercherTous();
    }

    currentAppartements = appartements;

    afficherAppartements(appartements);
}

void MainWindow::on_trier_clicked()
{
    QString critere = ui->tripar->currentText();

    if (currentAppartements.isEmpty())
    {
        currentAppartements = Appartement::rechercherTous();
    }

    if (critere == "Etage")
    {
        std::sort(currentAppartements.begin(), currentAppartements.end(),
                  [](const Appartement& a, const Appartement& b) {
                      return a.getEtage().toInt() < b.getEtage().toInt();
                  });
    }
    else if (critere == "Nombre de piéce")
    {
        std::sort(currentAppartements.begin(), currentAppartements.end(),
                  [](const Appartement& a, const Appartement& b) {
                      return a.getNbrPieces().toInt() < b.getNbrPieces().toInt();
                  });
    }
    else if (critere == "Etat")
    {
        std::sort(currentAppartements.begin(), currentAppartements.end(),
                  [](const Appartement& a, const Appartement& b) {
                      return a.getEtat() < b.getEtat();
                  });
    }
    else if (critere.compare("prix", Qt::CaseInsensitive) == 0)
    {
        std::sort(currentAppartements.begin(), currentAppartements.end(),
                  [](const Appartement& a, const Appartement& b) {
                      return a.getPrix() > b.getPrix();
                  });
    }

    afficherAppartements(currentAppartements);
}

void MainWindow::afficherAppartements(const QList<Appartement>& appartements)
{
    ui->res->setRowCount(0);

    ui->res->setRowCount(appartements.size());

    for (int i = 0; i < appartements.size(); ++i)
    {
        const Appartement& app = appartements[i];

        ui->res->setItem(i, 0, new QTableWidgetItem(app.getId()));
        ui->res->setItem(i, 1, new QTableWidgetItem(app.getNumTel()));
        ui->res->setItem(i, 2, new QTableWidgetItem(app.getNumApp()));
        ui->res->setItem(i, 3, new QTableWidgetItem(app.getAdresse()));
        ui->res->setItem(i, 4, new QTableWidgetItem(app.getEtage()));
        ui->res->setItem(i, 5, new QTableWidgetItem(app.getNbrPieces()));
        ui->res->setItem(i, 6, new QTableWidgetItem(app.getEtat()));
        ui->res->setItem(i, 7, new QTableWidgetItem(QString::number(app.getPrix())));
    }

    ui->res->resizeColumnsToContents();
}

void MainWindow::on_supprimer_clicked()
{
    QString idAppartement = ui->idmodsup->text().trimmed();

    if (idAppartement.isEmpty())
    {
        QMessageBox* msgBox = createStyledMessageBox(QMessageBox::Warning, "Erreur", "Veuillez entrer un identifiant d'appartement.");
        msgBox->exec();
        msgBox->deleteLater();
        return;
    }

    QMessageBox* msgBox = createStyledMessageBox(QMessageBox::Question, "Confirmation",
                                                 "Êtes-vous sûr de vouloir supprimer l'appartement avec l'ID: " + idAppartement + "?",
                                                 QMessageBox::Yes | QMessageBox::No);
    QMessageBox::StandardButton reply = static_cast<QMessageBox::StandardButton>(msgBox->exec());
    msgBox->deleteLater();

    if (reply == QMessageBox::Yes)
    {
        Appartement appart;
        if (appart.supprimer(idAppartement))
        {
            QMessageBox* msgBox = createStyledMessageBox(QMessageBox::Information, "Succès", "Appartement supprimé avec succès.");
            msgBox->exec();
            msgBox->deleteLater();
            ui->idmodsup->clear();
            if (!currentAppartements.isEmpty())
            {
                on_recherche_clicked();
            }
        }
        else
        {
            QMessageBox* msgBox = createStyledMessageBox(QMessageBox::Critical, "Erreur", "Erreur lors de la suppression.\nL'appartement avec cet ID n'existe peut-être pas.");
            msgBox->exec();
            msgBox->deleteLater();
        }
    }
}

void MainWindow::on_modifier_clicked()
{
    QString idAppartement = ui->idmodsup->text().trimmed();

    if (idAppartement.isEmpty())
    {
        QMessageBox* msgBox = createStyledMessageBox(QMessageBox::Warning, "Erreur", "Veuillez entrer un identifiant d'appartement.");
        msgBox->exec();
        msgBox->deleteLater();
        return;
    }

    Appartement appart;
    if (!appart.rechercher(idAppartement))
    {
        QMessageBox* msgBox = createStyledMessageBox(QMessageBox::Warning, "Erreur", "Appartement avec cet ID n'existe pas.");
        msgBox->exec();
        msgBox->deleteLater();
        return;
    }

    if (modifierWindow == nullptr)
    {
        modifierWindow = new appar_modifier(this);
        connect(modifierWindow, &appar_modifier::appartementModifie, this, [this]() {
            if (!currentAppartements.isEmpty())
            {
                on_recherche_clicked();
            }
        });
    }

    modifierWindow->chargerAppartement(idAppartement);

    modifierWindow->show();
    modifierWindow->raise();
    modifierWindow->activateWindow();
}


void MainWindow::on_ges_emp_clicked()
{
    hide();
    employeWindow = new employe_inter(this);
    employeWindow->show();
}

void MainWindow::on_pdf_clicked()
{
    QList<Appartement> appartements = Appartement::rechercherTous();

    if (appartements.isEmpty())
    {
        QMessageBox* msgBox = createStyledMessageBox(QMessageBox::Information, "Export PDF", "Aucun appartement à exporter.");
        msgBox->exec();
        msgBox->deleteLater();
        return;
    }

    QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", "", "Fichiers PDF (*.pdf)");

    if (fileName.isEmpty())
    {
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
    cursor.insertText("Liste des Appartements\n");
    cursor.insertText("\n");

    QTextTableFormat tableFormat;
    tableFormat.setAlignment(Qt::AlignCenter);
    tableFormat.setCellPadding(5);
    tableFormat.setCellSpacing(0);
    tableFormat.setBorder(1);
    tableFormat.setBorderStyle(QTextFrameFormat::BorderStyle_Solid);

    QTextTable *table = cursor.insertTable(appartements.size() + 1, 8, tableFormat);

    QTextCharFormat headerFormat;
    headerFormat.setFontWeight(QFont::Bold);
    headerFormat.setBackground(QColor("#E0E0E0"));

    QTextTableCell cell = table->cellAt(0, 0);
    cell.setFormat(headerFormat);
    cell.firstCursorPosition().insertText("ID");

    cell = table->cellAt(0, 1);
    cell.setFormat(headerFormat);
    cell.firstCursorPosition().insertText("Numéro Tél");

    cell = table->cellAt(0, 2);
    cell.setFormat(headerFormat);
    cell.firstCursorPosition().insertText("Numéro App");

    cell = table->cellAt(0, 3);
    cell.setFormat(headerFormat);
    cell.firstCursorPosition().insertText("Adresse");

    cell = table->cellAt(0, 4);
    cell.setFormat(headerFormat);
    cell.firstCursorPosition().insertText("Étage");

    cell = table->cellAt(0, 5);
    cell.setFormat(headerFormat);
    cell.firstCursorPosition().insertText("Nombre de Pièces");

    cell = table->cellAt(0, 6);
    cell.setFormat(headerFormat);
    cell.firstCursorPosition().insertText("État");

    cell = table->cellAt(0, 7);
    cell.setFormat(headerFormat);
    cell.firstCursorPosition().insertText("Prix");

    for (int i = 0; i < appartements.size(); ++i)
    {
        const Appartement& app = appartements[i];

        table->cellAt(i + 1, 0).firstCursorPosition().insertText(app.getId());
        table->cellAt(i + 1, 1).firstCursorPosition().insertText(app.getNumTel());
        table->cellAt(i + 1, 2).firstCursorPosition().insertText(app.getNumApp());
        table->cellAt(i + 1, 3).firstCursorPosition().insertText(app.getAdresse());
        table->cellAt(i + 1, 4).firstCursorPosition().insertText(app.getEtage());
        table->cellAt(i + 1, 5).firstCursorPosition().insertText(app.getNbrPieces());
        table->cellAt(i + 1, 6).firstCursorPosition().insertText(app.getEtat());
        table->cellAt(i + 1, 7).firstCursorPosition().insertText(QString::number(app.getPrix()));
    }

    document.print(&printer);

    QMessageBox* msgBox = createStyledMessageBox(QMessageBox::Information, "Export PDF", "Les données ont été exportées avec succès vers:\n" + fileName);
    msgBox->exec();
    msgBox->deleteLater();
}
