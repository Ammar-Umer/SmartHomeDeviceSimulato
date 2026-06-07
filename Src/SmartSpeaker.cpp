#include "SmartSpeaker.h"
#include <iostream>
#include <algorithm>
using namespace std;

SmartSpeaker::SmartSpeaker(int id, const string& n, const string& l, const string& v, int vol)
    : SmartAppliance(id, n, l, v, 50.0, "audio"), volume(vol), activeSkill("none"), serviceCount(0) {}

SmartSpeaker::SmartSpeaker(const SmartSpeaker& other)
    : SmartAppliance(other), volume(other.volume), activeSkill(other.activeSkill), serviceCount(other.serviceCount) {
    for (int i = 0; i < serviceCount; ++i) {
        connectedServices[i] = other.connectedServices[i];
    }
}

SmartSpeaker::~SmartSpeaker() {
    cout << "SmartSpeaker " << getDeviceName() << " destroyed.\n";
}

void SmartSpeaker::setVolume(int v) {
    if (v < 0 || v > 100) {
        cout << "Volume must be 0-100\n";
        return;
    }
    volume = v;
    cout << getDeviceName() << " VOLUME SET to " << volume << endl;
}

void SmartSpeaker::playMusic(const string& s) {
    if (!isOn) {
        cout << getDeviceName() << " is OFF.\n";
        return;
    }
    cout << getDeviceName() << " PLAYING: " << s << " (vol: " << volume << " )\n";
}

void SmartSpeaker::triggerSkill(const string& skill) {
    activeSkill = skill;
    cout << getDeviceName() << " triggered skill: " << skill << endl;
}

void SmartSpeaker::connectService(const string& s) {
    if (serviceCount >= 1000) {
        cout << "Cannot connect more services.\n";
        return;
    }
    connectedServices[serviceCount] = s;
    serviceCount++;
    cout << s << " connected to " << getDeviceName() << endl;
}

void SmartSpeaker::processVoiceCommand(const string& command) {
    cout << getDeviceName() << " received command: \"" << command << "\"\n";
    string cmd = command;
    transform(cmd.begin(), cmd.end(), cmd.begin(), ::tolower);
    if (cmd.find("turn on") != string::npos) {
        cout << "  -> Routing: turn on device\n";
    } else if (cmd.find("play") != string::npos) {
        cout << "  -> Routing: play music\n";
    } else if (cmd.find("set temperature") != string::npos) {
        cout << "  -> Routing: set thermostat\n";
    } else {
        cout << "  -> Command not recognized.\n";
    }
}

void SmartSpeaker::toggle() {
    isOn = !isOn;
    cout << getDeviceName() << (isOn ? " turned ON" : " turned OFF") << endl;
}

void SmartSpeaker::getStatus() const {
    cout << getDeviceName() << " | " << (isOn ? "ON" : "OFF") << " | Volume: " << volume << "% | Skill: " << activeSkill << endl;
}

void SmartSpeaker::generateReport() const {
    cout << "=========================================================================================================\n";
    cout << "||                                     SmartSpeaker Report                                             ||\n";
    cout << "=========================================================================================================\n";
    cout << "Device: " << getDeviceName() << " (" << getDeviceId() << ")\n";
    cout << "Location: " << getDeviceLocation() << endl;
    cout << "State: " << (isOn ? "ON" : "OFF") << endl;
    cout << "Volume: " << volume << "%\n";
    cout << "Skill: " << activeSkill << endl;
    cout << "Services: " << serviceCount << " connected\n";
}
