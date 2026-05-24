// SmartLight.h.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#ifndef SMARTLIGHt_H
#define SMARTLIGHT_H

#include <iostream>
#include"SmartDevice.h"
using namespace std;
//interface
class Schedulable {
	public:
		virtual void schedule(const string &time)  = 0;
		virtual void cancelSchedule() = 0;
		virtual ~Schedulable()=0;

};

class SmartLight:public SmartDevice ,public Schedulable{
	int brightness;
	int colorTemperature;
	string hexColor;
	string scheduledTime;
public:
	
	//Parameterized constructor
	SmartLight(int &id,const string &name,const string& location,int b,int ctemp,string hexc);

	//parameterized constructor
	SmartLight(const SmartLight& other);

	//destructor
	~SmartLight(); 

	//getters
	int getBrightness();
	int getColorTemperature();
	string getHexColor();

	//setters
	void setBrightness(int b);
	void setColorTemperature(int ctemp);
	void setHexColor(string hexc);

	void dimToSunset();

	//Override functions
	void toggle()  override;
	string getStatus()override;
	string generateReport()override;

	//Schedule override
	void schedule(const string& time) override;
	void cancelSchedule() override;


};
#endif
