#include "arduinomonitor.h"
#include "connection.h"
#include <QSqlDatabase>
#include <QDateTime>

ArduinoMonitor::ArduinoMonitor(QObject *parent)
    : QObject(parent)
    , m_serialPort(nullptr)
{
    m_serialPort = new QSerialPort(this);
    connect(m_serialPort, &QSerialPort::readyRead, this, &ArduinoMonitor::readSerialData);
    connect(m_serialPort, &QSerialPort::errorOccurred, this, &ArduinoMonitor::handleError);
}

ArduinoMonitor::~ArduinoMonitor()
{
    disconnectFromArduino();
    delete m_serialPort;
}

bool ArduinoMonitor::connectToArduino(const QString &portName)
{
    if (m_serialPort->isOpen()) {
        m_serialPort->close();
    }

    QString portToUse = portName;
    if (portToUse.isEmpty()) {
        auto ports = getAvailablePorts();
        if (!ports.isEmpty()) {
            portToUse = ports.first();
        } else {
            qDebug() << "No COM ports available";
            emit errorOccurred("No COM ports available");
            return false;
        }
    }

    qDebug() << "Setting up serial port:" << portToUse;

    m_serialPort->setPortName(portToUse);
    m_serialPort->setBaudRate(QSerialPort::Baud9600);
    m_serialPort->setDataBits(QSerialPort::Data8);
    m_serialPort->setParity(QSerialPort::NoParity);
    m_serialPort->setStopBits(QSerialPort::OneStop);
    m_serialPort->setFlowControl(QSerialPort::NoFlowControl);

    qDebug() << "Attempting to open port:" << portToUse;

    if (m_serialPort->open(QIODevice::ReadWrite)) {
        qDebug() << "Port opened successfully:" << portToUse;
        emit connectionStatusChanged(true);
        return true;
    } else {
        QString error = m_serialPort->errorString();
        qDebug() << "Failed to open port" << portToUse << ":" << error;
        emit errorOccurred("Failed to open port " + portToUse + ": " + error);
        return false;
    }
}

void ArduinoMonitor::disconnectFromArduino()
{
    if (m_serialPort && m_serialPort->isOpen()) {
        m_serialPort->close();
        emit connectionStatusChanged(false);
        qDebug() << "Disconnected from Arduino";
    }
}

bool ArduinoMonitor::isConnected() const
{
    return m_serialPort && m_serialPort->isOpen();
}

QString ArduinoMonitor::getPortName() const
{
    if (m_serialPort) {
        return m_serialPort->portName();
    }
    return QString();
}

QStringList ArduinoMonitor::getAvailablePorts()
{
    QStringList ports;
    qDebug() << "=== SCANNING FOR COM PORTS ===";

    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        qDebug() << "Port:" << info.portName()
        << "| Description:" << info.description()
        << "| Manufacturer:" << info.manufacturer()
        << "| System Location:" << info.systemLocation();

        if (!info.portName().isEmpty()) {
            ports.append(info.portName());
        }
    }

    qDebug() << "Found" << ports.size() << "COM port(s):" << ports;
    qDebug() << "============================";

    return ports;
}

void ArduinoMonitor::readSerialData()
{
    if (!m_serialPort || !m_serialPort->isOpen()) {
        return;
    }

    QByteArray data = m_serialPort->readAll();
    m_buffer += QString::fromUtf8(data);

    int newlineIndex;
    while ((newlineIndex = m_buffer.indexOf('\n')) != -1) {
        QString line = m_buffer.left(newlineIndex).trimmed();
        m_buffer = m_buffer.mid(newlineIndex + 1);

        if (!line.isEmpty()) {
            processLine(line);
        }
    }
}

void ArduinoMonitor::handleError(QSerialPort::SerialPortError error)
{
    if (error != QSerialPort::NoError) {
        QString errorMsg = "Serial port error: " + m_serialPort->errorString();
        qDebug() << errorMsg;
        emit errorOccurred(errorMsg);
        disconnectFromArduino();
    }
}

void ArduinoMonitor::processLine(const QString &line)
{
    qDebug() << "Arduino raw data:" << line;

    if (line.startsWith("MONITOR:")) {
        QStringList parts = line.mid(8).split(":");
        if (parts.size() >= 4) {
            QString codeBarre = "ALL_LAMPS";
            float temperature = parts[0].toFloat();
            float humidity = parts[1].toFloat();
            QString status = parts[3];

            emit dataReceived(codeBarre, temperature, humidity, status);
        }
    }
    else if (line.startsWith("UPDATE_ALL_LAMPS:")) {
        QString newStatus = line.mid(17).trimmed();
        qDebug() << "Updating all lamps to status:" << newStatus;
        if (updateAllLampsStatus(newStatus)) {
            qDebug() << "All lamps status updated to:" << newStatus;
        }
    }
    else if (line.startsWith("ERROR:")) {
        qDebug() << "Arduino error:" << line.mid(6);
    }
    else if (!line.isEmpty()) {
        qDebug() << "Unknown Arduino message:" << line;
    }
}

bool ArduinoMonitor::updateDatabaseStatus(const QString &codeBarre, const QString &newStatus)
{
    Connection& conn = Connection::getInstance();
    if (!conn.createConnection()) {
        qDebug() << "Failed to connect to database";
        return false;
    }

    QSqlDatabase db = conn.getDatabase();
    QSqlQuery query(db);
    query.prepare("UPDATE MATERIEL SET ETAT = :etat WHERE CODE_BARRE = :code_barre");
    query.bindValue(":etat", newStatus);
    query.bindValue(":code_barre", codeBarre);

    if (query.exec()) {
        qDebug() << "Database updated:" << codeBarre << "->" << newStatus;
        return true;
    } else {
        qDebug() << "Database update failed:" << query.lastError().text();
        return false;
    }
}

bool ArduinoMonitor::updateAllLampsStatus(const QString &newStatus)
{
    Connection& conn = Connection::getInstance();
    if (!conn.createConnection()) {
        qDebug() << "Failed to connect to database";
        return false;
    }

    QSqlDatabase db = conn.getDatabase();
    QSqlQuery query(db);
    query.prepare("UPDATE MATERIEL SET ETAT = :etat WHERE TYPE_MAT = 'Lampe'");
    query.bindValue(":etat", newStatus);

    if (query.exec()) {
        qDebug() << "All lamps status updated to:" << newStatus;
        return true;
    } else {
        qDebug() << "Failed to update all lamps:" << query.lastError().text();
        return false;
    }
}

// Add this line at the VERY END of the file:
#include "arduinomonitor.moc"
