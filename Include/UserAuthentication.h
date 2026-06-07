#ifndef USERAUTHENTICATION_H
#define USERAUTHENTICATION_H

#include <iostream>
#include <fstream>
#include <string>

class UserAuthentication
{
private:
    std::string userName;
    std::string password;
    std::string role;

public:
    UserAuthentication(std::string user="", std::string pass="", std::string role="");

    std::string getUsername() const;
    std::string getPassword() const;
    std::string getRole() const;

    void setUsername(std::string);
    void setPassword(std::string);
    void setRole(std::string);

    void registerUser();
    void registerGuest();
    bool login();
    void logout();
    bool verifyRole(std::string);
    bool grantGuestAccess();
};

#endif
