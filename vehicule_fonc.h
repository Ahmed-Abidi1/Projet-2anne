#ifndef VEHICULE_FONC_H
#define VEHICULE_FONC_H

#include <QDialog>
#include <QShowEvent>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QLabel>

namespace Ui {
class vehicule_fonc;
}

class vehicule_fonc : public QDialog
{
    Q_OBJECT

public:
    explicit vehicule_fonc(QWidget *parent = nullptr);
    ~vehicule_fonc();

protected:
    void showEvent(QShowEvent *event) override;

private slots:
    void on_accueil_clicked();
    void on_envoyer_clicked();

private:
    Ui::vehicule_fonc *ui;
    QNetworkAccessManager *networkManager;
    QString processChatbotQuery(const QString &input);
    void updateStatistics();
    void generateQRCode(const QString &url, QLabel *label, int size = 200);
    void generateAllQRCodes();
    void onQRCodeDownloaded(QNetworkReply *reply, QLabel *targetLabel);
};

#endif // VEHICULE_FONC_H
