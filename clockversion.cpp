#include "clockversion.h"

clockVersion::clockVersion()
{
}

int clockVersion::getVersionMajor() const {

}

int clockVersion::getVersionMinor() const {

}

void clockVersion::setVersion(int a_major, int a_minor) {

}

QString clockVersion::toString() const {

}

clockVersion& clockVersion::operator=(const clockVersion& a_val) {
    m_version_major = a_val.m_version_major;
    m_version_minor = a_val.m_version_minor;
    return *this;
}

bool clockVersion::operator==(const clockVersion& a_val) const {
    if (m_version_major != a_val.m_version_major) {
        return false;
    }
    if (m_version_minor != a_val.m_version_minor) {
        return false;
    }
    return true;
}

bool clockVersion::operator>(const clockVersion& a_val) const {
    if (m_version_major > a_val.m_version_major) {
        return true;
    } 
    if (m_version_major >= a_val.m_version_major && 
        m_version_minor > a_val.m_version_minor) {
        return true;
    }
    return false;
}

bool clockVersion::operator<(const clockVersion& a_val) const {
    if (m_version_major < a_val.m_version_major) {
        return true;
    }
    if (m_version_major <= a_val.m_version_major &&
        m_version_minor < a_val.m_version_minor) {
        return true;
    }
    return false;
}
