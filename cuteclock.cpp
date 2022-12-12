#include "cuteclock.h"

cuteClock::cuteClock()
{
}

int cuteClock::getLedMode() const {
    return m_ledMode;
};
void cuteClock::setLedMode(int a_val) {
    m_ledMode = a_val;
};

int cuteClock::getLedBrightness() const {
    return m_ledBrightness;
};
void cuteClock::setLedBrightness(int a_val) {
    m_ledBrightness = a_val;
};

int cuteClock::getHsvMode() const {
    return m_hsvMode;
};
void cuteClock::setHsvMode(int a_val) {
    m_hsvMode = a_val;
};

int cuteClock::getHourAlarmMode() const {
    return m_hourAlarmMode;
};
void cuteClock::setHourAlarmMode(int a_val) {
    m_hourAlarmMode = a_val;
};

int cuteClock::getNightHours() const {
    return m_night_hours;
};
void cuteClock::setNightHours(int a_val) {
    m_night_hours = a_val;
};

int cuteClock::getAlarmHours() const {
    return m_alarm_hours;
};
void cuteClock::setAlarmHours(int a_val) {
    m_alarm_hours = a_val;
};

int cuteClock::getAlarmMinutes() const {
    return m_alarm_minutes;
};
void cuteClock::setAlarmMinutes(int a_val) {
    m_alarm_minutes = a_val;
};

int cuteClock::getTimeFormat() const {
    return m_time_format;
};
void cuteClock::setTimeFormat(int a_val) {
    m_time_format = a_val;
};

QTime cuteClock::getTime() const {
    return time;
}
void cuteClock::setTime(QTime& a_val) {
    time = a_val;
}

QTime cuteClock::getAlarmTime() const {
    return alarm_time;
}
void cuteClock::setAlarmTime(QTime& a_val) {
    alarm_time = a_val;
}

QDate cuteClock::getDate() const {
    return date;
}
void cuteClock::setDate(QDate& a_val) {
    date = a_val;
}
