#include "clockversion.h"

clockVersion::clockVersion()
{
}

int clockVersion::getVersionMajor() const {
    return m_version_major;
}

int clockVersion::getVersionMinor() const {
    return m_version_minor;
}

void clockVersion::setVersion(int a_major, int a_minor) {
    m_version_major = a_major;
    m_version_minor = a_minor;
}

QString clockVersion::toString() const {
    return QString("v%1.%2").arg(m_version_major).arg(m_version_minor);
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
