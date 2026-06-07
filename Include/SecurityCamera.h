//SecurityCamera.h
#ifndef SECURITYCAMERA_H
#define SECURITYCAMERA_H

#include"SmartDevice.h"
#include<iostream>
#include<string>

class SecurityCamera :public SmartDevice {

	std::string resolution;
	 
	int motionSensitivity;
	int angle;

	bool isRecording=false;


public:
	
	// constructors
	SecurityCamera(int id, const std::string& name, const std::string& location, const std::string& v, std::string r, int sen, int a);
	SecurityCamera(const SecurityCamera& other);

	// destructor
	~SecurityCamera();

	// getters
	std::string getResolution() const;
	int getMotionSensitivity() const;
	int getAngle() const;


	// setters
	void setResolution(std::string r);
	void setMotionSensitivity(int sen);
	void setAngle(int a);
	
	void startRecording();
	void setMotionAlert(bool m);
	void captureSnapshot();
	
	// Override functions
	void toggle() override;
	void getStatus() const override;
	void generateReport() const override;


};
#endif
