#ifndef CLOCVERSION_H
#define CLOCVERSION_H

#include <QString>

class clockVersion
{
private:
    int m_version_major;
    int m_version_minor;

public:
    clockVersion();

    int getVersionMajor() const;
    int getVersionMinor() const;
    void setVersion(int a_major, int a_minor);

    QString toString() const;

    clockVersion& operator=(const clockVersion& a_val);
    bool operator==(const clockVersion& a_val) const;
    bool operator>(const clockVersion& a_val) const;
    bool operator<(const clockVersion& a_val) const;


};

#endif // CLOCVERSION_H
