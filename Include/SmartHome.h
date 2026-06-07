#ifndef SMARTHOME_H
#define SMARTHOME_H

#include <vector>
#include <string>
#include "Room.h"
#include "Automation.h"

class SmartHome
{
private:
    int homeId;
    std::string owner;
    std::string wifi;
    std::vector<Room *> rooms;
    std::vector<Automation *> automations;

public:
    SmartHome(int id, std::string own, std::string wifi);

    int getHomeId() const;
    std::string getOwner() const;
    std::string getWifi() const;
    std::vector<Room *> &getRooms();

    void setHomeId(int id);
    void setOwner(std::string own);
    void setWifi(std::string wifi);

    void loadRooms();
    Room *findRoom(int id);
    void addRooms(Room *room);
    void removeRoom(int id);
    void showRooms() const;
    void getHomeStatus() const;

    void loadAutomations();
    void addAutomation(Automation *autom);
    Automation *findAutomation(std::string id);
    void removeAutomation(std::string id);
    void showAutomations();
};

#endif
