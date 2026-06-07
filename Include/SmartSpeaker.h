#ifndef SMARTSPEAKER_H
#define SMARTSPEAKER_H
#include "SmartAppliance.h"
#include <string>

class SmartSpeaker : public SmartAppliance
{
private:
    int volume;
    std::string activeSkill;
    std::string connectedServices[1000];
    int serviceCount;

public:
    SmartSpeaker(int id, const std::string& n, const std::string& l, const std::string& v, int vol);
    SmartSpeaker(const SmartSpeaker& other);
    ~SmartSpeaker();

    void setVolume(int v);
    void playMusic(const std::string& s);
    void triggerSkill(const std::string& skill);
    void connectService(const std::string& s);
    void processVoiceCommand(const std::string& command);

    void toggle() override;
    void getStatus() const override;
    void generateReport() const override;
};

#endif
