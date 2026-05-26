// Thermostat.h

#ifndef THERMOSTAT_H
#define THERMOSTAT_H
#include"SmartDevice.h"
#include"SmartLight.h"
#include <iostream>
using namespace std;



class Thermostat:public SmartDevice,public Schedulable {

	double targetTemperature;
	double currentTemperature;
	string mode;
	string scheduledTime;
public:
	//constructors
	Thermostat(int id, const string& name, const string& location, double tt, double ct, string m);

	Thermostat(const Thermostat& other);
	 
	//destructor
	~Thermostat() {};

	//getters
	double getTargetTemperature()const;
	double getCurrentTemperature()const;
string getMode() const;

	//setters
	void setTargetTemperature(double tt);
	void setCurrentTemperature(double ct);
	void changeMode(const std::string& m);

	//schedule(interface) override
	void schedule(const string& time) override;
	void cancelSchedule() override;

	//Override functions
	void toggle() override;
void getStatus()const override;
	void generateReport()const override;



};
#endif

