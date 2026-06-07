#ifndef ROOM_H
#define ROOM_H

#include <vector>
#include <string>
#include "Thermostat.h"
#include "SmartLock.h"
#include "SecurityCamera.h"
#include "SmartSpeaker.h"
#include "SmartDevice.h"

class Room
{
private:
    int roomId;
    std::string roomName;
    std::string floor;
    std::vector<SmartDevice *> devices;

public:
    Room(int id, std::string name, std::string f);

    int getRoomId() const;
    std::string getRoomName() const;
    std::string getRoomFloor() const;

    void setRoomId(int id);
    void setRoomName(std::string name);
    void setRoomFloor(std::string f);
    void loadDevices();
    SmartDevice *findDevice(int id);
    void addDevice(SmartDevice *device);
    void removeDevice(int id);
    void showDevices() const;
    void turnAllOff();
};

#endif
