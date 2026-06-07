#ifndef SmartLock_h
#define SmartLock_h
#include "SmartAppliance.h"
using namespace std;

class Lock: public Appliaance {
private:
	bool isLocked;
	string accessCode;
	string accessLog[1000];
	int logCount;
	int count;
public:
	Lock();
	Lock(const string& i, const string& n, const string& l, const string& code = "0000");
	Lock(Lock& other);
	~Lock();
	bool isLockedState() const
	{
		return isLocked;
	}
	void lock();
	void unlock(const string& c);//code
	bool verifyCode(const string& c) const;//code
	void getAccessHistory() const;
	void changeCode(const string& o, const string& n);// o = old code, n = new code
	void toggle() override;
	string getStatus() const override;
	void generateReport() const override;
};

#endif SmartLock_h
