#ifndef SmartAppliance_h
#define SmartAppliance_h
#include "SmartDevice.h"
#include <string>
using namespace std;

class Appliance :public SmartDevice {
protected:
	double powerRating;
	string runMode;
public:
	Appliance();
	Appliance(const string& id, const string& name, const string& location, double powerRating = 100.0, const string& runMode = "standard");
	Appliance(const Appliance& other);
	virtual ~Appliance();
	double getPowerRating() const 
	{ 
		return powerRating; 
	}
	string getRunMode() const
	{
		return runMode;
	}
	void setRunMode(const string r)
	{
		runMode = r;
	}
	virtual void toggle () override;
	virtual string getStatus () const override;
	virtual void generateReport () const override;
	virtual void startcycle ();
	double getPowerUsage (double h) const;
};



#endif SmartAppliance_h