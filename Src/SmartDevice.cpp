/*
File Name: SmartDevice.cpp
Author : Muhammad Ammar Umer
Purpose: Make Abstract Class of SmartDevice
*/

#include "SmartDevice.h"
#include"EnergyLog.h"
#include <iostream>
using namespace std;
std::vector<EnergyLog *> logs;
int SmartDevice::count = 0;
// Constructor
SmartDevice::SmartDevice(int id, string n, string loc, string typ)
{
    deviceId = id;
    deviceName = n;
    location = loc;
    type = typ;
    isOn = false;
    count++;
}

// Copy Constructor
SmartDevice::SmartDevice(const SmartDevice& other)
    : deviceId(other.deviceId),
      deviceName(other.deviceName),
      location(other.location),
      type(other.type),
      isOn(other.isOn)
{
    count++;
}

// Destructor
SmartDevice::~SmartDevice()
{
    count--;
}

// Getters

int SmartDevice::getDeviceId() const
{
    return deviceId;
}

string SmartDevice::getDeviceName() const
{
    return deviceName;
}

string SmartDevice::getDeviceLocation() const
{
    return location;
}

string SmartDevice::getDeviceType() const
{
    return type;
}

bool SmartDevice::getPowerStatus() const
{
    return isOn;
}

// Setters

void SmartDevice::setDeviceId(int id)
{
    deviceId = id;
}

void SmartDevice::setDeviceName(string n)
{
    deviceName = n;
}

void SmartDevice::setDeviceLocation(string loc)
{
    location = loc;
}

void SmartDevice::setDeviceType(string typ)
{
    type = typ;
}

void SmartDevice::setPowerStatus(bool p)
{
    isOn = p;
}
// Member Fn
void SmartDevice::restart()
{
    cout << "Restarting..." << endl;
}

bool SmartDevice::operator==(const SmartDevice& other)
{
    return (deviceId == other.deviceId);
}

ostream& operator<<(ostream& out, const SmartDevice& device)
{
    out << "ID: " << device.deviceId << endl;
    out << "Name: " << device.deviceName << endl;
    out << "Location: " << device.location << endl;
    out << "Type: " << device.type << endl;
    out << "Power: " << (device.isOn ? "ON" : "OFF") << endl;
    return out;
}

