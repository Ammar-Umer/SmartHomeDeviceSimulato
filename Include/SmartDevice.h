#ifndef SMARTDEVICE_H
#define SMARTDEVICE_H

#include <iostream>
using namespace std;
class SmartDevice
{
private:
    int deviceId;
    string deviceName;
    string location;
    string firmwareVersion;

protected:
    bool isOn;

public:
    int static count;

    // Default Constructor
    SmartDevice();

    // Parameterized Constructor
    SmartDevice(int id, string n, string loc, string version);

    // Destructor
    virtual ~SmartDevice();

    // Getters
    int getDeviceId();
    string getDeviceName()const;
    string getDeviceLocation()const;
    string getFirmwareVersion()const;
    bool getPowerStatus()const;

    // Setters
    void setDeviceId(int);
    void setDeviceName(string);
    void setDeviceLocation(string);
    
};

#endif