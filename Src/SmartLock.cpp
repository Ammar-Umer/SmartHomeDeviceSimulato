#include "SmartLock.h"
#include <iostream>
using namespace std;

SmartLock::SmartLock(int id, const string& n, const string& l, const string& v, const string& c)
    : SmartAppliance(id, n, l, v, 20.0, "lock"), isLocked(true), accessCode(c), logCount(0) {}

SmartLock::SmartLock(const SmartLock& other)
    : SmartAppliance(other), isLocked(other.isLocked), accessCode(other.accessCode), logCount(other.logCount) {
    for (int i = 0; i < logCount; ++i) {
        accessLog[i] = other.accessLog[i];
    }
}

SmartLock::~SmartLock() {
    cout << "SmartLock " << getDeviceName() << " destroyed.\n";
}

void SmartLock::lock() {
    isLocked = true;
    if (logCount < 1000) {
        accessLog[logCount] = "LOCKED";
        logCount++;
    }
    cout << getDeviceName() << " locked.\n";
}

void SmartLock::unlock(const string& c) {
    if (!verifyCode(c)) {
        if (logCount < 1000) {
            accessLog[logCount] = "FAILED UNLOCK";
            logCount++;
        }
        cout << "ACCESS DENIED! Wrong Code.\n";
        return;
    }
    isLocked = false;
    if (logCount < 1000) {
        accessLog[logCount] = "UNLOCKED";
        logCount++;
    }
    cout << getDeviceName() << " UNLOCKED SUCCESSFULLY :)\n";
}

bool SmartLock::verifyCode(const string& c) const {
    return c == accessCode;
}

void SmartLock::getAccessHistory() const {
    cout << "=================================================================\n";
    cout << "||             Access Log for " << getDeviceName() << "                   ||\n";
    cout << "=================================================================\n";
    for (int i = 0; i < logCount; ++i) {
        cout << i + 1 << ". " << accessLog[i] << endl;
    }
}

void SmartLock::changeCode(const string& oldCode, const string& newCode) {
    if (!verifyCode(oldCode)) {
        cout << "WRONG CURRENT PASSWORD!\n";
        return;
    }
    accessCode = newCode;
    cout << getDeviceName() << " ACCESS CODE CHANGED :)\n";
}

void SmartLock::toggle() {
    if (isLocked) {
        unlock(accessCode);
    } else {
        lock();
    }
}

void SmartLock::getStatus() const {
    cout << getDeviceName() << " | " << (isOn ? "ON" : "OFF") << " | " << (isLocked ? "LOCKED!" : "UNLOCKED :)") << endl;
}

void SmartLock::generateReport() const {
    cout << "=========================================================================================================\n";
    cout << "||                                        SmartLock Report                                             ||\n";
    cout << "=========================================================================================================\n";
    cout << "Device: " << getDeviceName() << " (" << getDeviceId() << " )\n";
    cout << "Location: " << getDeviceLocation() << endl;
    cout << "Status: " << (isLocked ? "LOCKED!" : "UNLOCKED :)") << endl;
    cout << "Log entries: " << logCount << endl;
}
