#ifndef SMARTAPPLIANCE_H
#define SMARTAPPLIANCE_H
#include "SmartDevice.h"
#include <string>

class SmartAppliance : public SmartDevice
{
protected:
    double powerRating;
    std::string runMode;

public:
    SmartAppliance(int id, const std::string& n, const std::string& l, const std::string& v, double p, const std::string& r);
    SmartAppliance(const SmartAppliance& other);
    virtual ~SmartAppliance();

    double getPowerRating() const;
    std::string getRunMode() const;
    void setPowerRating(double p);
    void setRunMode(const std::string& r);

    virtual void startCycle();
    virtual double getPowerUsage(double hours) const;

    virtual void toggle() override;
    virtual void getStatus() const override;
    virtual void generateReport() const override;
};

#endif
