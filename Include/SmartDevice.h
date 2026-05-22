#ifndef SMARTDEVICE_H
#define SMARTDEVICE_H

#include <iostream>
#include <string>
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
    SmartDevice(int id, string n, string loc, string v);

    // Copy Constructor
    SmartDevice(const SmartDevice &obj);

    // Destructor
    virtual ~SmartDevice();

    // Getters
    int getDeviceId() const;
    string getDeviceName() const;
    string getDeviceLocation() const;
    string getDeviceVersion() const;
    bool getPowerStatus() const;

    // Setters
    void setDeviceId(int);
    void setDeviceName(string);
    void setDeviceLocation(string);
    void setDeviceVersion(string);
    void setPowerStatus(bool);

    // Pure Virtual Fn
    virtual void toggle() = 0;
    virtual void getStatus() const = 0;
    virtual void generateReport() const = 0;

    // Normal Virtual Fn
    virtual void restart();

    // Opreator Overloading
    bool operator==(const SmartDevice &other);

    // Friend Function
    friend ostream &operator<<(ostream &out, const SmartDevice &device);
};

#endif