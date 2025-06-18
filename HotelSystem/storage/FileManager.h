#pragma once

#include "UserManager.h"
#include "RoomManager.h"
#include "GuestManager.h"
#include "ReservationManager.h"

class FileManager {
public:
    static void loadUsers(UserManager& userManager);
    static void saveUsers(const UserManager& userManager);

    static void loadRooms(RoomManager& roomManager);
    static void saveRooms(const RoomManager& roomManager);

    static void loadGuests(GuestManager& guestManager);
    static void saveGuests(const GuestManager& guestManager);

    static void loadReservations(ReservationManager& resManager);
    static void saveReservations(const ReservationManager& resManager);

};
