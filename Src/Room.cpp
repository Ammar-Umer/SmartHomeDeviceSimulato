/*
File Name: Room.cpp
Author : Muhammad Ammar Umer
Purpose: Make Room class with aggrgation of SmartDevice
*/
#include "Room.h"
#include <iostream>
#include <fstream>
using namespace std;

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
void Room::loadDevices()
{
    devices.clear();
    ifstream file("Files/Devices.txt");

    if (!file)
    {
        cout << "File not found!\n";
        return;
    }

    int id, rid;
    string name;
    string loc;
    string typ;
    double d1, d2;
    string d3;

    while (file >> rid >> id >> name >> loc >> typ)
    {
        SmartDevice *device = nullptr;
        if (typ == "Thermostat")
        {
            file >> d1 >> d2 >> d3;
            device = new Thermostat(id, name, loc, typ, d1, d2, d3);
        }
        else if (typ == "Light")
        {
            file >> d1 >> d2 >> d3;
            device = new SmartLight(id, name, loc, typ, d1, d2, d3);
        }
        else if (typ == "Camera")
        {
            string d1 = d1;
            double d3 = d3;
            file >> d1 >> d2 >> d3;
            device = new SecurityCamera(id, name, loc, typ, d1, d2, d3);
        }
        if (typ == "Lock")
        {
            string d1 = d1;
            file >> d1;
            device = new SmartLock(id, name, loc, typ, d1);
        }
        if (typ == "Speaker")
        {
            file >> d1;
            device = new SmartSpeaker(id, name, loc, typ, d1);
        }

        if (device != nullptr)
        {
            devices.push_back(device);
        }
    }

    file.close();
}

SmartDevice *Room::findDevice(int id)
{
    for (auto r : devices)
        if (r->getDeviceId() == id)
            return r;
    return nullptr;
}
void Room::addDevice(SmartDevice *device)
{
    devices.push_back(device);
}
void Room::removeDevice(int id)
{
    bool found = false;

    // Remove from vector
    for (auto it = devices.begin(); it != devices.end(); ++it)
    {
        if ((*it)->getDeviceId() == id)
        {
            delete *it;
            devices.erase(it);
            found = true;
            break;
        }
    }

    if (found)
    {
        ifstream file("Files/Devices.txt");
        ofstream temp("Files/temp.txt");

        int did, rid;
        string name, loc, type;

        while (file >> rid >> did >> name >> loc >> type)
        {
            if (did == id)
            {
                // remove this device
                string line;
                getline(file, line);
                continue;
            }

            temp << rid << " "
                 << did << " "
                 << name << " "
                 << loc << " "
                 << type << " ";

            // copy remaining attributes according to device type

            if (type == "Thermostat")
            {
                string temp1, temp2, temp3;
                file >> temp1 >> temp2 >> temp3;

                temp << temp1 << " "
                     << temp2 << " "
                     << temp3;
            }

            else if (type == "Light")
            {
                string a, b, c;
                file >> a >> b >> c;

                temp << a << " "
                     << b << " "
                     << c;
            }

            else if (type == "Camera")
            {
                string a, b,c;
                file >> a >> b>>c;

                temp << a << " "
                     << b<<c;
            }

            else if (type == "Lock" || type == "Speaker")
            {
                string a;
                file >> a;

                temp << a;
            }

            temp << endl;
        }

        file.close();
        temp.close();

        remove("Files/Devices.txt");
        rename("Files/temp.txt", "Files/Devices.txt");

        cout << "Device Removed Successfully" << endl;
    }
    else
    {
        cout << "Device Not Found" << endl;
    }

    cout << "Press Enter to Continue...";
    cin.ignore();
    cin.get();
}

void Room::showDevices() const
{
    for (auto device : devices)
    {
        cout << *device;
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
