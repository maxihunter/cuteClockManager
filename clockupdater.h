#ifndef CLOCKUPDATER_H
#define CLOCKUPDATER_H

#include <QTime>
#include <QDate>
#include <QDir>
#include <cuteClock>

class clockUpdater
{
private:
    bool createTmpFolder() const;

public:
    clockUpdater();

    static int getCheckForUpdate(cuteClock* clock) const;

};

#endif // CLOCKUPDATER_H
