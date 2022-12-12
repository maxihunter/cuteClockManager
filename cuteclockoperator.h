#ifndef CUTECLOCKOPERATOR_H
#define CUTECLOCKOPERATOR_H

#include <QObject>

class cuteClock;

class cuteClockOperator
{
public:
    cuteClockOperator();

    static bool testClock();
    static bool readClockConfig(cuteClock* clock);

    static bool setClockMode(cuteClock* clock);
    static bool setLEDMode(cuteClock* clock);
    static bool setHSVMode(cuteClock* clock);
    static bool setTime(cuteClock* clock);
    static bool setDate(cuteClock* clock);

    static bool setHourAlarmMode(cuteClock* clock);
    static bool setNightHours(cuteClock* clock);
    static bool setAlarmHours(cuteClock* clock);
    static bool setAlarmMinutes(cuteClock* clock);
    static bool setTimeFormat(cuteClock* clock);
    static bool setAlarmTime(cuteClock* clock);

};

#endif // CUTECLOCKOPERATOR_H
