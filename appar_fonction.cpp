#include "appar_fonction.h"
#include "ui_appar_fonction.h"

#include <QVBoxLayout>
#include <QDir>
#include <QDebug>
#include <QPixmap>
#include <QStyle>
#include <QFile>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QSlider>
#include <QHBoxLayout>
#include <QUrl>
#include <QAudioOutput>
#include <QSqlQuery>
#include <QSqlError>
#include <QProgressBar>
#include <QLabel>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QAbstractItemView>
#include <QDateTime>
#include <QPainter>
#include <algorithm>

// Qt Charts
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include "appartement.h"
#include "connection.h"

appar_fonction::appar_fonction(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::appar_fonction)

{
    qDebug() << "Creating appar_fonction dialog...";
    ui->setupUi(this);
    qDebug() << "UI setup completed";

    QPixmap pix("C:/Users/samar/OneDrive/Bureau/projet C++/logo.png");
    ui->logo->setPixmap(pix.scaled(90,90,Qt::KeepAspectRatio));

    ui->play_pause->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    ui->stop->setIcon(style()->standardIcon(QStyle::SP_MediaStop));
    ui->mute->setIcon(style()->standardIcon(QStyle::SP_MediaVolume));

    mediaPlayer = new QMediaPlayer(this);
    videoWidget = new QVideoWidget(this);

    videoWidget->setMinimumSize(400, 300);

    mediaPlayer->setVideoOutput(videoWidget);

    QAudioOutput *audioOutput = new QAudioOutput(this);
    mediaPlayer->setAudioOutput(audioOutput);

    if (ui->video) {
        qDebug() << "Video groupBox found, setting up layout...";
        if (!ui->video->layout()) {
            QVBoxLayout *layout = new QVBoxLayout(ui->video);
            ui->video->setLayout(layout);
        }

        ui->video->layout()->addWidget(videoWidget);
        qDebug() << "Video widget added to video groupBox";
    } else {
        qDebug() << "ERROR: video groupBox not found in UI!";
        videoWidget->setParent(this);
        videoWidget->show();
    }

    ui->volumeSlider->setValue(50);

    connect(ui->volumeSlider, &QSlider::valueChanged, this, [this](int value) {
        mediaPlayer->audioOutput()->setVolume(value / 100.0);

        if (value == 0) {
            ui->mute->setIcon(style()->standardIcon(QStyle::SP_MediaVolumeMuted));
            IS_Muted = true;
        } else if (IS_Muted && value > 0) {
            ui->mute->setIcon(style()->standardIcon(QStyle::SP_MediaVolume));
            IS_Muted = false;
        }
    });

    mediaPlayer->audioOutput()->setVolume(0.5);

    QString videoPath = "C:/Users/samar/OneDrive/Documents/proji/video/vid.mp4";
    QFile file(videoPath);
    if (!file.exists()) {
        qDebug() << "Video file not found:" << videoPath;
        videoPath = "C:/Users/samar/OneDrive/Documents/proji/video/vid1.mp4";
        if (!QFile::exists(videoPath)) {
            qDebug() << "Alternative video file also not found:" << videoPath;
        }
    }

    mediaPlayer->setSource(QUrl::fromLocalFile(videoPath));

    connect(mediaPlayer, &QMediaPlayer::errorOccurred, this, [](QMediaPlayer::Error error, const QString &errorString) {
        qDebug() << "Media player error:" << error << errorString;
    });

    ui->play_pause->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));


    if (ui->Bar_occ) {
        ui->Bar_occ->setMinimumHeight(35);
        ui->Bar_occ->setTextVisible(true);
        ui->Bar_occ->setStyleSheet(
            "QProgressBar {"
            "    border: 2px solid #FFD700;"
            "    border-radius: 8px;"
            "    text-align: center;"
            "    font-weight: bold;"
            "    font-size: 16px;"
            "    color: white;"
            "    background-color: #2C2C2C;"
            "}"
            "QProgressBar::chunk {"
            "    background-color: #007DD1;"
            "    border-radius: 6px;"
            "}"
            );
    }

    if (ui->Bar_dis) {
        ui->Bar_dis->setMinimumHeight(35);
        ui->Bar_dis->setTextVisible(true);
        ui->Bar_dis->setStyleSheet(
            "QProgressBar {"
            "    border: 2px solid #FFD700;"
            "    border-radius: 8px;"
            "    text-align: center;"
            "    font-weight: bold;"
            "    font-size: 16px;"
            "    color: white;"
            "    background-color: #2C2C2C;"
            "}"
            "QProgressBar::chunk {"
            "    background-color: #20B077;"
            "    border-radius: 6px;"
            "}"
            );
    }


    if (ui->stat) {
        ui->stat->setText(QString());
        // Remove any border around the stat label
        ui->stat->setStyleSheet("border: none; background: transparent;");

        if (!ui->stat->layout()) {
            QVBoxLayout *statLayout = new QVBoxLayout(ui->stat);
            statLayout->setContentsMargins(0, 0, 0, 0);
            statLayout->setSpacing(0);
            statChartView = new QChartView(ui->stat);
            statLayout->addWidget(statChartView);
        } else {
            statChartView = new QChartView(ui->stat);
            ui->stat->layout()->addWidget(statChartView);
        }

        statChartView->setRenderHint(QPainter::Antialiasing);
        statChartView->setFrameShape(QFrame::NoFrame);
        statChartView->setStyleSheet("background: transparent; border: none;");
        statChartView->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        statChartView->setFixedSize(141, 141);      // match label size exactly
        statChartView->setContentsMargins(0, 0, 0, 0);
        statChartView->setAlignment(Qt::AlignTop | Qt::AlignLeft); // position at (0,0) inside label
        statChartView->setAttribute(Qt::WA_TransparentForMouseEvents);
    } else {
        qDebug() << "Warning: 'stat' label not found in UI";
    }

    updateStatistics();
    loadHistorique();

    qDebug() << "appar_fonction constructor completed successfully";

}

appar_fonction::~appar_fonction()
{
    delete ui;
}

void appar_fonction::on_accueil_clicked()
{
    if (parentWidget()) {
        parentWidget()->show();
    }

    this->close();
}



void appar_fonction::on_play_pause_clicked()
{
    if(IS_Pause == true)
    {
        IS_Pause = false;
        mediaPlayer->play();
        ui->play_pause->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
    }
    else
    {
        IS_Pause = true;
        mediaPlayer->pause();
        ui->play_pause->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    }
}


void appar_fonction::on_stop_clicked()
{
    mediaPlayer->stop();
    IS_Pause = true;
    ui->play_pause->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
}


void appar_fonction::on_mute_clicked()
{
    if (IS_Muted == false)
    {
        previousVolume = ui->volumeSlider->value();
        ui->volumeSlider->setValue(0);
        IS_Muted = true;
        mediaPlayer->audioOutput()->setMuted(true);
        ui->mute->setIcon(style()->standardIcon(QStyle::SP_MediaVolumeMuted));
    }
    else
    {
        ui->volumeSlider->setValue(previousVolume);
        IS_Muted = false;
        mediaPlayer->audioOutput()->setMuted(false);
        ui->mute->setIcon(style()->standardIcon(QStyle::SP_MediaVolume));
    }
}

void appar_fonction::updateStatistics()
{
    // FIXED: Use singleton instance and correct method name
    Connection& conn = Connection::getInstance();
    if (!conn.createConnection()) {
        qDebug() << "Failed to connect to database for statistics";
        return;
    }

    QSqlDatabase db = conn.getDatabase();
    QSqlQuery query(db);


    int totalCount = 0;
    if (query.exec("SELECT COUNT(*) FROM APPARTEMENT")) {
        if (query.next()) {
            totalCount = query.value(0).toInt();
        }
    } else {
        qDebug() << "Error getting total count:" << query.lastError().text();
    }


    int occupeCount = 0;
    query.prepare("SELECT COUNT(*) FROM APPARTEMENT WHERE Etat = :etat");
    query.bindValue(":etat", "Occupé");
    if (query.exec()) {
        if (query.next()) {
            occupeCount = query.value(0).toInt();
        }
    } else {
        qDebug() << "Error getting occupied count:" << query.lastError().text();
    }


    int disponibleCount = 0;
    query.prepare("SELECT COUNT(*) FROM APPARTEMENT WHERE Etat = :etat");
    query.bindValue(":etat", "Disponible");
    if (query.exec()) {
        if (query.next()) {
            disponibleCount = query.value(0).toInt();
        }
    } else {
        qDebug() << "Error getting available count:" << query.lastError().text();
    }


    if (ui->total) {
        ui->total->setText(QString::number(totalCount));
    } else {
        qDebug() << "Warning: 'total' label not found in UI";
    }


    int occupePercent = 0;
    int disponiblePercent = 0;

    if (totalCount > 0) {
        occupePercent = (occupeCount * 100) / totalCount;
        disponiblePercent = (disponibleCount * 100) / totalCount;
    }


    if (ui->Bar_occ) {
        ui->Bar_occ->setMinimum(0);
        ui->Bar_occ->setMaximum(100);
        ui->Bar_occ->setValue(occupePercent);
        ui->Bar_occ->setFormat(QString::number(occupePercent) + "%");
    } else {
        qDebug() << "Warning: 'Bar_occ' progress bar not found in UI";
    }


    if (ui->Bar_dis) {
        ui->Bar_dis->setMinimum(0);
        ui->Bar_dis->setMaximum(100);
        ui->Bar_dis->setValue(disponiblePercent);
        ui->Bar_dis->setFormat(QString::number(disponiblePercent) + "%");
    } else {
        qDebug() << "Warning: 'Bar_dis' progress bar not found in UI";
    }

    if (statChartView) {
        // --- Build pie chart using Qt Charts ---
        QPieSeries *series = new QPieSeries();
        // fallback to avoid empty chart
        const int totalPercent = occupePercent + disponiblePercent;
        const bool hasData = totalPercent > 0;
        const int occupeSlice = hasData ? occupePercent : 66;
        const int dispoSlice = hasData ? disponiblePercent : 34;
        series->append(QStringLiteral("Occupé (%1%)").arg(occupePercent), occupeSlice);
        series->append(QStringLiteral("Disponible (%1%)").arg(disponiblePercent), dispoSlice);

        if (series->slices().size() >= 2) {
            auto *occupeSlicePtr = series->slices()[0];
            occupeSlicePtr->setBrush(QColor("#1E73BE")); // solid blue
            occupeSlicePtr->setPen(Qt::NoPen);           // no border

            auto *dispoSlicePtr = series->slices()[1];
            dispoSlicePtr->setBrush(QColor("#1FA06A")); // solid green
            dispoSlicePtr->setPen(Qt::NoPen);           // no border
        }

        series->setLabelsVisible(false);
        series->setPieSize(0.80);        // leave margin inside 141x141
        series->setHorizontalPosition(0.5);
        series->setVerticalPosition(0.5); // center the pie

        QChart *chart = statChartView->chart();
        if (!chart) {
            chart = new QChart();
            statChartView->setChart(chart);
        } else {
            chart->removeAllSeries();
        }

        chart->addSeries(series);
        chart->setBackgroundVisible(true);
        chart->setBackgroundBrush(Qt::white);
        chart->setBackgroundPen(Qt::NoPen);          // no border around chart
        chart->legend()->setVisible(false);
        chart->setContentsMargins(0, 0, 0, 0);
        chart->setMargins(QMargins(0, 0, 0, 0));
        chart->setBackgroundRoundness(0);
        chart->setTheme(QChart::ChartThemeLight);
        statChartView->setVisible(true);
    } else if (ui->stat) {
        qDebug() << "Stat chart view not initialized";
    } else {
        qDebug() << "Warning: 'stat' placeholder widget not found in UI";
    }
    qDebug() << "Statistics updated - Total:" << totalCount
             << "Occupé:" << occupeCount << "(" << occupePercent << "%)"
             << "Disponible:" << disponibleCount << "(" << disponiblePercent << "%)";
}

void appar_fonction::loadHistorique()
{
    if (!ui->historique) {
        qDebug() << "Warning: 'historique' table widget not found in UI";
        return;
    }

    ui->historique->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->historique->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->historique->setSelectionMode(QAbstractItemView::SingleSelection);
    auto *header = ui->historique->horizontalHeader();
    header->setStretchLastSection(false);
    header->setSectionResizeMode(0, QHeaderView::Interactive);
    header->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    header->setSectionResizeMode(2, QHeaderView::ResizeToContents);

    ui->historique->setRowCount(0);
    ui->historique->setColumnCount(3);
    ui->historique->setHorizontalHeaderLabels({"Date et Heure", "Identifiant", "A_M_S"});

    // FIXED: Use singleton instance and correct method name
    Connection& conn = Connection::getInstance();
    if (!conn.createConnection()) {
        qDebug() << "Failed to connect to database for historique";
        return;
    }

    QSqlDatabase db = conn.getDatabase();
    QSqlQuery query(db);
    const QString historiqueQuery = QStringLiteral(
        "SELECT Date_et_Heure, Id_Appartement, A_M_S "
        "FROM HISTORIQUE ORDER BY Date_et_Heure DESC");
    if (!query.exec(historiqueQuery)) {
        qDebug() << "Failed to fetch historique:" << query.lastError().text();
        return;
    }

    int row = 0;
    while (query.next()) {
        ui->historique->insertRow(row);

        const QVariant dateValue = query.value(0);
        QString dateText;
        if (dateValue.canConvert<QDateTime>()) {
            dateText = dateValue.toDateTime().toString("dd/MM/yyyy HH:mm:ss");
        } else {
            dateText = dateValue.toString();
        }

        ui->historique->setItem(row, 0, new QTableWidgetItem(dateText));
        ui->historique->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));
        ui->historique->setItem(row, 2, new QTableWidgetItem(query.value(2).toString()));

        ++row;
    }


    const int totalWidth = ui->historique->viewport()->width();
    const int dateWidth = static_cast<int>(totalWidth * 0.55);
    ui->historique->setColumnWidth(0, std::max(dateWidth, 200));

    qDebug() << "Historique loaded with" << row << "rows";
}
