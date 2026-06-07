#include "Automation.h"
#include <iostream>
#include <string>
using namespace std;

Automation::Automation()
{
    ruleID = "Auto000";
    triggerCondition = "none";
    triggerTime = "00:00";
    active = false;
}

Automation::Automation(const string id, const string condition, const string time)
{
    ruleID = id;
    triggerCondition = condition;
    triggerTime = time;
    active = false;
}

Automation::~Automation() {}

string Automation::getruleID() const { return ruleID; }
bool Automation::isactive() const { return active; }
string Automation::gettriggerCondition() const { return triggerCondition; }

void Automation::activate()
{
    active = true;
    cout << "Automation[" << ruleID << "] Activated" << endl;
}

void Automation::deactivate()
{
    active = false;
    cout << "Automation[" << ruleID << "] Deactivated" << endl;
}

void Automation::addAction(SmartDevice *device, const string &action)
{
    cout << "Action added: " << action << " on " << device->getDeviceName() << endl;
}

void Automation::editRule(const string &newcondition, const string &newtime)
{
    triggerCondition = newcondition;
    triggerTime = newtime;
    cout << "Rule[" << ruleID << "] updated" << endl;
}

void Automation::evaluateTrigger(const string &currentcondition)
{
    if (!active) {
        cout << "Rule inactive" << endl;
        return;
    }
}
void Automation::showAutomation(){
    cout<<"Rule Id: "<<getruleID()<<endl;
    cout<<"Trigger Condition:"<<gettriggerCondition()<<endl;
    cout<<"Is Active: "<<(isactive()?"ON":"OFF") <<endl;
}
