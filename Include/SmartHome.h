#ifndef SMARTHOME_H
#define SMARTHOME_H

#include <vector>
#include "Room.h"
using namespace std;

class SmartHome
{
private:
    int homeId;
    string owner;
    string wifi;
    vector<Room *> rooms;

public:
    SmartHome(int id, string own, string wifi);

    int getHomeId() const;
    string getOwner() const;
    string getWifi() const;

    void setHomeId(int id);
    void setOwner(string own);
    void setWifi(string wifi);

    void addRooms(Room *room);
    void showRooms() const;
    void getHomeStatus() const;
};

#endif