#include "ReservationManager.h"
#include <iostream>

bool ReservationManager::createReservation(int guestId, int roomId, const Date& from, const Date& to,
    GuestManager& guestManager, RoomManager& roomManager) {
    try {
        if (!from.isValid() || !to.isValid() || !(from < to)) {
            std::cout << "Invalid date range.\n";
            return false;
        }

        Guest* guest = guestManager.findGuestById(guestId);
        if (!guest) {
            std::cout << "Guest not found.\n";
            return false;
        }

        Room* room = roomManager.findRoomById(roomId);
        if (!room) {
            std::cout << "Room not found.\n";
            return false;
        }

        if (!roomManager.isAvailable(room)) {
            std::cout << "Room is not available.\n";
            return false;
        }

        double price = room->calculatePrice(from, to);

        const MyString& type = guest->getType();
        if (type == "gold") price *= 0.9;
        else if (type == "platinum") price *= 0.8;

        reservations.push_back(Reservation(nextId++, guestId, roomId, from, to, price));
        room->setStatus("reserved");
        guest->incrementReservations();

        std::cout << "Reservation created successfully.\n";
        return true;

    }
    catch (...) {
        std::cout << "Error creating reservation.\n";
        return false;
    }
}

bool ReservationManager::cancelReservation(int reservationId, RoomManager& roomManager) {
    try {
        for (int i = 0; i < reservations.size(); ++i) {
            if (reservations[i].getId() == reservationId) {
                Room* room = roomManager.findRoomById(reservations[i].getRoomId());
                if (room && room->getStatus() == "reserved")
                    room->setStatus("free");

                reservations.removeAt(i);
                std::cout << "Reservation canceled.\n";
                return true;
            }
        }
        std::cout << "Reservation not found.\n";
        return false;
    }
    catch (...) {
        std::cout << "Error canceling reservation.\n";
        return false;
    }
}

Reservation* ReservationManager::findReservationById(int id) {
    for (int i = 0; i < reservations.size(); ++i)
        if (reservations[i].getId() == id)
            return &reservations[i];
    return nullptr;
}

void ReservationManager::printAllReservations() const {
    for (int i = 0; i < reservations.size(); ++i)
        reservations[i].printInfo();
}
