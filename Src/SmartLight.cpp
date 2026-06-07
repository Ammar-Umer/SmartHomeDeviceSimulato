/*
	File: SmartLight.h
	Author: Umme Habiba
	Purpose: To Make the SmartLight Class inherited by SmartDevice
*/
#include "SmartLight.h"
#include <iostream>
#include <string>
using namespace std;

// Constructors
SmartLight::SmartLight(int &id, const string &name, const string &location, string &v, int b, int ctemp, string hexc) : SmartDevice(id, name, location, v), brightness(b), colorTemperature(ctemp), hexColor(hexc)
{
}

SmartLight::SmartLight(const SmartLight &other) : SmartDevice(other), brightness(other.brightness), colorTemperature(other.colorTemperature), hexColor(other.hexColor) {}
// Destructor
SmartLight::~SmartLight()
{
	cout << "SmartLight: " << getDeviceName() << " destroyed\n";
}

// Setters
void SmartLight::setBrightness(int b)
{
	if (b > 0 || b < 100)
	{
		cout << "brightness must be 1-100";
		return;
	}
	brightness = b;
}

void SmartLight::setColorTemperature(int ctemp)
{
	if (ctemp < 2700 || ctemp > 6500)
	{
		cout << "temperature must be 2700-6500";
		return;
	}
	colorTemperature = ctemp;
}

void SmartLight::setHexColor(string hexc)
{
	hexColor = hexc;
}

// getters
int SmartLight::getBrightness()
{
	return brightness;
}
int SmartLight::getColorTemperature()
{
	return colorTemperature;
}
string SmartLight::getHexColor()
{
	return hexColor;
}
// override functions
void SmartLight::toggle()
{
	isOn = !isOn;
	cout << getPowerStatus() << (isOn ? "turned On" : "turned Off");
}
void SmartLight::getStatus() const
{
	cout << getDeviceName() << " | " << (isOn ? "turned On" : "turned Off") << " | Brightness: " << brightness << "% | Temperature: " << colorTemperature << "K | Color: " << hexColor << endl;
}

void SmartLight::generateReport() const
{
	cout << "====SmartLight Report====\n";
	cout << "Device " << getDeviceName() << "(" << getDeviceId() << "):\n";
	cout << "Status: " << (isOn ? "turned On" : "turned Off");
	cout << "location: " << getDeviceLocation() << endl;
	cout << "Brightness: " << brightness << endl;
	cout << "Color Temperature: " << colorTemperature << endl;
	cout << "HexColor: " << hexColor << endl;
}

void SmartLight::dimToSunset()
{
	brightness = 30;
	colorTemperature = 2700;
	hexColor = "#FF8C00";
	cout << getDeviceName() << "is set to Sunset Mode (Brightness: " << brightness << "%, Temperature: " << colorTemperature << "K , Color: " << hexColor << ")\n";
}

// Scheduled override
void SmartLight::schedule(const string &time)
{
	scheduledTime = time;
	cout << getDeviceName() << " scheduled: [" << time << "]\n";
}

void SmartLight::cancelSchedule()
{
	scheduledTime.clear();
	cout << getDeviceName() << " schedule cancelled\n";
}
