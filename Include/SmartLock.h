#ifndef SMARTLOCK_H
#define SMARTLOCK_H
#include "SmartAppliance.h"
#include <string>

class SmartLock : public SmartAppliance
{
private:
    bool isLocked;
    std::string accessCode;
    std::string accessLog[1000];
    int logCount;

public:
    SmartLock(int id, const std::string& n, const std::string& l, const std::string& v, const std::string& c);
    SmartLock(const SmartLock& other);
    ~SmartLock();

    void lock();
    void unlock(const std::string& c);
    bool verifyCode(const std::string& c) const;
    void getAccessHistory() const;
    void changeCode(const std::string& oldCode, const std::string& newCode);

    void toggle() override;
    void getStatus() const override;
    void generateReport() const override;
};

#endif
