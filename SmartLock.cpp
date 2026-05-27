#include "SmartLock.h"
#include <iostream>

using namespace std;

Lock:: Lock()
{
	Appliance("LK000", "Default Lock", "Front Door", 20.0, "lock");
	isLocked(true);
	accessCode("0000");
	logCount(0);
}
Lock:: Lock(const string& i, const string& n, const string& l, const string& c)
{
	Appliance(i, n, l, 20.0, "lock");
	isLocked(true);
	accessCode(c);
	logCount(0);
}
Lock:: Lock(const Lock& other) 
{
	Appliance(other);
	isLocked(other.isLocked);
	accessCode(other.accessCode);
	logCount(other.logCount) {
		for (int i = 0;i < logCount;i++)
		{
			accessLog[i] = other.accessLog[i];
		}
	}
}
Lock:: ~Lock()
{
	cout << "SmartLock " << name << " destroyed." << endl;
}
void Lock::lock() {
	isLocked = true;
	if (logCount < 1000)
	{
		accessLog[logCount] = "LOCKED";
		logCount++;
	}
}
void Lock::unlock(const string& c)
{
	if (!verifyCode(code)) 
	{
		if (logCount < 1000) 
		{
			accessLog[logCount] = "FAILED UNLOCK" << endl;
			logCount++;
		}
		cout << "ACCESS DENIED!!!!!!!!! Wrong Code." << endl;
		return;
	}
	isLocked = false;
	if (logCount < 1000) 
	{
		accessLog[logCount] = "UNLOCKED";
		logCount++;
	}
	cout << name << " UNLOCKED SUCCESSFULLY :)" << endl;
}
bool Lock::verifyCode(const string& c) const
{
	return c == accessCode;
}
void Lock::getAccessHistory() const
{
	cout << "=================================================================" << endl;
	cout << "||             Access Log for " << name << "                   ||" << endl;
	cout << "=================================================================" << endl;
	for (int i = 0;i < logCount;i++) 
	{
		cout << i + 1 << ". " << accessLog[i] << endl;
	}
}
void Lock::changeCode(const string& o, const string& n) {
	if (!verifyCode(o))
	{
		cout << "WRONG CURRENT PASSWORD!!!!!!!!!!!"; << endl;
		return;
	}
	accessCode = n;
	cout << name << " ACCESS CODE CHANGED :)" << endl;
}
void Lock::toggle()
{
	if(isLocked)
	{
		unlock(accessCode);
	}
	else
	{
		lock();
	}
}
string Lock::getStatus() const
{
	return name + " | " + (isOn ? "ON" : "OFF") + (isLocked ? "LOCKED!!" : "UNLOCKED :)");
}
void Lock::generateReport() const
{
	cout << "=========================================================================================================" << endl;
	cout << "||                                        SmartLock Report                                             ||" << endl;
	cout << "=========================================================================================================" << endl;
	cout << "Device: " << name << " (" << deviceID << " )" << endl;
	cout << "Location: " << location << endl;
	cout << "Status: " << (isLocked ? "LOCKED!!" : "UNLOCKED :)" << endl;
	cout << "Log entries: " << logCount << endl;
}