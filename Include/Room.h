#ifndef ROOM_H
#define ROOM_H

#include <vector>
#include "SmartDevice.h"

class Room
{
private:
    int roomId;
    string roomName;
    string floor;
    vector<SmartDevice *> devices;

public:
    Room(int id, string name, string f);

    int getRoomId() const;
    string getRoomName() const;
    string getRoomFloor() const;

    void setRoomId(int id);
    void setRoomName(string n);
    void setRoomFloor(string f);

    void addDevice(SmartDevice *device);
    void removeDevice(int id);
    void showDevices() const;
    void turnAllOff();
};

#endif