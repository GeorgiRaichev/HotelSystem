#pragma once

#include "Reservation.h"
#include "MyVector.h"
#include "RoomManager.h"
#include "GuestManager.h"

class ReservationManager {
private:
    MyVector<Reservation> reservations;
    int nextId = 1;

public:
    bool createReservation(int guestId, int roomId, const Date& from, const Date& to,
        GuestManager& guestManager, RoomManager& roomManager);

    bool cancelReservation(int reservationId, RoomManager& roomManager);
    Reservation* findReservationById(int id);
    void printAllReservations() const;

    void loadReservation(int id, int guestId, int roomId, const Date& from, const Date& to, double totalPrice);
    int size() const;
    const Reservation& getAt(int index) const;
};
