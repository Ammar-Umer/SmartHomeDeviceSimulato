#include "SmartAppliance.h"
#include <iostream>
using namespace std;

SmartAppliance::SmartAppliance(int id, const string& n, const string& l, const string& v, double p, const string& r)
    : SmartDevice(id, n, l, v), powerRating(p), runMode(r) {}

SmartAppliance::SmartAppliance(const SmartAppliance& other)
    : SmartDevice(other), powerRating(other.powerRating), runMode(other.runMode) {}

SmartAppliance::~SmartAppliance() {
    cout << "SmartAppliance " << getDeviceName() << " destroyed.\n";
}

double SmartAppliance::getPowerRating() const { return powerRating; }
string SmartAppliance::getRunMode() const { return runMode; }
void SmartAppliance::setPowerRating(double p) { powerRating = p; }
void SmartAppliance::setRunMode(const string& r) { runMode = r; }

void SmartAppliance::startCycle() {
    if (!isOn) {
        cout << getDeviceName() << " must be ON first.\n";
        return;
    }
    cout << getDeviceName() << " started a cycle in " << runMode << " mode.\n";
}

double SmartAppliance::getPowerUsage(double hours) const {
    return (powerRating * hours) / 1000.0;
}

void SmartAppliance::toggle() {
    isOn = !isOn;
    cout << getDeviceName() << (isOn ? " turned ON" : " turned OFF") << endl;
}

void SmartAppliance::getStatus() const {
    string state = isOn ? "ON" : "OFF";
    cout << getDeviceName() << " | " << state << " | Power: " << powerRating << "W | Mode: " << runMode << endl;
}

void SmartAppliance::generateReport() const {
    cout << "=========================================================================================================\n";
    cout << "||                                     SmartAppliance Report                                           ||\n";
    cout << "=========================================================================================================\n";
    cout << "Device : " << getDeviceName() << " (" << getDeviceId() << " )\n";
    cout << "Location : " << getDeviceLocation() << endl;
    cout << "Status : " << (isOn ? "ON" : "OFF") << endl;
    cout << "Power : " << powerRating << " W\n";
    cout << "Mode : " << runMode << endl;
}
