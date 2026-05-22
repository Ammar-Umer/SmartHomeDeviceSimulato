/*
File Name: SmartDevice.cpp
Author : Muhammad Ammar Umer
Purpose: Make Abstract Class of SmartDevice
*/

#include "..\include\SmartDevice.h"

int SmartDevice::count = 0;
// Costructor
SmartDevice::SmartDevice(int id, string n, string loc,string v)
{
    deviceId = id;
    deviceName = n;
    location = loc;
    firmwareVersion=v;
    isOn = false;

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

string SmartDevice::getDeviceVersion() const
{
    return firmwareVersion;
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

void SmartDevice::setDeviceVersion(string v)
{
    firmwareVersion = v;
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

bool SmartDevice::operator==(const SmartDevice &other)
{
    return (deviceId == other.deviceId);
}

ostream &operator<<(ostream &out, const SmartDevice &device)
{
    out << "ID: " << device.deviceId << endl;
    out << "Name: " << device.deviceName << endl;
    out << "Location: " << device.location << endl;
    out << "Firmware Version: " << device.firmwareVersion << endl;
    out << "Power: " << (device.isOn ? "ON" : "OFF") << endl;
    return out;
}
