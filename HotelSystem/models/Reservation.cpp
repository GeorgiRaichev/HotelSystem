#include "Reservation.h"
#include <iostream>

Reservation::Reservation(int id, int guestId, int roomId, const Date& from, const Date& to, double totalPrice)
    : id(id), guestId(guestId), roomId(roomId), from(from), to(to), totalPrice(totalPrice) {
}

int Reservation::getId() const { return id; }
int Reservation::getGuestId() const { return guestId; }
int Reservation::getRoomId() const { return roomId; }
const Date& Reservation::getFromDate() const { return from; }
const Date& Reservation::getToDate() const { return to; }
double Reservation::getTotalPrice() const { return totalPrice; }

void Reservation::printInfo() const {
    std::cout << "Reservation ID: " << id
        << ", Guest ID: " << guestId
        << ", Room ID: " << roomId
        << ", From: " << from.getDay() << "/" << from.getMonth() << "/" << from.getYear()
        << ", To: " << to.getDay() << "/" << to.getMonth() << "/" << to.getYear()
        << ", Total Price: " << totalPrice << "\n";
}