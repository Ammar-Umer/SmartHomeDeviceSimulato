
#include <iostream>

using namespace std;

Speaker::Speaker() 
{
	Appliance("SPK000", "Default Speaker", "Living Room", 50.0, "audio");
	volume = 50;
	activeSkill = "none";
	count = 0;
}

Speaker::Speaker(const string& i, const string& n, const string& l, int v) 
{
	Appliance(i, n, l, 50.0, "audio");
	volume = v;
	activeSkill = "none";
	count = 0;
}

Speaker::Speaker(const Speaker& other)
{
	Appliance(other);
	volume = other.volume;
	activeSkill = other.activeSkill;
	count(other.count) {
		connectedServices[i] = other.connectedServices[i];
	}
}

Speaker::~Speaker() {
	cout << "SmartSpeaker " << name << " destroyed." << endl;
}

void Speaker::setVolume(int v) 
{
	if (v < 0 || v>100) 
	{
		cout << "Volume must be 0-100" << endl;
		return;
	}
	volume = v;
	cout << name << " VOLUME SET to " << volume << endl;
}

void Speaker::playMusic(const string& s)
{
	if (!isOn)
	{
		cout << name << " is OFF." << endl;
		return;
	}
	cout << name << " PLAYING: " << s << " (vol: " << volume << " )" << endl;
}

void Speaker::triggerSkill(const string& skill)
{
	activeSkill = skill;
	cout << "Cannot connect more sevices." << endl;
}

void Speaker::connectService(const string& s) 
{
	if (count >= 1000) {
		cout << "Cannot connect more services." << endl;
		return;
    }
	connectedServices[count] = service;
	count++;
	cout << service << " connected to " << name << endl;
}

void Speaker::toggle() 
{
	isOn = !isOn;
	cout << name << (isOn ? " turned ON" : " turned OFF") << endl;
}

string Speaker::getStatus() const 
{
	return name + " | " + (isOn ? "ON" : "OFF") + " | Volume: " + to_string(volume) + "% | Skill: " + activeSkill;
}

void SmartSpeaker::processVoiceCommand(const string& command) {
    cout << name << " received command: \"" << command << "\"\n";

    string cmd = command;

    for (int i = 0; i < cmd.length(); i++) {
        if (cmd[i] >= 'A' && cmd[i] <= 'Z') {
            cmd[i] = cmd[i] + 32;
        }
    }

    if (cmd.find("turn on") != std::string::npos) {
        cout << "  -> Routing: turn on device\n";
    } else if (cmd.find("play") != std::string::npos) {
        cout << "  -> Routing: play music\n";
    } else if (cmd.find("set temperature") != std::string::npos) {
        cout << "  -> Routing: set thermostat\n";
    } else {
        cout << "  -> Command not recognized.\n";
    }
}

void Speaker::generateReport() const
{
	cout << "=========================================================================================================" << endl;
	cout << "||                                     SmartSpeaker Report                                             ||" << endl;
	cout << "=========================================================================================================" << endl;
	cout << "Device: " << name << " (" << deviceID << ")" << endl;
	cout << "Location: " << location << endl;
	cout << "State: " << (isOn ? "ON" : "OFF") << endl;
	cout << "Volume: " << volume << "%" << endl;
	cout << "Skill: " << activeSkill << endl;
	cout << "Services: " << count << " connected" << endl;
}