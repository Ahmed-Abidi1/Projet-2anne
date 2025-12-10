#include "mate_fonc.h"
#include "ui_mate_fonc.h"

#include <QPixmap>
#include <QDebug>
#include <QMessageBox>
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

// Qt Charts includes - use explicit namespace or Qt5/Qt6 compatible approach
#include <QChartView>
#include <QChart>
#include <QBarSet>
#include <QBarSeries>
#include <QBarCategoryAxis>
#include <QValueAxis>

#include <QPieSeries>       // ← PIE CHART
#include <QPieSlice>        // ← SLICES

mate_fonc::mate_fonc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mate_fonc),
    m_chart(nullptr),
    m_chartType(nullptr),
    m_chartView(nullptr),
    m_chartViewType(nullptr)
{
    ui->setupUi(this);

    QPixmap pix("C:/Users/samar/OneDrive/Bureau/projet C++/logo.png");
    ui->logo->setPixmap(pix.scaled(90, 90, Qt::KeepAspectRatio));

    QPixmap stat_pix("C:/Users/samar/OneDrive/Bureau/projet C++/stat_ahmed.jpg");
    ui->stat->setPixmap(stat_pix.scaled(1200, 500, Qt::KeepAspectRatio));

    setupNotificationTable();

    connect(ui->supprimer2, &QPushButton::clicked, this, &mate_fonc::on_supprimer2_clicked);
}

mate_fonc::~mate_fonc()
{
    delete ui;
    // Clean up chart pointers
    delete m_chartView;
    delete m_chartViewType;
}

void mate_fonc::on_accueil_clicked()
{
    if (parentWidget()) {
        parentWidget()->show();
    }
    this->close();
}

void mate_fonc::setupNotificationTable()
{
    QStringList notificationHeaders;
    notificationHeaders << "Date" << "Notifications";

    ui->tableWidget_3->setColumnCount(2);
    ui->tableWidget_3->setHorizontalHeaderLabels(notificationHeaders);
    ui->tableWidget_3->setRowCount(0);

    ui->tableWidget_3->setColumnWidth(0, 200); // Date column
    ui->tableWidget_3->setColumnWidth(1, 700); // Notification column
}

void mate_fonc::addNotification(const QString &message)
{
    QString currentDateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    int row = ui->tableWidget_3->rowCount();
    ui->tableWidget_3->insertRow(row);
    ui->tableWidget_3->setItem(row, 0, new QTableWidgetItem(currentDateTime));
    ui->tableWidget_3->setItem(row, 1, new QTableWidgetItem(message));
    ui->tableWidget_3->scrollToBottom();

    qDebug() << "Notification added:" << message;
}

void mate_fonc::on_supprimer2_clicked()
{
    ui->tableWidget_3->setRowCount(0);
    QMessageBox::information(this, "Notifications", "Toutes les notifications ont été supprimées.");
}

void mate_fonc::updateStatistics()
{
    qDebug() << "=== UPDATE STATISTICS CALLED ===";

    // Only update if we're on page 2


    qDebug() << "On statistics page, creating new charts...";

    // Debug: Show ALL data in database
    QSqlQuery debugQuery;
    debugQuery.exec("SELECT CODE_BARRE, NOM_MATR, TYPE_MAT, ETAT FROM MATERIEL");

    qDebug() << "=== ALL MATERIALS IN DATABASE ===";
    int materialCount = 0;
    while (debugQuery.next()) {
        materialCount++;
        qDebug() << "Material" << materialCount << ":"
                 << "Code:" << debugQuery.value(0).toString()
                 << "Nom:" << debugQuery.value(1).toString()
                 << "Type:" << debugQuery.value(2).toString()
                 << "Etat:" << debugQuery.value(3).toString();
    }
    qDebug() << "Total materials:" << materialCount;

    // COMPLETELY CLEAR the groupBox
    QLayout *existingLayout = ui->groupBox_4->layout();
    if (existingLayout) {
        QLayoutItem *item;
        while ((item = existingLayout->takeAt(0)) != nullptr) {
            if (item->widget()) {
                item->widget()->setParent(nullptr);
                delete item->widget();
            }
            delete item;
        }
        delete existingLayout;
    }

    // Create new horizontal layout
    QHBoxLayout *mainLayout = new QHBoxLayout(ui->groupBox_4);
    mainLayout->setAlignment(Qt::AlignCenter);
    mainLayout->setSpacing(30);

    // ===== ETAT CHART =====
    QChart *chartEtat = new QChart();
    chartEtat->setTitle("Statistiques par État");
    chartEtat->setTitleFont(QFont("Arial", 12, QFont::Bold));

    // FIXED QUERY: Remove the WHERE clause to include ALL materials
    QSqlQuery etatQuery;
    etatQuery.exec("SELECT ETAT, COUNT(*) FROM MATERIEL GROUP BY ETAT");

    QPieSeries *seriesEtat = new QPieSeries();
    int etatTotal = 0;

    qDebug() << "=== ETAT STATISTICS ===";
    while (etatQuery.next()) {
        QString etat = etatQuery.value(0).toString();
        int count = etatQuery.value(1).toInt();
        etatTotal += count;

        // Handle NULL or empty states
        if (etat.isEmpty()) {
            etat = "Non spécifié";
        }

        qDebug() << "Etat:" << etat << "Count:" << count;

        QPieSlice *slice = seriesEtat->append(etat + " (" + QString::number(count) + ")", count);

        if (etat == "En Reparation") slice->setColor(QColor(255, 165, 0));
        else if (etat == "En Panne") slice->setColor(QColor(255, 0, 0));
        else if (etat == "En Cours d'Utilisation") slice->setColor(QColor(0, 128, 0));
        else if (etat == "Non spécifié") slice->setColor(QColor(128, 128, 128));
        else slice->setColor(QColor(70, 130, 180)); // Default blue
    }

    qDebug() << "Total Etat count:" << etatTotal;

    // If no data, show empty state
    if (seriesEtat->slices().isEmpty()) {
        seriesEtat->append("Aucune donnée (0)", 1)->setColor(QColor(200, 200, 200));
        qDebug() << "No Etat data found!";
    }

    for (QPieSlice *slice : seriesEtat->slices()) {
        slice->setLabelVisible(true);
        slice->setLabelFont(QFont("Arial", 9));
    }

    chartEtat->addSeries(seriesEtat);
    chartEtat->legend()->setVisible(true);
    chartEtat->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartViewEtat = new QChartView(chartEtat);
    chartViewEtat->setRenderHint(QPainter::Antialiasing);
    chartViewEtat->setMinimumSize(350, 300);

    // ===== TYPE CHART =====
    QChart *chartType = new QChart();
    chartType->setTitle("Statistiques par Type");
    chartType->setTitleFont(QFont("Arial", 12, QFont::Bold));

    QStringList allowedTypes = {"Électronique", "Mécanique", "Informatique", "Mobilier", "Outillage", "Autre"};
    QPieSeries *seriesType = new QPieSeries();
    int typeTotal = 0;

    qDebug() << "=== TYPE STATISTICS ===";

    // FIXED QUERY: Check for ALL types including empty ones
    QSqlQuery allTypesQuery;
    allTypesQuery.exec("SELECT TYPE_MAT, COUNT(*) FROM MATERIEL GROUP BY TYPE_MAT");

    while (allTypesQuery.next()) {
        QString type = allTypesQuery.value(0).toString();
        int count = allTypesQuery.value(1).toInt();
        typeTotal += count;

        // Handle NULL or empty types
        if (type.isEmpty()) {
            type = "Non spécifié";
        }

        qDebug() << "Type:" << type << "Count:" << count;

        // Only add if it's one of the allowed types or unspecified
        if (allowedTypes.contains(type) || type == "Non spécifié") {
            seriesType->append(type + " (" + QString::number(count) + ")", count);
        }
    }

    qDebug() << "Total Type count:" << typeTotal;

    // If no data, show empty state
    if (seriesType->slices().isEmpty()) {
        seriesType->append("Aucune donnée (0)", 1)->setColor(QColor(200, 200, 200));
        qDebug() << "No Type data found!";
    }

    // Apply colors
    QList<QColor> typeColors = {
        QColor(70, 130, 180),   // Électronique
        QColor(220, 20, 60),    // Mécanique
        QColor(30, 144, 255),   // Informatique
        QColor(218, 165, 32),   // Mobilier
        QColor(46, 139, 87),    // Outillage
        QColor(148, 0, 211),    // Autre
        QColor(128, 128, 128)   // Non spécifié
    };

    int colorIndex = 0;
    for (QPieSlice *slice : seriesType->slices()) {
        slice->setColor(typeColors[colorIndex % typeColors.size()]);
        slice->setLabelVisible(true);
        slice->setLabelFont(QFont("Arial", 9));
        colorIndex++;
    }

    chartType->addSeries(seriesType);
    chartType->legend()->setVisible(true);
    chartType->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartViewType = new QChartView(chartType);
    chartViewType->setRenderHint(QPainter::Antialiasing);
    chartViewType->setMinimumSize(350, 300);

    // Add both charts to layout
    mainLayout->addWidget(chartViewEtat);
    mainLayout->addWidget(chartViewType);

    // Store pointers
    m_chart = chartEtat;
    m_chartType = chartType;
    m_chartView = chartViewEtat;
    m_chartViewType = chartViewType;

    qDebug() << "=== CHARTS CREATED ===";
    qDebug() << "Etat slices:" << seriesEtat->slices().count();
    qDebug() << "Type slices:" << seriesType->slices().count();
}

QString mate_fonc::getProgressBarStyle(const QString &state)
{
    if (state == "En Reparation") {
        return "QProgressBar { border: 2px solid grey; border-radius: 5px; text-align: center; }"
               "QProgressBar::chunk { background-color: #FFA500; }";
    } else if (state == "En Panne") {
        return "QProgressBar { border: 2px solid grey; border-radius: 5px; text-align: center; }"
               "QProgressBar::chunk { background-color: #FF0000; }";
    } else { // En Cours d'Utilisation
        return "QProgressBar { border: 2px solid grey; border-radius: 5px; text-align: center; }"
               "QProgressBar::chunk { background-color: #008000; }";
    }
}
