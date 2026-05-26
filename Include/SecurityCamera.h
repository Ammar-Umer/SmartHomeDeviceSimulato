//SecurityCamera.h
#ifndef SECURITYCAMERA_H
#define SECURITYCAMERA_H

#include"SmartDevice.h"
#include<iostream>
using namespace std;


class SecurityCamera :public SmartDevice {

	string resolution;
	 
	int motionSensitivity;
	int angle;

	bool isRecording=false;


public:
	
	//constructors
	SecurityCamera(int id, const string& location, const string& name, string r, int sen, int a);
	SecurityCamera(const SecurityCamera& other);

	//destructor
	~SecurityCamera() {};

	//getters
	string getResolution() const;
	int getMotionSensitivity()const;
	int getAngle() const;


	//setters
	void setResolution(string r);
	void setMotionSensitivity(int sen);
	void setAngle(int a);
	
	void startRecording();
	void setMotionAlert(bool m);
	void captureSnapshot();
	
	//Override functions
	void toggle()override;
	void setStatus()override;
	void generateReport()override;



};
#endif