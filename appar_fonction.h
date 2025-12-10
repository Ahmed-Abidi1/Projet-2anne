#ifndef APPAR_FONCTION_H
#define APPAR_FONCTION_H

#include <QDialog>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QSlider>
#include <QUrl>
#include <QAudioOutput>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include "appartement.h"
#include "connection.h"

class QChartView;

namespace Ui {
class appar_fonction;
}

class appar_fonction : public QDialog
{
    Q_OBJECT

public:
    explicit appar_fonction(QWidget *parent = nullptr);
    ~appar_fonction();

private slots:
    void on_accueil_clicked();


    void on_play_pause_clicked();

    void on_stop_clicked();

    void on_mute_clicked();

private:
    Ui::appar_fonction *ui;
    bool IS_Pause = true;
    bool IS_Muted = false;
    

    QMediaPlayer *mediaPlayer;
    QVideoWidget *videoWidget;
    int previousVolume = 50;
    QChartView *statChartView = nullptr;


    void updateStatistics();
    void loadHistorique();

};

#endif
