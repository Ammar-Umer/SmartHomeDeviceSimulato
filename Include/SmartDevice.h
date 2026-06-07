#ifndef SMARTDEVICE_H
#define SMARTDEVICE_H

#include <iostream>
#include <string>
#include <vector>
class EnergyLog;
class SmartDevice
{
private:
    int deviceId;
    std::string deviceName;
    std::string location;
    std::string type;

protected:
    bool isOn;

public:
    int static count;

    // Default Constructor
    SmartDevice(int id, std::string n, std::string loc, std::string typ);

    // Copy Constructor
    SmartDevice(const SmartDevice &obj);

    // Destructor
    virtual ~SmartDevice();

    // Getters
    int getDeviceId() const;
    std::string getDeviceName() const;
    std::string getDeviceLocation() const;
    std::string getDeviceType() const;
    bool getPowerStatus() const;

    // Setters
    void setDeviceId(int);
    void setDeviceName(std::string);
    void setDeviceLocation(std::string);
    void setDeviceType(std::string);
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
    friend std::ostream &operator<<(std::ostream &out, const SmartDevice &device);
};

#endif