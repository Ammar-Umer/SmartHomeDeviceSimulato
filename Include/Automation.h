#ifndef Automation_h
#define Automation_h
#include <string>
#include "SmartDevice.h"
#include <functional>

struct AutoAction
{
	std::string action;
	SmartDevice *target;
};
class Automation
{
private:
	std::string ruleID;
	std::string triggerCondition;
	std::string triggerTime;
	AutoAction actionlist[1000];
	bool active;

public:
	Automation();
	Automation(const std::string id, const std::string condition, const std::string time);
	~Automation();
	std::string getruleID() const;
	bool isactive() const;
	std::string gettriggerCondition() const;
	void activate();
	void deactivate();
	void addAction(SmartDevice *device, const std::string &action);
	void editRule(const std::string &newcondition, const std::string &newtime);
	void evaluateTrigger(const std::string &CurrentCondition);
	void showAutomation();
};
#endif
