#ifndef MENU_H
#define MENU_H
#include "UserAuthentication.h"
#include "SmartHome.h"
#include "Room.h"
#include "SmartDevice.h"
#include <string>
void homePage();
void adminMenu(UserAuthentication &u, SmartHome &h);
void viewUsers();
void removeUser(UserAuthentication user);
void loading(std::string msg);
void invalidInput();
void deviceControl(SmartHome* house);
void deviceManager(SmartHome house);
void userManager(UserAuthentication user);
void houseManager(SmartHome house);
void ownerMenu();
void guestMenu(SmartHome& house);
#endif
