/*
File Name: SmartHome.cpp
Author : Muhammad Ammar Umer
Purpose: Make SmartHome class with aggregation of Room class
*/
#include"SmartHome.h"
#include <fstream>
#include <iostream>
using namespace std;

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
vector<Room *>& SmartHome:: getRooms() 
{
    return rooms;
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
void SmartHome::loadRooms()
{
    ifstream file("Files/Rooms.txt");

    if (!file)
    {
        cout << "File not found!\n";
        return;
    }

    int id;
    string name;
    string floor;

    while (file >> id >> name >> floor)
    {
        rooms.push_back(new Room(id, name, floor));
    }

    file.close();
}
Room *SmartHome::findRoom(int id)
{
    for (auto r : rooms)
        if (r->getRoomId() == id)
            return r;
    return nullptr;
}
void SmartHome::addRooms(Room *room)
{
    rooms.push_back(room);
}

void SmartHome::removeRoom(int id)
{
    bool found = false;

    for (int i = 0; i < rooms.size(); i++)
    {
        if (rooms[i]->getRoomId() == id)
        {
            rooms.erase(rooms.begin() + i);
            found = true;
            break;
        }
    }

    if (found)
    {
        // rewrite file without deleted room
        ifstream in("Files/Rooms.txt");
        ofstream out("Files/temp.txt");

        int rId;
        string name, floor;

        while (in >> rId >> name >> floor)
        {
            if (rId != id)
            {
                out << rId << " "
                    << name << " "
                    << floor << endl;
            }
        }

        in.close();
        out.close();

        remove("Files/Rooms.txt");
        rename("Files/temp.txt", "Files/Rooms.txt");

        cout << "Room Removed Successfully\n";
    }
    else
    {
        cout << "Room Not Found\n";
    }
    cout << "Press Enter to Continue..." << endl;
    cin.ignore();
    cin.get();
}

void SmartHome::showRooms() const
{
    cout << "\t\t=====All Rooms=====" << endl;
    if (rooms.empty())
    {
        cout << "No Room Available" << endl;
    }
    else
    {
        cout << "ID\t\tName\t\tFloor" << endl;
        for (auto room : rooms)
        {
            cout << room->getRoomId() << ".\t " << room->getRoomName() << "\t" << room->getRoomFloor() << endl;
        }
    }
    cout << "=======================" << endl;
    cout << "Press Enter To continue..." << endl;
    cin.ignore();
    cin.get();
}

void SmartHome::getHomeStatus() const
{
    system("cls");
    cout << "======== HOME STATUS =========" << endl;
    cout << "Home ID: " << homeId << endl;
    cout << "Owner: " << owner << endl;
    cout << "Wifi: " << wifi << endl;
    cout << "Total Rooms: " << rooms.size() << endl;
    cout << "===================" << endl;
    cout << "Press Enter to Continue...";
    cin.ignore();
    cin.get();
    system("cls");
}

void SmartHome::loadAutomations()
{
    ifstream file("Files/Automations.txt");

    if (!file)
    {
        cout << "File not found!\n";
        return;
    }

    string id;
    string cond;
    string time;

    while (file >> id >> cond >> time)
    {
        automations.push_back(new Automation(id, cond, time));
    }

    file.close();
}
void SmartHome::addAutomation(Automation *autom)
{
    automations.push_back(autom);
}

Automation *SmartHome::findAutomation(string id)
{
    for (auto r : automations)
        if (r->getruleID() == id)
            return r;
    return nullptr;
}
void SmartHome::removeAutomation(string id)
{
    bool found = false;

    for (int i = 0; i < automations.size(); i++)
    {
        if (automations[i]->getruleID()== id)
        {
            automations.erase(automations.begin() + i);
            found = true;
            break;
        }
    }

    if (found)
    {
        // rewrite file without deleted room
        ifstream in("Files/Automations.txt");
        ofstream out("Files/temp.txt");

        string aid,cond,time;

        while (in >> aid >> cond >> time)
        {
            if (aid != id)
            {
                out << aid << " "
                    << cond << " "
                    << time << endl;
            }
        }

        in.close();
        out.close();

        remove("Files/Automations.txt");
        rename("Files/temp.txt", "Files/Automations.txt");

        cout << "Automation Removed Successfully\n";
    }
    else
    {
        cout << "Automation Not Found\n";
    }
    cout << "Press Enter to Continue..." << endl;
    cin.ignore();
    cin.get();
}
void SmartHome::showAutomations() 
{
    system("cls");
    cout << "\t\t=====All Automations=====" << endl;
    if (automations.empty())
    {
        cout << "No Automation Available" << endl;
    }
    else
    {
        for (auto r : automations)
        {
            r->showAutomation();
        }
    }
    cout << "=======================" << endl;
    cout << "Press Enter To continue..." << endl;
    cin.ignore();
    cin.get();
}