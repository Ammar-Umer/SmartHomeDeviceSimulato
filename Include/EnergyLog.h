#ifndef ENERGYLOG_H
#define ENERGYLOG_H
#include "SmartDevice.h"
#include<string>
class SmartDevice;
class EnergyLog {
private:
    std::string logID;
    SmartDevice* deviceRef;
    double kilowattHours;
    std::string timestamp;
public:
    EnergyLog();
    EnergyLog(const std::string& id, SmartDevice* device,double kw, const std::string& timestamp);
    ~EnergyLog();
    std::string getLogID() const {
        return logID;
    }
    double getkilowattHours() const {
        return kilowattHours;
    }
    std::string gettimestamp() const {
        return timestamp;
    }
    void recordUsage(double kwh);
    void getMonthlyReport() const;
    double compareToAverage(double avgKwh) const;
};
#endif
