#ifndef SMARTLIGHT_H
#define SMARTLIGHT_H

#include <iostream>
#include <string>
#include "SmartDevice.h"

// interface
class Schedulable
{
public:
	virtual void schedule(const std::string &time) = 0;
	virtual void cancelSchedule() = 0;
	virtual ~Schedulable() = default;
};

class SmartLight : public SmartDevice, public Schedulable
{
	int brightness;
	int colorTemperature;
	std::string hexColor;
	std::string scheduledTime;

public:
	// Parameterized constructor
	SmartLight(int &id, const std::string &name, const std::string &location, std::string &v, int b, int ctemp, std::string hexc);

	// Copy constructor
	SmartLight(const SmartLight &other);

	// destructor
	~SmartLight();

	// getters
	int getBrightness();
	int getColorTemperature();
	std::string getHexColor();

	// setters
	void setBrightness(int b);
	void setColorTemperature(int ctemp);
	void setHexColor(std::string hexc);

	void dimToSunset();

	// Override functions
	void toggle() override;
	void getStatus() const override;
	void generateReport() const override;

	// Schedule override
	void schedule(const std::string &time) override;
	void cancelSchedule() override;
};
#endif
