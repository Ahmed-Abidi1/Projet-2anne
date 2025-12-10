#include "espace_fonc.h"
#include "ui_espace_fonc.h"
#include <QMessageBox>
#include <QPixmap>
#include <QQuickWidget>
#include <QQmlContext>
#include <QSqlQuery>
#include <QSqlError>
#include <QProgressBar>
#include <QLabel>
#include "espace.h"
#include "connection.h"
#include "espace_fonc.h"

#include <QChartView>
#include <QChart>
#include <QBarSet>
#include <QBarSeries>
#include <QBarCategoryAxis>
#include <QValueAxis>

#include <QPieSeries>       // ← PIE CHART
#include <QPieSlice>        // ← SLICES



Espace_fonc::Espace_fonc(QWidget *parent)
    : QDialog(parent), ui(new Ui::Espace_fonc)
{
    ui->setupUi(this);

    // Affichage logo redimensionné
    QPixmap pix("C:/Users/samar/OneDrive/Bureau/projet C++/logo.png");
    ui->logo->setPixmap(pix.scaled(90, 90, Qt::KeepAspectRatio));

    qDebug() << "espace_fonc constructor completed successfully";

    // Supposez que ui->markerWidget est un QWidget dans votre UI prévu pour les icones
    markerLayout = new QVBoxLayout(ui->map_2);
    ui->map_2->setLayout(markerLayout);

    // Initialiser le gestionnaire réseau
    networkManager = new QNetworkAccessManager(this);
    connect(networkManager, &QNetworkAccessManager::finished,
            this, &Espace_fonc::onNetworkReply);

    updatePieChartSecurite();
}

void Espace_fonc::on_recherche2_Clicked()
{
    bool okLat = false;
    bool okLon = false;

    double lat = ui->lat->text().toDouble(&okLat);
    double lon = ui->lon->text().toDouble(&okLon);

    if (!okLat || !okLon) {
        QMessageBox::warning(this, "Erreur", "Latitude ou longitude invalide");
        return;
    }

    // Créer un label comme icône
    QLabel *marker = new QLabel;
    QPixmap icon("C:/Users/LENOVO/Downloads/images");
    marker->setPixmap(icon.scaled(30, 30));
    markerLayout->addWidget(marker);

    ui->setupUi(this);
    networkManager = new QNetworkAccessManager(this);
    connect(networkManager, &QNetworkAccessManager::finished, this, &Espace_fonc::onNetworkReply);
}

void Espace_fonc::on_pushButton_clicked()
{
    if (parentWidget()) {
        parentWidget()->show();
    }
    this->close();
}

void Espace_fonc::on_envoyer_clicked()
{
    // Récupérer les 3 champs
    QString idEmploye = ui->id->text().trimmed();           // QLineEdit "id"
    QString nomEspaceVert = ui->espace_vert->text().trimmed(); // QLineEdit "espace_vert"
    QDate dateEnvoi = ui->date->date();                     // QDateEdit "date"

    // Vérifier que tous les champs sont remplis
    if (idEmploye.isEmpty() || nomEspaceVert.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir ID employé et nom d'espace vert.");
        return;
    }

    // Construire le message au format demandé : "ID: nom: date"
    QString numeroDest = idEmploye;  // Utiliser ID employé comme numéro destinataire
    QString texteMessage = QString("ID employé: %1\nNom espace vert: %2\nDate: %3")
                               .arg(idEmploye)
                               .arg(nomEspaceVert)
                               .arg(dateEnvoi.toString("dd/MM/yyyy"));

    // VOS INFORMATIONS INFOBIP (À REMPLACER)
    QString apiKey = "819cc2781fc53fb5b9ab51e70423b04a-71cde829-b78a-4231-b2da-5ac894a0fa20";
    QString baseUrl = "https://jjklpv.api.infobip.com";

    QUrl url(baseUrl + "/sms/2/text/single");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization", ("App " + apiKey).toUtf8());

    // Corps JSON Infobip
    QJsonObject message;
    message["from"] = "+44 7491 163443";     // Sender gratuit
    message["to"] = +21624701992;         // ID employé = numéro destinataire
    message["text"] = texteMessage;     // Message formaté

    QJsonDocument doc(message);
    networkManager->post(request, doc.toJson());

    qDebug() << "Message envoyé :" << texteMessage;
}

void Espace_fonc::onNetworkReply(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray response = reply->readAll();
        qDebug() << "Réponse Infobip:" << response;

        // Vérifier si succès dans la réponse JSON
        QJsonDocument doc = QJsonDocument::fromJson(response);
        if (!doc.isNull()) {
            QJsonObject obj = doc.object();
            if (obj.contains("to")) {
                QMessageBox::information(this, "✅ SUCCÈS",
                                         "SMS envoyé avec succès !\nVérifiez votre téléphone.");
            } else {
                QMessageBox::warning(this, "Erreur",
                                     "Réponse inattendue:\n" + response);
            }
        } else {
            QMessageBox::information(this, "✅ SUCCÈS", "SMS envoyé !");
        }
    } else {
        qDebug() << "Erreur réseau:" << reply->errorString();
        QMessageBox::warning(this, "❌ Erreur",
                             "Échec envoi SMS:\n" + reply->errorString());
    }
    reply->deleteLater();
}


Espace_fonc::~Espace_fonc()
{
    delete ui;
    // No need to delete connexion - it's not a member anymore
}


#include "connection.h"  // ← Votre classe Connection

void Espace_fonc::updatePieChartSecurite()
{
    qDebug() << "=== DÉBUT updatePieChartSecurite() ===";

    // Supprimer ancien graphique
    if (chartView) {
        ui->verticalLayout->removeWidget(chartView);
        delete chartView;
        chartView = nullptr;
        qDebug() << "Ancien graphique supprimé";
    }

    // FIXED: Use singleton instance and correct method name
    Connection& conn = Connection::getInstance();
    qDebug() << "Connection instance obtained";

    // FIXED: Use correct method name
    if (!conn.createConnection()) {
        qDebug() << "❌ ERREUR : createConnection() a échoué !";
        return;
    }
    qDebug() << "✅ Connexion BDD OK";

    QSqlDatabase db = conn.getDatabase();

    // TEST REQUÊTE avec DEBUG
    QSqlQuery query(db);
    QString sql = "SELECT SECURITE, COUNT(*) FROM ESPACE "
                  "GROUP BY SECURITE";
    qDebug() << "Requête exécutée :" << sql;

    if (!query.exec(sql)) {
        qDebug() << "❌ ERREUR requête :" << query.lastError().text();
        return;
    }

    int faible = 0, moyenne = 0, elevee = 0;
    qDebug() << "Résultats trouvés :";

    while (query.next()) {
        QString sec = query.value(0).toString();
        int cnt = query.value(1).toInt();
        qDebug() << "  Securite =" << sec << ", COUNT =" << cnt;

        QString secLower = sec.toLower();
        if (secLower.contains("faible")) { faible = cnt; qDebug() << "   → FAIBLE :" << faible; }
        else if (secLower.contains("moyenne")) { moyenne = cnt; qDebug() << "   → MOYENNE :" << moyenne; }
        else if (secLower.contains("elevee") || secLower.contains("élevée")) {
            elevee = cnt; qDebug() << "   → ÉLEVÉE :" << elevee;
        }
    }

    int total = faible + moyenne + elevee;
    qDebug() << "TOTAL =" << total << "(faible:" << faible << ", moyenne:" << moyenne << ", elevee:" << elevee << ")";

    if (total == 0) {
        qDebug() << "❌ AUCUNE donnée trouvée ! Vérifiez :";
        qDebug() << "  1. Nom table = 'espaces_verts' ?";
        qDebug() << "  2. Colonne = 'Securite' ?";
        qDebug() << "  3. Données présentes ?";
        return;
    }

    // CAMEMBERT
    QPieSeries *series = new QPieSeries();
    series->append("Faible", faible);
    series->append("Moyenne", moyenne);
    series->append("Élevée", elevee);

    for (QPieSlice *slice : series->slices()) {
        slice->setLabelVisible(true);
        slice->setLabel(slice->label() + "\n" + QString::number(slice->percentage()*100, 'f', 1) + "%");
        if (slice->label().contains("Faible"))
            slice->setBrush(QColor(255,100,100));
        else if (slice->label().contains("Moyenne"))
            slice->setBrush(QColor(255,200,100));
        else
            slice->setBrush(QColor(100,200,100));
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition (" + QString::number(total) + ")");
    chart->legend()->setAlignment(Qt::AlignBottom);

    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    ui->verticalLayout->addWidget(chartView);

    qDebug() << "✅ CAMEMBERT AFFICHÉ !";
    qDebug() << "=== FIN updatePieChartSecurite() ===";
}
