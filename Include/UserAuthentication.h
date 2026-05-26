#ifndef USERAUTHENTICATION_H
#define USERAUTHENTICATION_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class UserAuthentication
{
private:
    string userName;
    string password;
    string role;

public:
    UserAuthentication(string user, string pass, string role);

    string getUsername() const;
    string getPassword() const;
    string getRole() const;

    void setUsername(string);
    void setPassword(string);
    void setRole(string);

    void registerUser();
    void registerGuest();
    bool login();
    void logout();
    bool verifyRole(string);
    bool grantGuestAccess();
};

#endif