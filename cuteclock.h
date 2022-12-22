#ifndef CUTECLOCK_H
#define CUTECLOCK_H

#include <QTime>
#include <QDate>

#include "clockversion.h"

#define ALARM_MODE_OFFSET 0x0
#define ALARM_MODE_MASK 0x2
#define SUNRISE_MODE_OFFSET 0x2
#define SUNRISE_MODE_MASK 0x2
#define BEEP_OFFSET 4
#define BEEP_MASK 1

class cuteClock
{
private:

    int m_version_major;
    int m_version_minor;
    int m_revision_num;

    int m_ledMode;
    int m_ledBrightness;
    int m_hsvMode;
    // XXXX XXXX - byte data
    // 3210
    // 01 - normal alarm mode (0 - off, 1 - on LED, 2 - sound alarm)
    // 32 - sunrise mode (0 - off, othen prerun: 1 - 15 minute; 2 - 30 minutes; 3 - 60 minutes)
    int m_hourAlarmMode;
    int m_night_hours;
    int m_alarm_hours;
    int m_alarm_minutes;
    int m_time_format;
    QTime time;
    QTime alarm_time;
    QDate date;
    clockVersion m_version;

public:
    cuteClock();

    int getVersionMajor() const;
    int getVersionMinor() const;
    clockVersion getVersion() const;
    void setVersion(int a_major, int a_minor);
    void setVersion(clockVersion a_ver);

    int getRevision() const;
    void setRevision(int a_rev);

    int getLedMode() const;
    void setLedMode(int a_val);

    int getLedBrightness() const;
    void setLedBrightness(int a_val);

    int getHsvMode() const;
    void setHsvMode(int a_val);

    int getRawAlarmMode() const;
    void setRawAlarmMode(int a_val); // raw value

    int getAlarmMode() const;
    void setAlarmMode(int a_val);

    bool getHourlyBeep() const;
    void setHourlyBeep(int a_val);

    int getSunricePrerun() const;
    void setSunricePrerun(int a_val);

    int getNightHours() const;
    void setNightHours(int a_val);

    int getAlarmHours() const;
    void setAlarmHours(int a_val);

    int getAlarmMinutes() const;
    void setAlarmMinutes(int a_val);

    int getTimeFormat() const;
    void setTimeFormat(int a_val);

    QTime getTime() const;
    void setTime(QTime& a_val);

    QTime getAlarmTime() const;
    void setAlarmTime(QTime& a_val);

    QDate getDate() const;
    void setDate(QDate& a_val);
};

#endif // CUTECLOCK_H
