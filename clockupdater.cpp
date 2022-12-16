#include "clockupdater.h"
#include "cuteclock.h"

clockUpdater::clockUpdater()
{
}

bool clockUpdater::createTmpFolder() const {
    if (!QDir("./tmp/").exists()) {
        if (!QDir::mkdir("./tmp/")) {
            return false;
        }
    }
    return true;
}

int clockUpdater::getCheckForUpdate(cuteClock* clock) const {
    return 0;
}