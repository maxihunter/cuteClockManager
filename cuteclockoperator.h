#ifndef CUTECLOCKOPERATOR_H
#define CUTECLOCKOPERATOR_H

#include <QObject>
#include <QSerialPort>

class cuteClock;

class cuteClockOperator
{
public:
    cuteClockOperator(QSerialPort* serial);

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

private:
    QSerialPort* m_serial;

};

#endif // CUTECLOCKOPERATOR_H
