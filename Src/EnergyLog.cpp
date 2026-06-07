#include "EnergyLog.h"
#include"SmartDevice.h"
#include <iostream>
#include <string>
using namespace std;

EnergyLog::EnergyLog() {
    logID = "LOG000";
    deviceRef = nullptr;
    kilowattHours = 118.7;
    timestamp = "30 Days";
}

EnergyLog::EnergyLog(const string& id, SmartDevice* device,double kw, const string& ts) {
    logID = id;
    deviceRef = device;
    kilowattHours = kw;
    timestamp = ts;
}

EnergyLog::~EnergyLog() {
    deviceRef = nullptr;
}

void EnergyLog::recordUsage(double kwh) {
    kilowattHours += kwh;
    cout << "Recorded " << kwh << " kWh for " << (deviceRef ? deviceRef->getDeviceName() : "Unknown") << endl;
}

void EnergyLog::getMonthlyReport() const {
    cout << "=== Energy Report [" << logID << "] ===" << endl;
    cout << "Device: " << (deviceRef ? deviceRef->getDeviceName() : "Unknown") << endl;
    cout << "Timestamp: " << timestamp << endl;
    cout << "Total kWh: " << kilowattHours << endl;
}

double EnergyLog::compareToAverage(double avgKwh) const {
    double diff = kilowattHours - avgKwh;
    cout << "Usage vs avg: " << (diff >= 0 ? "+" : "") << diff << " kWh\n";
    return diff;
}
