/*
File Name: SmartHome.cpp
Author : Muhammad Ammar Umer
Purpose: Make SmartHome class with aggregation of Room class
*/
#include "..\include\SmartHome.h"

SmartHome::SmartHome(int id, string own, string wifi)
{
    homeId = id;
    owner = own;
    this->wifi = wifi;
}

int SmartHome::getHomeId() const
{
    return homeId;
}

string SmartHome::getOwner() const
{
    return owner;
}

string SmartHome::getWifi() const
{
    return wifi;
}

void SmartHome::setHomeId(int id)
{
    homeId = id;
}

void SmartHome::setOwner(string own)
{
    owner = own;
}

void SmartHome::setWifi(string wifi)
{
    this->wifi = wifi;
}

void SmartHome::addRooms(Room *room)
{
    rooms.push_back(room);
}

void SmartHome::showRooms() const
{
    cout << "Rooms in Smart Home:" << endl;
    if (rooms.empty())
    {
        cout << "No Room Available" << endl;
    }
    else
    {
        for (auto room : rooms)
        {
            cout << room->getRoomId() << ". " << room->getRoomName() << endl;
        }
    }
}

void SmartHome::getHomeStatus() const
{
    cout << "======== HOME STATUS ==========" << endl;
    cout << "Home ID: " << homeId << endl;
    cout << "Owner: " << owner << endl;
    cout << "Wifi: " << wifi << endl;
    cout << "Total Rooms: " << rooms.size() << endl;
}
