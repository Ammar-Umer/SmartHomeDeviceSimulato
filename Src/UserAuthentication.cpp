#include "..\include\UserAuthentication.h"

UserAuthentication::UserAuthentication(string user, string pass, string role)
{
    userName = user;
    password = pass;
    this->role = role;
}

string UserAuthentication::getUsername() const
{
    return userName;
}

string UserAuthentication::getPassword() const
{
    return password;
}

string UserAuthentication::getRole() const
{
    return role;
}

void UserAuthentication::setUsername(string user)
{
    userName = user;
}

void UserAuthentication::setPassword(string pass)
{
    password = pass;
}

void UserAuthentication::setRole(string role)
{
    this->role = role;
}

void UserAuthentication::registerUser()
{
    ofstream out("Files/users.txt", ios::app);
    cout << "Enter Username: ";
    cin >> userName;
    cout << "Enter Password: ";
    cin >> password;
    cout << "Enter Role(Admin/Owner/Guest): ";
    cin >> role;

    out << userName << " " << password << " " << role << endl;
    out.close();
    cout << "User Registered Successfully" << endl;
}

bool UserAuthentication::login()
{
    string u, p, r;
    string inputPass, inputUser;
    cout << "Enter Your Username: ";
    cin >> inputUser;
    cout << "Enter Password: ";
    cin >> inputPass;
    ifstream in("Files/users.txt");
    while (in >> u >> p >> r)
    {
        if (inputUser == u && inputPass == p)
        {
            userName = u;
            password = p;
            role = r;
            cout << "Login Successfully" << endl;
            in.close();
            return true;
        }
    }
    cout << "Invalid Username and Password" << endl;
    return false;
}

void UserAuthentication::logout()
{
    userName = "";
    password = "";
    role = "";
    cout << "Log Out Successfully" << endl;
}

bool UserAuthentication::verifyRole(string r)
{
    return (role == r);
}

bool UserAuthentication::grantGuestAccess()
{
    if (role == "Guest")
    {
        cout << "Guest Access Granted Successfully" << endl;
        return true;
    }
    return false;
}