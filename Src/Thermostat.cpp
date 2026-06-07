/*file:Thermostat.cpp
Author:Umme Habiba*/

#include "Thermostat.h"
#include <iostream>
#include <string>
using namespace std;

// constructor
Thermostat::Thermostat(int id, const string &name, const string &location, const string &v, double tt, double ct, string m) : SmartDevice(id, name, location, v), targetTemperature(tt), currentTemperature(ct), mode(m) {}

Thermostat::Thermostat(const Thermostat &other) : SmartDevice(other), targetTemperature(other.targetTemperature), currentTemperature(other.currentTemperature),
                                                  mode(other.mode), scheduledTime(other.scheduledTime) {}

// destructor
Thermostat::~Thermostat()
{
    cout << getDeviceName() << " [thermostat] is destroyed \n";
}

// getters
double Thermostat::getTargetTemperature() const
{
    return targetTemperature;
}

double Thermostat::getCurrentTemperature() const
{
    return currentTemperature;
}

string Thermostat::getMode() const
{
    return mode;
}

// setters
void Thermostat::setTargetTemperature(double tt)
{
    if (tt < 10 || tt > 35)
    {
        cout << "temperature must be in 10-35\n";
        return;
    }
    targetTemperature = tt;
}

void Thermostat::setCurrentTemperature(double ct)
{
    currentTemperature = ct;
}

void Thermostat::changeMode(const string &m)
{
    if (m != "heat" && m != "cool" && m != "auto")
    {
        cout << "invalid input. Input must be heat/cool/auto\n";
        return;
    }
    mode = m;
    cout << "Mode changed to " << m << endl;
}

// schedule(interface) override
void Thermostat::schedule(const string &time)
{
    scheduledTime = time;
    cout << getDeviceName() << " scheduled: [" << time << "]\n";
}

void Thermostat::cancelSchedule()
{
    scheduledTime.clear();
    cout << "Schedule cancelled\n";
}

// Override functions
void Thermostat::toggle()
{
    isOn = !isOn;
    cout << getDeviceName() << (isOn ? " turned ON " : " turned OFF ") << "in Mode :" << mode << endl;
}

void Thermostat::getStatus() const
{
    cout << getDeviceName() << " | " << (isOn ? " turned On " : " turned Off ") << "| Mode: " << mode << " | Current Temperature: " << currentTemperature << " | Target Temperature: " << targetTemperature << endl;
}

void Thermostat::generateReport() const
{
    cout << "====Thermostat Report====\n";
    cout << "Device: " << getDeviceName() << " (" << getDeviceId() << ")\n";
    cout << "Location: " << getDeviceLocation() << endl;
    cout << "Status: " << (isOn ? " turned ON " : " turned OFF ") << endl;
    cout << "Mode: " << mode << endl;
    cout << "Target Temperature: " << targetTemperature << endl;
    cout << "Current Temperature : " << currentTemperature << endl;
}
