// SecurityCamera.cpp
#include "SecurityCamera.h"
#include <iostream>
using namespace std;

SecurityCamera::SecurityCamera(int id, const string& name, const string& location, const string& v, string r, int sen, int a)
    : SmartDevice(id, name, location, v), resolution(r), motionSensitivity(sen), angle(a), isRecording(false) {}

SecurityCamera::SecurityCamera(const SecurityCamera& other)
    : SmartDevice(other), resolution(other.resolution), motionSensitivity(other.motionSensitivity),
    angle(other.angle), isRecording(other.isRecording) {}

SecurityCamera::~SecurityCamera() {
    cout << getDeviceName() << " [camera] is destroyed\n";
}

string SecurityCamera::getResolution() const { return resolution; }
int SecurityCamera::getMotionSensitivity() const { return motionSensitivity; }
int SecurityCamera::getAngle() const { return angle; }

void SecurityCamera::setResolution(string r) { resolution = r; }
void SecurityCamera::setMotionSensitivity(int sen) { motionSensitivity = sen; }
void SecurityCamera::setAngle(int a) { angle = a; }

void SecurityCamera::startRecording() {
    isRecording = true;
    cout << getDeviceName() << " started recording\n";
}

void SecurityCamera::setMotionAlert(bool m) {
    cout << getDeviceName() << " motion alert " << (m ? "enabled" : "disabled") << endl;
}

void SecurityCamera::captureSnapshot() {
    cout << getDeviceName() << " captured snapshot at " << angle << " degrees\n";
}

void SecurityCamera::toggle() {
    isOn = !isOn;
    cout << getDeviceName() << (isOn ? " turned ON" : " turned OFF") << endl;
}

void SecurityCamera::getStatus() const {
    cout << getDeviceName() << " | " << (isOn ? "ON" : "OFF") << " | Resolution: " << resolution
         << " | Angle: " << angle << " | Recording: " << (isRecording ? "Yes" : "No") << endl;
}

void SecurityCamera::generateReport() const {
    cout << "====Security Camera Report====\n";
    cout << "Device: " << getDeviceName() << " (" << getDeviceId() << ")\n";
    cout << "Location: " << getDeviceLocation() << endl;
    cout << "Status: " << (isOn ? "ON" : "OFF") << endl;
    cout << "Resolution: " << resolution << endl;
    cout << "Angle: " << angle << endl;
    cout << "Recording: " << (isRecording ? "Yes" : "No") << endl;
}
