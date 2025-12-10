#ifndef MATE_FONC_H
#define MATE_FONC_H

#include <QDialog>

// Forward declarations for Qt Charts
QT_BEGIN_NAMESPACE
class QChart;
class QChartView;
QT_END_NAMESPACE

namespace Ui {
class mate_fonc;
}

class mate_fonc : public QDialog
{
    Q_OBJECT

public:
    explicit mate_fonc(QWidget *parent = nullptr);
    ~mate_fonc();

    void addNotification(const QString &message);
    void updateStatistics();
    QString getProgressBarStyle(const QString &state);

private slots:
    void on_accueil_clicked();
    void on_supprimer2_clicked();

private:
    Ui::mate_fonc *ui;
    void setupNotificationTable();

    // Add these chart pointers
    QChart *m_chart;
    QChart *m_chartType;
    QChartView *m_chartView;
    QChartView *m_chartViewType;
};

#endif // MATE_FONC_H
