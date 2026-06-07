#include "UserAuthentication.h"
#include "menu.h"
#include "SmartHome.h"
#include "Room.h"
#include "EnergyLog.h"
#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

// Functions
void viewUsers()
{
    system("cls");
    string u, p, r;
    cout << "\t\t=====All Users=====\t\t\n";
    cout << "Username\tPassword\tRole" << endl;
    ifstream in("Files/users.txt");
    while (in >> u >> p >> r)
    {
        cout << u << "\t\t" << p << "\t\t" << r << endl;
    }
    in.close();
    cout << "Press Enter To Continue..." << endl;
    cin.ignore();
    cin.get();
}

void removeUser(UserAuthentication user)
{
    system("cls");
    string u, p, r;
    string inputUser;
    cout << "\t\t\t=====Remove User=====\n"
         << endl;
    cout << "Enter Username: ";
    cin >> inputUser;
    ifstream in("Files/users.txt");
    ofstream temp("Files/temp.txt");
    bool found = false;
    while (in >> u >> p >> r)
    {
        if (inputUser == user.getUsername())
        {
            temp.close();
            remove("Files/temp.txt");
            cout << "You Cannot delete Your Account" << endl;
            cout << "Press Enter to Continue...";
            cin.ignore();
            cin.get();
            return;
        }
        else if (inputUser != u)
        {
            temp << u << " " << p << " " << r << endl;
        }
        else
        {
            found = true;
        }
    }
    in.close();
    temp.close();
    remove("Files/users.txt");
    rename("Files/temp.txt", "Files/users.txt");

    if (found)
    {
        cout << "User Deleted Successfully" << endl;
    }
    else
    {
        cout << "User not Found" << endl;
    }
    cout << "Press Enter to Continue...";
    cin.ignore();
    cin.get();
}

// Utility Fn
void loading(string msg)
{
    cout << msg;
    for (int i = 0; i < 3; i++)
    {
        cout << ".";
        Sleep(500);
    }
}

void invalidInput()
{
    system("cls");
    cout << "Invalid Input!";
    cout << "Press Enter to Continue...";
    cin.ignore();
    cin.get();
    system("cls");
}

// Sub Menu
void userManager(UserAuthentication user)
{
    string c;
    do
    {
        system("cls");
        cout << "\t\t=====User Manager=====\t\t\n"
             << endl;
        cout << "1.Register User" << endl;
        cout << "2.Remove User" << endl;
        cout << "3.View all Users" << endl;
        cout << "0.Go Back" << endl;
        cout << "Enter your choice= ";
        cin >> c;
        if (c == "1")
        {
            user.registerUser();
        }
        else if (c == "2")
        {
            removeUser(user);
        }
        else if (c == "3")
        {
            viewUsers();
        }
        else if (c == "0")
        {
            system("cls");
            break;
        }
        else
        {
            invalidInput();
        }
    } while (c != "0");
}

void houseManager(SmartHome house)
{
    string c;
    do
    {
        system("cls");
        cout << "\t\t=====House Manager=====\t\t\n"
             << endl;
        cout << "1.House Details" << endl;
        cout << "2.Add Room" << endl;
        cout << "3.Remove Room" << endl;
        cout << "4.View all Room" << endl;
        cout << "0.Go Back" << endl;
        cout << "Enter your choice= ";
        cin >> c;
        if (c == "1")
        {
            house.getHomeStatus();
        }
        else if (c == "2")
        {
            system("cls");
            cout << "\t\t=====Add Room=====" << endl;
            int id;
            string name;
            string floor;

            cout << "\nEnter Room ID: ";
            cin >> id;
            cout << "Enter Room Name: ";
            cin >> name;
            cout << "Enter Floor: ";
            cin >> floor;

            // create room dynamically because SmartHome stores pointer
            Room *newRoom = new Room(id, name, floor);
            house.addRooms(newRoom);

            ofstream file("Files/Rooms.txt", ios::app);

            if (file.is_open())
            {
                file << id << " "
                     << name << " "
                     << floor << endl;

                file.close();

                cout << "\nRoom Added Successfully\n";
            }
            else
            {
                cout << "File Error\n";
            }
            cout << "Press Enter to Continue..." << endl;
            cin.ignore();
            cin.get();
        }
        else if (c == "3")
        {
            system("cls");
            int id;
            cout << "\t\t=====Remove Room=====" << endl;
            cout << "Enter Room ID: ";
            cin >> id;

            house.removeRoom(id);
        }
        else if (c == "4")
        {
            system("cls");
            house.showRooms();
        }

        else if (c == "0")
        {
            system("cls");
            break;
        }
        else
        {
            invalidInput();
        }
    } while (c != "0");
}
void deviceControl(SmartHome *house)
{

    string c;
    do
    {
        system("cls");
        cout << "\t\t=====Device Control=====" << endl;
        cout << "1.Toggle Device" << endl;
        cout << "2.Generate Report" << endl;
        cout << "3.Restrart" << endl;
        cout << "0.Go Back" << endl;
        cout << "Enter Choice:";
        cin >> c;
        if (c == "1")
        {
            system("cls");
            int rid, did;
            cout << "\t\t=====Toggle Device=====" << endl;
            cout << "Enter Room Id: ";
            cin >> rid;
            cout << "Enter Device Id: ";
            cin >> did;
            house->findRoom(rid)->findDevice(did)->toggle();
            cout << "Press Enter to Continue..." << endl;
            cin.ignore();
            cin.get();
        }
        else if (c == "2")
        {
            system("cls");
            int rid, did;
            cout << "\t\t=====Generate Report=====" << endl;
            cout << "Enter Room Id: ";
            cin >> rid;
            cout << "Enter Device Id: ";
            cin >> did;
            house->findRoom(rid)->findDevice(did)->generateReport();
            cout << "Press Enter to Continue..." << endl;
            cin.ignore();
            cin.get();
        }
        else if (c == "3")
        {
            system("cls");
            int rid, did;
            cout << "\t\t=====Generate Report=====" << endl;
            cout << "Enter Room Id: ";
            cin >> rid;
            cout << "Enter Device Id: ";
            cin >> did;
            house->findRoom(rid)->findDevice(did)->restart();
            cout << "Press Enter to Continue..." << endl;
            cin.ignore();
            cin.get();
        }
        else if (c == "0")
        {
            break;
        }
        else
            invalidInput();
    } while (c != "0");
}
void deviceManager(SmartHome house)
{
    string c;
    do
    {
        system("cls");
        cout << "\t\t=====Device Manager=====\t\t\n"
             << endl;
        cout << "1.Add Device" << endl;
        cout << "2.Remove Device" << endl;
        cout << "3.View all Devices" << endl;
        cout << "4.Device Control" << endl;
        cout << "5.Room Grouping" << endl;
        cout << "0.Go Back" << endl;
        cout << "Enter your choice= ";
        cin >> c;
        if (c == "1")
        {
            string c;
            system("cls");
            do
            {
                cout << "\t\t=====Device Type=====" << endl;
                cout << "1.Thermostat" << endl;
                cout << "2.Light" << endl;
                cout << "3.Security Camera" << endl;
                cout << "4.Smart Lock" << endl;
                cout << "5.Smart Speaker" << endl;
                cout << "0.Go Back" << endl;
                cout << "Enter Choice:";
                cin >> c;
                if (c == "1")
                {
                    system("cls");
                    cout << "\t\t=====Add Thermostat=====" << endl;
                    int Rid, Did;
                    string name, loc, typ;
                    double ct, tt;
                    string mode;
                    typ = "Thermostat";
                    cout << "Enter Device Id: ";
                    cin >> Did;
                    cout << "Enter Device Name: ";
                    cin >> name;
                    cout << "Enter Device Location: ";
                    cin >> loc;
                    cout << "Enter Current Temprature: ";
                    cin >> ct;
                    cout << "Enter Target Tamprature: ";
                    cin >> tt;
                    cout << "Enter Device Mode(Heat/Cold/Dry): ";
                    cin >> mode;
                    cout << "\nEnter Room ID: ";
                    cin >> Rid;
                    // create Device dynamically because Room stores pointer
                    SmartDevice *newdevice = new Thermostat(Did, name, loc, typ, ct, tt, mode);
                    house.findRoom(Rid)->addDevice(newdevice);
                    ofstream file("Files/Devices.txt", ios::app);

                    if (file.is_open())
                    {
                        file << Rid << " " << Did << " "
                             << name << " "
                             << loc << " " << typ << " " << ct << " " << tt << " " << mode << endl;

                        file.close();

                        cout << "Device Added Successfully\n";
                    }
                    else
                    {
                        cout << "File Error\n";
                    }
                    cout << "Press Enter to Continue..." << endl;
                    cin.ignore();
                    cin.get();
                }
                else if (c == "2")
                {
                    system("cls");
                    cout << "\t\t=====Add Light=====" << endl;
                    int Rid, Did, b, ct;
                    string name, loc, typ, col;
                    string mode;
                    typ = "Light";
                    cout << "Enter Device Id: ";
                    cin >> Did;
                    cout << "Enter Device Name: ";
                    cin >> name;
                    cout << "Enter Device Location: ";
                    cin >> loc;
                    cout << "Enter Brightness: ";
                    cin >> b;
                    cout << "Enter Colour Temprature: ";
                    cin >> ct;
                    cout << "Enter Colour: ";
                    cin >> col;
                    cout << "\nEnter Room ID: ";
                    cin >> Rid;
                    // create Device dynamically because Room stores pointer
                    SmartDevice *newdevice = new SmartLight(Did, name, loc, typ, b, ct, col);
                    house.findRoom(Rid)->addDevice(newdevice);
                    ofstream file("Files/Devices.txt", ios::app);

                    if (file.is_open())
                    {
                        file << Rid << " " << Did << " "
                             << name << " "
                             << loc << " " << typ << " " << b << " " << ct << " " << col << endl;

                        file.close();

                        cout << "Device Added Successfully\n";
                    }
                }
                else if (c == "3")
                {
                    system("cls");
                    cout << "\t\t=====Add Security Camera=====" << endl;
                    int Rid, Did, ang, sen;
                    string name, loc, typ, res;
                    typ = "Camera";
                    cout << "Enter Device Id: ";
                    cin >> Did;
                    cout << "Enter Device Name: ";
                    cin >> name;
                    cout << "Enter Device Location: ";
                    cin >> loc;
                    cout << "Enter Resolution: ";
                    cin >> res;
                    cout << "Enter Motion Sensitivity: ";
                    cin >> sen;
                    cout << "Enter Angle: ";
                    cin >> ang;
                    cout << "\nEnter Room ID: ";
                    cin >> Rid;
                    // create Device dynamically because Room stores pointer
                    SmartDevice *newdevice = new SecurityCamera(Did, name, loc, typ, res, sen, ang);
                    house.findRoom(Rid)->addDevice(newdevice);

                    ofstream file("Files/Devices.txt", ios::app);

                    if (file.is_open())
                    {
                        file << Rid << " " << Did << " "
                             << name << " "
                             << loc << " " << typ << " " << res << " " << sen << " " << ang << endl;

                        file.close();

                        cout << "Device Added Successfully\n";
                    }
                }
                else if (c == "4")
                {
                    system("cls");
                    cout << "\t\t=====Add Smart Lock=====" << endl;
                    int Rid, Did;
                    string name, loc, typ, c;
                    typ = "Lock";
                    cout << "Enter Device Id: ";
                    cin >> Did;
                    cout << "Enter Device Name: ";
                    cin >> name;
                    cout << "Enter Device Location: ";
                    cin >> loc;
                    cout << "Enter Access Code: ";
                    cin >> c;
                    cout << "\nEnter Room ID: ";
                    cin >> Rid;
                    // create Device dynamically because Room stores pointer
                    SmartDevice *newdevice = new SmartLock(Did, name, loc, typ, c);
                    house.findRoom(Rid)->addDevice(newdevice);

                    ofstream file("Files/Devices.txt", ios::app);

                    if (file.is_open())
                    {
                        file << Rid << " " << Did << " "
                             << name << " "
                             << loc << " " << typ << " " << c << endl;

                        file.close();

                        cout << "Device Added Successfully\n";
                    }
                }
                else if (c == "5")
                {
                    system("cls");
                    cout << "\t\t=====Add Smart Speaker=====" << endl;
                    int Rid, Did, vol;
                    string name, loc, typ;
                    typ = "Speaker";
                    cout << "Enter Device Id: ";
                    cin >> Did;
                    cout << "Enter Device Name: ";
                    cin >> name;
                    cout << "Enter Device Location: ";
                    cin >> loc;
                    cout << "Enter Volume: ";
                    cin >> vol;
                    cout << "\nEnter Room ID: ";
                    cin >> Rid;
                    // create Device dynamically because Room stores pointer
                    SmartDevice *newdevice = new SmartSpeaker(Did, name, loc, typ, vol);
                    house.findRoom(Rid)->addDevice(newdevice);

                    ofstream file("Files/Devices.txt", ios::app);

                    if (file.is_open())
                    {
                        file << Rid << " " << Did << " "
                             << name << " "
                             << loc << " " << typ << " " << vol << endl;

                        file.close();

                        cout << "Device Added Successfully\n";
                    }
                    else
                    {
                        cout << "File Error\n";
                    }
                    cout << "Press Enter to Continue..." << endl;
                    cin.ignore();
                    cin.get();
                }
                else if (c == "0")
                {
                    break;
                }
            } while (c != "0");
        }
        else if (c == "2")
        {
            system("cls");
            int rid, did;
            cout << "\t\t=====Remove Device=====" << endl;
            cout << "Enter Room ID: ";
            cin >> rid;
            cout << "Enter Device ID: ";
            cin >> did;
            house.findRoom(rid)->removeDevice(did);
        }
        else if (c == "3")
        {
            system("cls");
            for (auto r : house.getRooms())
            {
                r->showDevices();
            }
            cout << "Press Enter to Continue...";
            cin.ignore();
            cin.get();
        }
        else if (c == "4")
        {

            deviceControl(&house);
        }
        else if (c == "5")
        {
            system("cls");
            int id;
            cout << "\t\t=====Room Grouping=====" << endl;
            cout << "Enter Room Id: ";
            cin >> id;
            house.findRoom(id)->showDevices();
            cout << "Press Enter to Continue...";
            cin.ignore();
            cin.get();
        }

        else if (c == "0")
        {
            system("cls");
            break;
        }
        else
        {
            invalidInput();
        }
    } while (c != "0");
}
void automationManager(SmartHome house)
{
    string c;
    do
    {
        system("cls");
        cout << "\t\t\t=====Automation Manager=====\t\t\t\n"
             << endl;
        cout << "1.Add Automation" << endl;
        cout << "2.Remove Automation" << endl;
        cout << "3.Activate Automation" << endl;
        cout << "4.Deactivate Automation" << endl;
        cout << "5.Show all Automation" << endl;
        cout << "0.Exit" << endl;
        cout << "Enter Choice: " << endl;
        cin >> c;
        if (c == "1")
        {
            system("cls");
            cout << "\t\t=====Add Automation=====" << endl;
            string id, cond, time;
            cout << "Enter Automation Id: ";
            cin >> id;
            cout << "Enter Condition: ";
            cin >> cond;
            cout << "Enter Time: ";
            cin >> time;
            // create Automation dynamically because SmartHome stores pointer
            Automation *autom = new Automation(id, cond, time);
            house.addAutomation(autom);
            ofstream file("Files/Automations.txt", ios::app);

            if (file.is_open())
            {
                file << id << " " << cond << " "
                     << time << endl;

                file.close();

                cout << "Device Added Successfully\n";
                cout << "Press Enter to Continue..." << endl;
                cin.ignore();
                cin.get();
            }
        }
        else if (c == "2")
        {
            system("cls");
            string id;
            cout << "\t\t=====Remove Automation" << endl;
            cout << "Enter Automation Id: ";
            cin >> id;
            house.removeAutomation(id);
        }

        else if (c == "3")
        {
            system("cls");
            string id;
            cout << "\t\t=====Activate Automation=====" << endl;
            cout << "Enter Automation Id: " << endl;
            cin >> id;
            if (house.findAutomation(id))
            {
                house.findAutomation(id)->activate();
            }
            else
                cout << "No automation Found" << endl;
            cout << "Press Enter to Continue..." << endl;
            cin.ignore();
            cin.get();
        }
        else if (c == "4")
        {
            system("cls");
            string id;
            cout << "\t\t=====Deactivate Automation=====" << endl;
            cout << "Enter Automation Id: " << endl;
            cin >> id;
            if (house.findAutomation(id))
            {
                house.findAutomation(id)->deactivate();
            }
            else
                cout << "No automation Found" << endl;
            cout << "Press Enter to Continue..." << endl;
            cin.ignore();
            cin.get();
        }

        else if (c == "5")
        {
            house.showAutomations();
        }
        else if (c == "0")
        {
            break;
        }

    } while (c != "0");
}
// Menu
void homePage()
{
    system("cls");
    cout << "\t\t\t=====SMART HOME DEVICES SIMULATOR=====\t\t\t\n"
         << endl;
    cout << "1.Register As Guest" << endl;
    cout << "2.Login" << endl;
    cout << "0.Exit" << endl;
}

void adminMenu(UserAuthentication &u, SmartHome &h)
{
    string c;
    do
    {
        system("cls");
        cout << "\t\t\t=====Admin Menu=====\t\t\t\n"
             << endl;
        cout << "1.User Management" << endl;
        cout << "2.House Management" << endl;
        cout << "3.Device Management" << endl;
        cout << "4.Automation Rules" << endl;
        cout << "5.Energy Monitoring" << endl;
        cout << "0.Logout" << endl;
        cout << "Enter your choice= ";
        cin >> c;
        if (c == "1")
        {
            userManager(u);
        }
        else if (c == "2")
        {
            houseManager(h);
        }
        else if (c == "3")
        {
            deviceManager(h);
        }
        else if (c == "4")
        {
            automationManager(h);
        }
        else if (c == "5")
        {
            system("cls");
            EnergyLog log;
            cout << "\t\t===Energy Consumption===" << endl;
            log.getMonthlyReport();
            cout << "Press Enter to Continue..." << endl;
            cin.ignore();
            cin.get();
        }

        else if (c == "0")
        {
            system("cls");
            loading("Logging Out");
            break;
        }
        else
        {
            invalidInput();
        }
    } while (c != "0");
}

void guestMenu(SmartHome &house)
{
    system("cls");
    SmartHome h=house;
    string c;
    do
    {
        cout << "\t\t\t=====Guest Menu=====\t\t\t\n"
             << endl;
        cout << "1.Device Control" << endl;
        cout << "0.Logout" << endl;
        cout << "Enter your choice= ";
        cin >> c;
        if (c=="1")
        {
            system("cls");
            deviceControl(&h);
        }
        
        else if (c == "0")
        {
            system("cls");
            loading("Logging Out");
            break;
        }
        else
        {
            invalidInput();
        }
    } while (c != "0");
}
