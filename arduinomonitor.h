#ifndef ARDUINOMONITOR_H
#define ARDUINOMONITOR_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QTimer>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>

class ArduinoMonitor : public QObject
{
    Q_OBJECT

public:
    explicit ArduinoMonitor(QObject *parent = nullptr);
    ~ArduinoMonitor();

    bool connectToArduino(const QString &portName = "");
    void disconnectFromArduino();
    bool isConnected() const;
    QString getPortName() const;

    // Get list of available COM ports
    static QStringList getAvailablePorts();

signals:
    void statusChanged(const QString &codeBarre, const QString &oldStatus, const QString &newStatus);
    void dataReceived(const QString &codeBarre, float temperature, float humidity, const QString &status);
    void errorOccurred(const QString &error);
    void connectionStatusChanged(bool connected);

private slots:
    void readSerialData();
    void handleError(QSerialPort::SerialPortError error);

private:
    QSerialPort *m_serialPort;
    QString m_buffer;

    void processLine(const QString &line);
    bool updateDatabaseStatus(const QString &codeBarre, const QString &newStatus);
    bool updateAllLampsStatus(const QString &newStatus);
};

#endif // ARDUINOMONITOR_H
