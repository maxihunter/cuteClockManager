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

int cuteClock::getHightHours() const {
    return m_night_hours;
};
void cuteClock::setHightHours(int a_val) {
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
