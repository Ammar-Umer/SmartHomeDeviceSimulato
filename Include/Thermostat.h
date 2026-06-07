// Thermostat.h

#ifndef THERMOSTAT_H
#define THERMOSTAT_H
#include"SmartDevice.h"
#include"SmartLight.h"
#include <iostream>
#include <string>

class Thermostat:public SmartDevice,public Schedulable {
    double targetTemperature;
    double currentTemperature;
    std::string mode;
    std::string scheduledTime;
public:
    // constructors
    Thermostat(int id, const std::string& name, const std::string& location, const std::string& v, double tt, double ct, std::string m);

    Thermostat(const Thermostat& other);

    // destructor
    ~Thermostat();

    // getters
    double getTargetTemperature()const;
    double getCurrentTemperature()const;
std::string getMode() const;

    // setters
    void setTargetTemperature(double tt);
    void setCurrentTemperature(double ct);
    void changeMode(const std::string& m);

    // schedule(interface) override
    void schedule(const std::string& time) override;
    void cancelSchedule() override;

    // Override functions
    void toggle() override;
void getStatus()const override;
    void generateReport()const override;


};
#endif
