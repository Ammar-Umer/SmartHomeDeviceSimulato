#include "UserAuthentication.h"
#include "menu.h"
#include "SmartHome.h"
#include <iostream>
using namespace std;

int main()
{
    // Load Data From Files To Vectors
    SmartHome house(101, "Ammar", "PTCL");
    house.loadAutomations();
    house.loadRooms();
    for (auto r: house.getRooms())
    {
        r->loadDevices();
    }
    

    
    UserAuthentication user;
    string ch;
    do
    {
        homePage();
        cout << "Enter Your Choice: ";
        cin >> ch;
        if (ch == "1")
        {
            user.registerGuest();
        }
        else if (ch == "2")
        {
            if (user.login())
            {
                system("cls");
                loading("Logging In");
                if (user.verifyRole("Admin"))
                {
                    system("cls");
                    cout << "WELCOME " << user.getUsername() << " AS " << user.getRole() << endl;
                    adminMenu(user, house);
                }
                else if (user.verifyRole("Owner"))
                {
                    system("cls");
                    cout << "WELCOME " << user.getUsername() << " AS " << user.getRole() << endl;
                    adminMenu(user,house);
                }
                else
                {
                    system("cls");
                    cout << "WELCOME " << user.getUsername() << " AS " << user.getRole() << endl;
                    guestMenu(house);
                }
            }
            else
            {
                system("cls");
                cout << "Invalid Login Details\nPress Enter to Continue..." << endl;
                cin.ignore();
                cin.get();
                continue;
            }
        }
        else if (ch == "0")
        {
            break;
        }
        else
        {
            invalidInput();
        }
    } while (ch != "0");
    system("cls");
    loading("Exiting");
    system("cls");
    cout << "Exited" << endl;
}
