#ifndef ESPACE_FONC_H
#define ESPACE_FONC_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include "espace.h"
#include "connection.h"
#include <QVBoxLayout>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrlQuery>

#include <QDialog>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include <QChartView>
#include <QChart>
#include <QBarSet>
#include <QBarSeries>
#include <QBarCategoryAxis>
#include <QValueAxis>



namespace Ui {
class Espace_fonc;
}

class Espace_fonc : public QDialog
{
    Q_OBJECT

public:
    explicit Espace_fonc(QWidget *parent = nullptr);
    ~Espace_fonc();

private slots:
    void on_pushButton_clicked();
    void on_envoyer_clicked();
    void on_recherche2_Clicked();
    void onNetworkReply(QNetworkReply *reply);
    void updatePieChartSecurite();

private:
    Ui::Espace_fonc *ui;
    QVBoxLayout *markerLayout;
    QNetworkAccessManager *networkManager;
    // REMOVED: Connection connexion;  // ← Don't create Connection as member
    QChartView *chartView = nullptr;
};

#endif // ESPACE_FONC_H
