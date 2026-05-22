/*
File Name: Room.cpp
Author : Muhammad Ammar Umer
Purpose: Make Room class with aggrgation of SmartDevice
*/
#include "..\include\Room.h"

Room::Room(int id, string n, string f)
{
    roomId = id;
    roomName = n;
    floor = f;
}

int Room::getRoomId() const
{
    return roomId;
}

string Room::getRoomName() const
{
    return roomName;
}

string Room::getRoomFloor() const
{
    return floor;
}

void Room::setRoomId(int id)
{
    roomId = id;
}

void Room::setRoomName(string n)
{
    roomName = n;
}

void Room::setRoomFloor(string f)
{
    floor = f;
}

void Room::addDevice(SmartDevice *device)
{
    devices.push_back(device);
}

void Room::removeDevice(int id)
{
    for (auto device = devices.begin(); device != devices.end(); device++)
    {
        if ((*device)->getDeviceId() == id)
        {
            delete *device;
            devices.erase(device);
            cout << "Device Removed Successfully." << endl;
            return;
        }
    }
    cout << "Device Not Found" << endl;
}

void Room::showDevices() const
{
    for (auto device : devices)
    {
        device->getStatus();
    }
}

void Room::turnAllOff()
{
    for (auto device : devices)
    {
        if (device->getPowerStatus())
        {
            device->toggle();
        }
    }
}
