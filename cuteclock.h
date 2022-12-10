#ifndef CUTECLOCK_H
#define CUTECLOCK_H

/*ledAction[0] = stripRollingRainbow;
  ledAction[1] = stripStaticRainbow;
  ledAction[2] = stripCircleRainbow;
  ledAction[3] = stripPulseRainbow;
  ledAction[4] = stripArrowDots;
  ledAction[5] = stripArrowOverlap;
  ledAction[6] = stripArrowDotsSec;
  ledAction[7] = stripArrowOverlapSec;
  ledAction[8] = stripStaticCustom;
  ledAction[9] = stripPulseCustom;
*/
class cuteClock
{
private:
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
public:
    cuteClock();

    int getLedMode() const;
    void setLedMode(int a_val);

    int getLedBrightness() const;
    void setLedBrightness(int a_val);

    int getHsvMode() const;
    void setHsvMode(int a_val);

    int getHourAlarmMode() const;
    void setHourAlarmMode(int a_val);

    int getHightHours() const;
    void setHightHours(int a_val);

    int getAlarmHours() const;
    void setAlarmHours(int a_val);

    int getAlarmMinutes() const;
    void setAlarmMinutes(int a_val);

    int getTimeFormat() const;
    void setTimeFormat(int a_val);
};

#endif // CUTECLOCK_H
