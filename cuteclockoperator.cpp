#include "cuteclockoperator.h"
#include "cuteclock.h"

cuteClockOperator::cuteClockOperator()
{}

void cuteClockOperator::setSerial(QSerialPort& serial)
{
    m_serial = &serial;
    QString output;
    sendCommand(output, QString());
    if (output.contains("Ready\r\nOK\r\n")) {
        qDebug() << "Looks ok";
    }
}

bool cuteClockOperator::testClock() {
    QString msg = "T\n";
    QString data;
    sendCommand(data, msg);
    if (data.contains("TESTOK")) {
        return true;
    }
    return false;
}

bool cuteClockOperator::getClockInfo(cuteClock* clock) {
    QString msg = "V\n";
    QString data;
    sendCommand(data, msg);
    if (data.length() <= 0)
        return false;
    QStringList conf_str = data.split("|");
    if (conf_str.size() <= 0)
        return false;
    QStringList version = conf_str[0].split(".");
    if (conf_str.size() <= 0)
        return false;
    clock->setVersion(version[0].toInt(), version[1].toInt());
    clock->setRevision(conf_str[1].toInt());
    return true;
}

bool cuteClockOperator::readClockConfig(cuteClock* clock) {
    QString msg = "R\n";
    QString data;
    QString new_data;
    sendCommand(data, msg);

    if (!data.contains("ROK|")) {
        return false;
    }
    QString conf_str = data.split("|")[1];
    QStringList args = conf_str.split(";");
    for (auto it = args.begin(); it < args.end(); it++) {
        QStringList values = (*it).split("=");
        qDebug() << "value=" << (*it);
        if (values[0].contains("t")) {
            QTime time = QTime::fromString(values[1], "hh:mm:ss");
            clock->setTime(time);
            qDebug() << "values[0]=" << values[0] << ":" << time.toString();
            continue;
        }
        if (values[0].contains("d")) {
            QDate date = QDate::fromString(values[1], "dd.MM.yyyy");
            qDebug() << "values[0]=" << values[0] << ":" << date.toString();
            continue;
        }
        if (values[0].contains("l")) {
            clock->setLedMode(values[1].toInt());
            continue;
        }
        if (values[0].contains("h")) {
            clock->setHsvMode(values[1].toInt());
            continue;
        }
        if (values[0].contains("b")) {
            clock->setAlarmMode(values[1].toInt());
            continue;
        }
        if (values[0].contains("n")) {
            clock->setNightHours(values[1].toInt());
            continue;
        }
        if (values[0].contains("A")) {
            clock->setAlarmHours(values[1].toInt());
            continue;
        }
        if (values[0].contains("a")) {
            clock->setAlarmMinutes(values[1].toInt());
            continue;
        }
        if (values[0].contains("m")) {
            clock->setTimeFormat(values[1].toInt());
            continue;
        }
    }
    return true;
}

bool cuteClockOperator::setClockMode(cuteClock* /*clock*/) {
    return true;
}
bool cuteClockOperator::setLEDMode(cuteClock* clock) {
    QString cmd = QString("l=%1").arg(clock->getLedMode());
    QString data;
    sendCommand(data, cmd);
    if (data != "OK") {
        return false;
    }
    return true;
};
bool cuteClockOperator::setHSVMode(cuteClock* clock) {
    QString cmd = QString("h=%1").arg(clock->getHsvMode());
    QString data;
    sendCommand(data, cmd);
    if (data != "OK") {
        return false;
    }
    return true;
};
bool cuteClockOperator::setTime(cuteClock* clock) {
    QString cmd = QString("t=%1").arg(clock->getTime().toString("hh:mm"));
    QString data;
    sendCommand(data, cmd);
    if (data != "OK") {
        return false;
    }
    return true;
};
bool cuteClockOperator::setDate(cuteClock* clock) {
    QString cmd = QString("d=%1").arg(clock->getDate().toString("dd.MM.yyyy"));
    QString data;
    sendCommand(data, cmd);
    if (data != "OK") {
        return false;
    }
    return true;
};

bool cuteClockOperator::setHourAlarmMode(cuteClock* clock) {
    QString cmd = QString("b=%1").arg(clock->getAlarmMode());
    QString data;
    sendCommand(data, cmd);
    if (data != "OK") {
        return false;
    }
    return true;
};
bool cuteClockOperator::setNightHours(cuteClock* clock) {
    QString cmd = QString("n=%1").arg(clock->getNightHours());
    QString data;
    sendCommand(data, cmd);
    if (data != "OK") {
        return false;
    }
    return true;
};
bool cuteClockOperator::setAlarmHours(cuteClock* clock) {
    QString cmd = QString("A=%1")
            .arg(clock->getAlarmTime().toString("hh"));
    QString data;
    sendCommand(data, cmd);
    if (data != "OK") {
        return false;
    }
    return true;
};
bool cuteClockOperator::setAlarmMinutes(cuteClock* clock) {
    QString cmd = QString("a=%1")
            .arg(clock->getAlarmTime().toString("mm"));
    QString data;
    sendCommand(data, cmd);
    if (data != "OK") {
        return false;
    }
    return true;
};
bool cuteClockOperator::setTimeFormat(cuteClock* clock) {
    QString cmd = QString("m=%1").arg(clock->getTimeFormat());
    QString data;
    sendCommand(data, cmd);
    if (data != "OK") {
        return false;
    }
    return true;
};
bool cuteClockOperator::setAlarmTime(cuteClock* clock) {
    QString cmd = QString("A=%1").arg(clock->getAlarmHours());
    QString data;
    sendCommand(data, cmd);
    if (data != "OK") {
        return false;
    }
    cmd = QString("a=%1").arg(clock->getAlarmMinutes());
    data.clear();
    sendCommand(data, cmd);
    if (data != "OK") {
        return false;
    }
    return true;
}
bool cuteClockOperator::sendCommand(QString& output, QString command)
{
    if (!m_serial->isOpen())
        return false;
    if (!command.isEmpty()) {
        qDebug() << "Attempt to write data:" << command << " (" << command.length() << ") chars";
        m_serial->write(command.toUtf8());
    }
    // Block until new data arrives
    // Wait for 5 seconds for new data
    int readbytes = 0;
    while (!output.contains("\r\n")) {
        if (!m_serial->waitForReadyRead(7000)) {
            lastError = m_serial->errorString();
            qDebug() << "error: " << lastError;
            break;
        }
        readbytes += m_serial->bytesAvailable();
        output.append(m_serial->readAll());
    }
    qDebug() << "New data available: " << readbytes << " bytes";
    qDebug() << output;

    if (!output.contains("\r\n"))
        return false;
    return true;
}

QString cuteClockOperator::getLastError() const {
    return lastError;
}