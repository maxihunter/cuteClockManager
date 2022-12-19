#include "cuteclockoperator.h"
#include "cuteclock.h"

cuteClockOperator::cuteClockOperator()
{}

void cuteClockOperator::setSerial(QSerialPort& serial)
{
    m_serial = &serial;
}

bool cuteClockOperator::testClock() {
    QString msg = "T\n";
    m_serial->write(msg.toUtf8());
    QString data = m_serial->readAll();
    if (data != "TESTOK")
        return false;
    return true;
}

bool cuteClockOperator::getClockInfo(cuteClock* clock) {
    QString msg = "V\n";
    m_serial->write(msg.toUtf8());
    QString data = m_serial->readAll();
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
    QString msg;
    // Do some magic with serial port
    QString conf_str = msg.split("|")[1];
    QStringList args = conf_str.split(";");
    for (auto it = args.begin(); it < args.end(); it++) {
        QStringList values = (*it).split("=");
        if (values[0] == "t") {

        }
        if (values[0] == "d") {

        }
        if (values[0] == "l") {

        }
        if (values[0] == "h") {

        }
    }
    return true;
}

bool cuteClockOperator::setClockMode(cuteClock* clock) {
    return true;
}
bool cuteClockOperator::setLEDMode(cuteClock* clock) {
    QString cmd = QString("l=%1").arg(clock->getLedMode());
    return true;
};
bool cuteClockOperator::setHSVMode(cuteClock* clock) {
    QString cmd = QString("h=%1").arg(clock->getHsvMode());
    return true;
};
bool cuteClockOperator::setTime(cuteClock* clock) {
    return true;
};
bool cuteClockOperator::setDate(cuteClock* clock) {
    return true;
};

bool cuteClockOperator::setHourAlarmMode(cuteClock* clock) {
    QString cmd = QString("b=%1").arg(clock->getHourAlarmMode());
    return true;
};
bool cuteClockOperator::setNightHours(cuteClock* clock) {
    QString cmd = QString("n=%1").arg(clock->getNightHours());
    return true;
};
bool cuteClockOperator::setAlarmHours(cuteClock* clock) {
    QString cmd = QString("A=%1")
            .arg(clock->getAlarmTime().toString("hh"));
    return true;
};
bool cuteClockOperator::setAlarmMinutes(cuteClock* clock) {
    QString cmd = QString("a=%1")
            .arg(clock->getAlarmTime().toString("mm"));
    return true;
};
bool cuteClockOperator::setTimeFormat(cuteClock* clock) {
    QString cmd = QString("m=%1").arg(clock->getTimeFormat());
    return true;
};
bool cuteClockOperator::setAlarmTime(cuteClock* clock) {
    return true;
};
