#include "vehicule_fonc.h"
#include "ui_vehicule_fonc.h"

#include <QStyle>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QString>
#include <QStringList>
#include <QTextCursor>
#include <QShowEvent>
#include <QLabel>
#include <QPixmap>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QUrlQuery>
#include <QVariant>

vehicule_fonc::vehicule_fonc(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::vehicule_fonc)
    , networkManager(new QNetworkAccessManager(this))
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/samar/OneDrive/Bureau/projet C++/logo.png");
    ui->logo->setPixmap(pix.scaled(90,90,Qt::KeepAspectRatio));

    QPixmap statPix("C:/Users/samar/OneDrive/Bureau/projet C++/stat_vehi.png");
    ui->stat->setPixmap(statPix.scaled(120,120,Qt::KeepAspectRatio));

    ui->envoyer->setIcon(style()->standardIcon(QStyle::SP_ArrowForward));
    ui->computer->setIcon(style()->standardIcon(QStyle::SP_ComputerIcon));
    
    // Connect Enter key to send message
    connect(ui->lets_chat, &QLineEdit::returnPressed, this, &vehicule_fonc::on_envoyer_clicked);
    
    // Initialize chatbot welcome message
    ui->rep->setPlainText("Chatbot: Bonjour! Je suis votre assistant pour la gestion des véhicules.\n"
                          "Posez-moi des questions sur les véhicules dans la base de données.\n"
                          "Tapez 'aide' pour voir les questions disponibles.");
    
    // Configure progress bars - similar to appar_fonction
    if (ui->voiture) {
        ui->voiture->setMinimumHeight(31);
        ui->voiture->setTextVisible(true);
        ui->voiture->setStyleSheet(
            "QProgressBar {"
            "    border: 2px solid rgb(255, 191, 62);"
            "    border-radius: 8px;"
            "    text-align: center;"
            "    font-weight: bold;"
            "    font-size: 12pt;"
            "    color: white;"
            "    background-color: rgb(0, 125, 209);"
            "}"
            "QProgressBar::chunk {"
            "    background-color: rgb(0, 125, 209);"
            "    border-radius: 6px;"
            "}"
        );
    }
    
    if (ui->moto) {
        ui->moto->setMinimumHeight(31);
        ui->moto->setTextVisible(true);
        ui->moto->setStyleSheet(
            "QProgressBar {"
            "    border: 2px solid rgb(255, 191, 62);"
            "    border-radius: 8px;"
            "    text-align: center;"
            "    font-weight: bold;"
            "    font-size: 12pt;"
            "    color: white;"
            "    background-color: rgb(237, 28, 36);"
            "}"
            "QProgressBar::chunk {"
            "    background-color: rgb(237, 28, 36);"
            "    border-radius: 6px;"
            "}"
        );
    }
    
    if (ui->camion) {
        ui->camion->setMinimumHeight(31);
        ui->camion->setTextVisible(true);
        ui->camion->setStyleSheet(
            "QProgressBar {"
            "    border: 2px solid rgb(255, 191, 62);"
            "    border-radius: 8px;"
            "    text-align: center;"
            "    font-weight: bold;"
            "    font-size: 12pt;"
            "    color: white;"
            "    background-color: rgb(36, 179, 122);"
            "}"
            "QProgressBar::chunk {"
            "    background-color: rgb(36, 179, 122);"
            "    border-radius: 6px;"
            "}"
        );
    }
    
    if (ui->bus) {
        ui->bus->setMinimumHeight(31);
        ui->bus->setTextVisible(true);
        ui->bus->setStyleSheet(
            "QProgressBar {"
            "    border: 2px solid rgb(255, 191, 62);"
            "    border-radius: 8px;"
            "    text-align: center;"
            "    font-weight: bold;"
            "    font-size: 12pt;"
            "    color: white;"
            "    background-color: rgb(93, 135, 143);"
            "}"
            "QProgressBar::chunk {"
            "    background-color: rgb(93, 135, 143);"
            "    border-radius: 6px;"
            "}"
        );
    }
    
    if (ui->bis) {
        ui->bis->setMinimumHeight(31);
        ui->bis->setTextVisible(true);
        ui->bis->setStyleSheet(
            "QProgressBar {"
            "    border: 2px solid rgb(255, 191, 62);"
            "    border-radius: 8px;"
            "    text-align: center;"
            "    font-weight: bold;"
            "    font-size: 12pt;"
            "    color: white;"
            "    background-color: rgb(254, 182, 52);"
            "}"
            "QProgressBar::chunk {"
            "    background-color: rgb(254, 182, 52);"
            "    border-radius: 6px;"
            "}"
        );
    }
    
    // Update statistics from database
    updateStatistics();
    
    // Generate QR codes
    generateAllQRCodes();
}

vehicule_fonc::~vehicule_fonc()
{
    delete ui;
}

void vehicule_fonc::showEvent(QShowEvent *event)
{
    QDialog::showEvent(event);
    // Refresh statistics when dialog is shown
    updateStatistics();
}

void vehicule_fonc::on_accueil_clicked()
{
    if (parentWidget()) {
        parentWidget()->show();
    }

    this->close();
}


void vehicule_fonc::on_envoyer_clicked()
{
    QString userInput = ui->lets_chat->text().trimmed().toLower();
    
    if (userInput.isEmpty()) {
        return;
    }
    
    // Display user message
    QString currentText = ui->rep->toPlainText();
    if (!currentText.isEmpty()) {
        currentText += "\n\n";
    }
    currentText += "Vous: " + ui->lets_chat->text() + "\n";
    
    // Process the question and get response
    QString response = processChatbotQuery(userInput);
    currentText += "Chatbot: " + response;
    
    ui->rep->setPlainText(currentText);
    ui->lets_chat->clear();
    
    // Scroll to bottom
    QTextCursor cursor = ui->rep->textCursor();
    cursor.movePosition(QTextCursor::End);
    ui->rep->setTextCursor(cursor);
}

QString vehicule_fonc::processChatbotQuery(const QString &input)
{
    QSqlQuery query;
    QString response;
    
    // Check for total vehicle count
    if (input.contains("combien") && (input.contains("vehicule") || input.contains("véhicule")) && 
        !input.contains("marque") && !input.contains("modele") && !input.contains("modèle") && !input.contains("type")) {
        query.prepare("SELECT COUNT(*) FROM VEHICULE");
        if (query.exec() && query.next()) {
            int count = query.value(0).toInt();
            response = QString("Il y a %1 véhicule(s) dans la base de données.").arg(count);
        } else {
            response = "Erreur lors de la requête: " + query.lastError().text();
        }
    }
    // Check for number of distinct marques (brands)
    else if (input.contains("combien") && input.contains("marque")) {
        query.prepare("SELECT COUNT(DISTINCT MARQUE) FROM VEHICULE");
        if (query.exec() && query.next()) {
            int count = query.value(0).toInt();
            response = QString("Il y a %1 marque(s) différente(s) dans la base de données.").arg(count);
        } else {
            response = "Erreur lors de la requête: " + query.lastError().text();
        }
    }
    // Check for number of distinct modeles (models)
    else if (input.contains("combien") && (input.contains("modele") || input.contains("modèle"))) {
        query.prepare("SELECT COUNT(DISTINCT MODELE) FROM VEHICULE");
        if (query.exec() && query.next()) {
            int count = query.value(0).toInt();
            response = QString("Il y a %1 modèle(s) différent(s) dans la base de données.").arg(count);
        } else {
            response = "Erreur lors de la requête: " + query.lastError().text();
        }
    }
    // Check for number of distinct types
    else if (input.contains("combien") && input.contains("type")) {
        query.prepare("SELECT COUNT(DISTINCT TYPE) FROM VEHICULE");
        if (query.exec() && query.next()) {
            int count = query.value(0).toInt();
            response = QString("Il y a %1 type(s) de véhicule(s) différent(s) dans la base de données.").arg(count);
        } else {
            response = "Erreur lors de la requête: " + query.lastError().text();
        }
    }
    // Check for statistics (statistique)
    else if (input.contains("statistique") || input.contains("stat")) {
        response = "Statistiques des véhicules:\n";
        
        // Total
        query.prepare("SELECT COUNT(*) FROM VEHICULE");
        if (query.exec() && query.next()) {
            int total = query.value(0).toInt();
            response += QString("Total: %1 véhicule(s)\n").arg(total);
        }
        
        // Count by type
        QStringList types = {"Voiture", "Moto", "Camion", "Bus", "Bicyclette"};
        for (const QString &type : types) {
            query.prepare("SELECT COUNT(*) FROM VEHICULE WHERE UPPER(TYPE) = UPPER(:type)");
            query.bindValue(":type", type);
            if (query.exec() && query.next()) {
                int count = query.value(0).toInt();
                if (count > 0) {
                    response += QString("- %1: %2 véhicule(s)\n").arg(type).arg(count);
                }
            }
        }
        
        // Count distinct marques
        query.prepare("SELECT COUNT(DISTINCT MARQUE) FROM VEHICULE");
        if (query.exec() && query.next()) {
            int marques = query.value(0).toInt();
            response += QString("Marques différentes: %1\n").arg(marques);
        }
        
        // Count distinct modeles
        query.prepare("SELECT COUNT(DISTINCT MODELE) FROM VEHICULE");
        if (query.exec() && query.next()) {
            int modeles = query.value(0).toInt();
            response += QString("Modèles différents: %1").arg(modeles);
        }
    }
    // Check for specific vehicle type counts
    else if (input.contains("combien") && input.contains("voiture")) {
        query.prepare("SELECT COUNT(*) FROM VEHICULE WHERE UPPER(TYPE) = 'VOITURE'");
        if (query.exec() && query.next()) {
            int count = query.value(0).toInt();
            response = QString("Il y a %1 voiture(s) dans la base de données.").arg(count);
        } else {
            response = "Erreur lors de la requête: " + query.lastError().text();
        }
    }
    else if (input.contains("combien") && input.contains("moto")) {
        query.prepare("SELECT COUNT(*) FROM VEHICULE WHERE UPPER(TYPE) = 'MOTO'");
        if (query.exec() && query.next()) {
            int count = query.value(0).toInt();
            response = QString("Il y a %1 moto(s) dans la base de données.").arg(count);
        } else {
            response = "Erreur lors de la requête: " + query.lastError().text();
        }
    }
    else if (input.contains("combien") && input.contains("camion")) {
        query.prepare("SELECT COUNT(*) FROM VEHICULE WHERE UPPER(TYPE) = 'CAMION'");
        if (query.exec() && query.next()) {
            int count = query.value(0).toInt();
            response = QString("Il y a %1 camion(s) dans la base de données.").arg(count);
        } else {
            response = "Erreur lors de la requête: " + query.lastError().text();
        }
    }
    else if (input.contains("combien") && input.contains("bus")) {
        query.prepare("SELECT COUNT(*) FROM VEHICULE WHERE UPPER(TYPE) = 'BUS'");
        if (query.exec() && query.next()) {
            int count = query.value(0).toInt();
            response = QString("Il y a %1 bus dans la base de données.").arg(count);
        } else {
            response = "Erreur lors de la requête: " + query.lastError().text();
        }
    }
    else if (input.contains("combien") && (input.contains("bicyclette") || input.contains("vélo"))) {
        query.prepare("SELECT COUNT(*) FROM VEHICULE WHERE UPPER(TYPE) = 'BICYCLETTE'");
        if (query.exec() && query.next()) {
            int count = query.value(0).toInt();
            response = QString("Il y a %1 bicyclette(s) dans la base de données.").arg(count);
        } else {
            response = "Erreur lors de la requête: " + query.lastError().text();
        }
    }
    // Help message
    else if (input.contains("aide") || input.contains("help") || input.contains("?")) {
        response = "Je peux répondre aux questions suivantes:\n"
                   "- Combien de véhicule(s)?\n"
                   "- Combien de marque(s)?\n"
                   "- Combien de modèle(s)?\n"
                   "- Combien de type(s)?\n"
                   "- Combien de voiture(s)?\n"
                   "- Combien de moto(s)?\n"
                   "- Combien de camion(s)?\n"
                   "- Combien de bus?\n"
                   "- Combien de bicyclette(s)?\n"
                   "- Statistique(s)";
    }
    // Default response
    else {
        response = "Je ne comprends pas votre question. Je peux vous aider avec des questions sur la gestion des véhicules.\n"
                   "Tapez 'aide' pour voir les questions disponibles.";
    }
    
    return response;
}

void vehicule_fonc::updateStatistics()
{
    QSqlQuery query;
    
    // Get total count
    int totalCount = 0;
    if (query.exec("SELECT COUNT(*) FROM VEHICULE")) {
        if (query.next()) {
            totalCount = query.value(0).toInt();
        }
    } else {
        qDebug() << "Error getting total count:" << query.lastError().text();
    }
    
    // Update total label
    if (ui->total) {
        ui->total->setText(QString::number(totalCount));
    }
    
    // Count each vehicle type
    int voitureCount = 0;
    int motoCount = 0;
    int camionCount = 0;
    int busCount = 0;
    int bicycletteCount = 0;
    
    // Count Voiture
    query.prepare("SELECT COUNT(*) FROM VEHICULE WHERE UPPER(TYPE) = 'VOITURE'");
    if (query.exec() && query.next()) {
        voitureCount = query.value(0).toInt();
    }
    
    // Count Moto
    query.prepare("SELECT COUNT(*) FROM VEHICULE WHERE UPPER(TYPE) = 'MOTO'");
    if (query.exec() && query.next()) {
        motoCount = query.value(0).toInt();
    }
    
    // Count Camion
    query.prepare("SELECT COUNT(*) FROM VEHICULE WHERE UPPER(TYPE) = 'CAMION'");
    if (query.exec() && query.next()) {
        camionCount = query.value(0).toInt();
    }
    
    // Count Bus
    query.prepare("SELECT COUNT(*) FROM VEHICULE WHERE UPPER(TYPE) = 'BUS'");
    if (query.exec() && query.next()) {
        busCount = query.value(0).toInt();
    }
    
    // Count Bicyclette
    query.prepare("SELECT COUNT(*) FROM VEHICULE WHERE UPPER(TYPE) = 'BICYCLETTE'");
    if (query.exec() && query.next()) {
        bicycletteCount = query.value(0).toInt();
    }
    
    // Calculate percentages
    int voiturePercent = 0;
    int motoPercent = 0;
    int camionPercent = 0;
    int busPercent = 0;
    int bicyclettePercent = 0;
    
    if (totalCount > 0) {
        voiturePercent = (voitureCount * 100) / totalCount;
        motoPercent = (motoCount * 100) / totalCount;
        camionPercent = (camionCount * 100) / totalCount;
        busPercent = (busCount * 100) / totalCount;
        bicyclettePercent = (bicycletteCount * 100) / totalCount;
    }
    
    // Update progress bars with percentage values - similar to appar_fonction
    if (ui->voiture) {
        ui->voiture->setMinimum(0);
        ui->voiture->setMaximum(100);
        ui->voiture->setValue(voiturePercent);
        ui->voiture->setFormat(QString::number(voiturePercent) + "%");
        ui->voiture->show();
        ui->voiture->setVisible(true);
        qDebug() << "Voiture progress bar updated:" << voiturePercent << "%";
    } else {
        qDebug() << "ERROR: 'voiture' progress bar not found in UI";
    }
    
    if (ui->moto) {
        ui->moto->setMinimum(0);
        ui->moto->setMaximum(100);
        ui->moto->setValue(motoPercent);
        ui->moto->setFormat(QString::number(motoPercent) + "%");
        ui->moto->show();
        ui->moto->setVisible(true);
        qDebug() << "Moto progress bar updated:" << motoPercent << "%";
    } else {
        qDebug() << "ERROR: 'moto' progress bar not found in UI";
    }
    
    if (ui->camion) {
        ui->camion->setMinimum(0);
        ui->camion->setMaximum(100);
        ui->camion->setValue(camionPercent);
        ui->camion->setFormat(QString::number(camionPercent) + "%");
        ui->camion->show();
        ui->camion->setVisible(true);
        qDebug() << "Camion progress bar updated:" << camionPercent << "%";
    } else {
        qDebug() << "ERROR: 'camion' progress bar not found in UI";
    }
    
    if (ui->bus) {
        ui->bus->setMinimum(0);
        ui->bus->setMaximum(100);
        ui->bus->setValue(busPercent);
        ui->bus->setFormat(QString::number(busPercent) + "%");
        ui->bus->show();
        ui->bus->setVisible(true);
        qDebug() << "Bus progress bar updated:" << busPercent << "%";
    } else {
        qDebug() << "ERROR: 'bus' progress bar not found in UI";
    }
    
    if (ui->bis) {
        ui->bis->setMinimum(0);
        ui->bis->setMaximum(100);
        ui->bis->setValue(bicyclettePercent);
        ui->bis->setFormat(QString::number(bicyclettePercent) + "%");
        ui->bis->show();
        ui->bis->setVisible(true);
        qDebug() << "Bicyclette progress bar updated:" << bicyclettePercent << "%";
    } else {
        qDebug() << "ERROR: 'bis' progress bar not found in UI";
    }
    
    qDebug() << "Statistics updated - Total:" << totalCount 
             << "Voiture:" << voitureCount << "(" << voiturePercent << "%)"
             << "Moto:" << motoCount << "(" << motoPercent << "%)"
             << "Camion:" << camionCount << "(" << camionPercent << "%)"
             << "Bus:" << busCount << "(" << busPercent << "%)"
             << "Bicyclette:" << bicycletteCount << "(" << bicyclettePercent << "%)";
}

void vehicule_fonc::generateQRCode(const QString &url, QLabel *label, int size)
{
    if (!label) {
        qDebug() << "Error: Label is null for QR code generation";
        return;
    }
    
    // Use QR code API to generate QR code
    QString apiUrl = QString("https://api.qrserver.com/v1/create-qr-code/?size=%1x%1&data=%2")
                     .arg(size)
                     .arg(QUrl::toPercentEncoding(url));
    
    QUrl qrUrl(apiUrl);
    QNetworkRequest request;
    request.setUrl(qrUrl);
    QNetworkReply *reply = networkManager->get(request);
    
    // Connect the finished signal - capture label directly in lambda
    connect(reply, &QNetworkReply::finished, this, [this, reply, label]() {
        onQRCodeDownloaded(reply, label);
    });
}

void vehicule_fonc::onQRCodeDownloaded(QNetworkReply *reply, QLabel *targetLabel)
{
    if (!targetLabel) {
        reply->deleteLater();
        return;
    }
    
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray imageData = reply->readAll();
        QPixmap pixmap;
        if (pixmap.loadFromData(imageData)) {
            targetLabel->setPixmap(pixmap.scaled(200, 200, Qt::KeepAspectRatio, Qt::SmoothTransformation));
            targetLabel->setScaledContents(true);
            qDebug() << "QR code generated successfully for label";
        } else {
            qDebug() << "Error: Failed to load QR code image data";
            targetLabel->setText("QR Code\nError");
        }
    } else {
        qDebug() << "Error downloading QR code:" << reply->errorString();
        targetLabel->setText("QR Code\nError");
    }
    
    reply->deleteLater();
}

void vehicule_fonc::generateAllQRCodes()
{
    // Define URLs for each QR code - you can change these to your desired URLs
    QString url1 = "https://www.shutterstock.com/image-photo/mini-cooper-red-white-stripes-260nw-2558203343.jpg";
    QString url2 = "https://cdn.motor1.com/images/mgl/1ZQ2ep/s1/2024-audi-tt-special-edition-for-spain.webp";
    QString url3 = "https://motors.tn/magazine/wp-content/uploads/2019/10/Pr%C3%A9sentation-du-Camion-Mercedes-Benz-Actros-4X2-Tracteur-routier-2040-S-Tunisie-2.jpg";
    
    // Generate QR codes for each label
    // Check if labels exist in UI
    QLabel *qr1 = findChild<QLabel*>("QR1");
    QLabel *qr2 = findChild<QLabel*>("QR2");
    QLabel *qr3 = findChild<QLabel*>("QR3");
    
    if (qr1) {
        generateQRCode(url1, qr1, 200);
        qDebug() << "Generating QR code 1 for URL:" << url1;
    } else {
        qDebug() << "Warning: QR1 label not found in UI";
    }
    
    if (qr2) {
        generateQRCode(url2, qr2, 200);
        qDebug() << "Generating QR code 2 for URL:" << url2;
    } else {
        qDebug() << "Warning: QR2 label not found in UI";
    }
    
    if (qr3) {
        generateQRCode(url3, qr3, 200);
        qDebug() << "Generating QR code 3 for URL:" << url3;
    } else {
        qDebug() << "Warning: QR3 label not found in UI";
    }
}

