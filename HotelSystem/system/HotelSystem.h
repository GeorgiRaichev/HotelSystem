#pragma once

#include "UserManager.h"
#include "RoomManager.h"
#include "GuestManager.h"
#include "ReservationManager.h"
#include "ActionLogger.h"
#include "FileManager.h"
#include "User.h"

class HotelSystem {
private:
    UserManager userManager;
    RoomManager roomManager;
    GuestManager guestManager;
    ReservationManager reservationManager;

    User currentUser;
    bool isLoggedIn = false;

    void loginMenu();
    void registerMenu();
    void mainMenu();
    void managerMenu();
    void receptionistMenu();
    void accountantMenu();

public:
    void run();
};
