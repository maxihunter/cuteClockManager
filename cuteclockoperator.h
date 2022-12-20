#ifndef CUTECLOCKOPERATOR_H
#define CUTECLOCKOPERATOR_H

#include <QObject>
#include <QDebug>
#include <QSerialPort>

class cuteClock;

class cuteClockOperator
{
public:
    cuteClockOperator();
    
    void setSerial(QSerialPort& serial);

    bool testClock();
    bool getClockInfo(cuteClock* clock);
    bool readClockConfig(cuteClock* clock);

    bool setClockMode(cuteClock* clock);
    bool setLEDMode(cuteClock* clock);
    bool setHSVMode(cuteClock* clock);
    bool setTime(cuteClock* clock);
    bool setDate(cuteClock* clock);

    bool setHourAlarmMode(cuteClock* clock);
    bool setNightHours(cuteClock* clock);
    bool setAlarmHours(cuteClock* clock);
    bool setAlarmMinutes(cuteClock* clock);
    bool setTimeFormat(cuteClock* clock);
    bool setAlarmTime(cuteClock* clock);

    QString getLastError() const;

private:

    bool sendCommand(QString& output, QString command);

    QSerialPort* m_serial;
    QString lastError;

};

#endif // CUTECLOCKOPERATOR_H
