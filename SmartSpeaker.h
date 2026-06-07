#ifndef SmartSpeaker_h
#define SmartSpeaker_h
#include "SmartAppliance.h"

using namespace std;

class Speaker : public Appliance {
private:
	int volume;
	string activeSkill;
	string connectedServices[1000];
public:
	Speaker();
	Speaker(const string& i, const string& n, const string& l, double volume = 50);
	Speaker(Speaker& other);
	~Speaker();
	int getVolume()
	{
		return volume;
	}
	string getActiveSkill() const
	{
		return activeSkill;
	}
	void setVolume(int v);
	void playMusic(const string& s);// s = song
	void triggerSkill(const string& s);//  s = skill
	void connectService(const string& s);// s = service
	void processVoiceCommand(const string& c);
	void toggle() override;
	string getStatus() const override;
	void generateReport() const override;
};

#endif  SmartSpeaker_h