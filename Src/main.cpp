#include "UserAuthentication.cpp"
#include <windows.h>
// Utilities Fn
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
// Menu
void homePage()
{
    system("cls");
    cout << "\t\t\t=====SMART HOME DEVICES SIMULATOR=====\t\t\t\n"
         << endl;
    cout << "1.Register Yourself" << endl;
    cout << "2.Login" << endl;
    cout << "0.Exit" << endl;
}
void adminMenu()
{
    string c;
    do
    {
        cout << "\t\t\t=====Admin Menu=====\t\t\t\n"
             << endl;
        cout << "1.Users" << endl;
        cout << "2.Device Managment" << endl;
        cout << "3.House Managment" << endl;
        cout << "4.Automation Rules" << endl;
        cout << "5.Energy Monitoring" << endl;
        cout << "6.Room Grouping" << endl;
        cout << "7.Security Control" << endl;
        cout << "0.Logout" << endl;
        cout << "Enter your choice= ";
        cin >> c;
        if (c == "0")
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
void ownerMenu()
{
    string c;
    do
    {
        cout << "\t\t\t=====Owner Menu=====\t\t\t\n"
             << endl;
        cout << "1.Users" << endl;
        cout << "2.Devices" << endl;
        cout << "3.House Managment" << endl;
        cout << "4.Energy Monitoring" << endl;
        cout << "5.Voice Command Simulation" << endl;
        cout << "0.Logout" << endl;
        cout << "Enter your choice= ";
        cin >> c;
        if (c == "0")
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
void guestMenu()
{
    cout << "\t\t\t=====Guest Menu=====\t\t\t\n"
         << endl;
    cout << "1.Manage Lights" << endl;
    cout << "2.Manage Thermostat" << endl;
    cout << "2.Manage Thermostat" << endl;
    cout << "0.Logout" << endl;
}

int main()
{
    UserAuthentication user;
    string ch;
    do
    {
        homePage();
        cout << "Enter Your Choice: ";
        cin >> ch;
        if (ch == "1")
        {
            user.registerUser();
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
                    adminMenu();
                }
                else if (user.verifyRole("Owner"))
                {
                    system("cls");
                    cout << "WELCOME " << user.getUsername() << " AS " << user.getRole() << endl;
                    ownerMenu();
                }
                else
                {
                    system("cls");
                    cout << "WELCOME " << user.getUsername() << " AS " << user.getRole() << endl;
                    guestMenu();
                }
            }
            else
            {
                cout << "Invlid Login Details\nPress Enter to Continue..." << endl;
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
            invalidInput();

    } while (ch != "0");
    system("cls");
    loading("Exiting");
    system("cls");
    cout << "Exited" << endl;
}