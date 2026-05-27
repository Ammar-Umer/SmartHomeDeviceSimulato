#include "SmartAppliance.h"
#include <iostream>

Appliance::Appliance() : SmartDevice("APP000", "Default Appliance", "Kitchen"), powerRating(100.0), runMode("standard"){
}
Appliance::Appliance(const string& id, const string& n, const string& l, double p, const string& r) {
	SmartDevice(id, n, l);
	powerRating = p;
	runMode = r;
}
Appliance::Appliance(const Appliance& other) {
	SmartDevice(other);
	powerRating = other.powerRating;
	runMode = other.runMode;
}
Appliance:: ~Appliance() {
	cout << "SmartAppliance" << name << " destroyed." << endl;
}
void Appliance::toggle() {
    if (isOn == true) {
        isOn = false;
        cout << name << " turned OFF" << endl;
    }
    else {
        isOn = ture;
        cout << name << " turned ON" << endl;
    }
}
Appliance::getStatus() const {
    string state;
    if (isOn) {
        state = "ON";
    }
    else {
        state = "OFF";
    }
    string status = name + " | " + state;
    status += " | Power: " + to_string(powerRating) + "W";
    status += " | Mode: " + runMode;
    return status;
}

void Appliance::generateReport() const {
    cout << "=========================================================================================================" << endl;
    cout << "||                                     SmartAppliance Report                                           ||" << endl;
    cout << "=========================================================================================================" << endl;
    cout << "Device : " << name << " (" << deviceID << " )" << endl;
    cout << "Location : " << location << endl;
    cout << "State : " << (isOn ? "ON" : "OFF") << endl;
    cout << "Power : " << powerRating << " W" << endl;
    cout << "Mode : " << runMode << endl;
}
void Appliance::startcycle() {
    if (!isOn) {
        cout << name << " must be ON first." << endl;
        return;
    } <
        cout << name << " started a cycle in " << runMode << " mode." << endl;
}
double Appliance::getPowerUsage(double h) const {
    return (powerRating * hours) / 1000.0;
}