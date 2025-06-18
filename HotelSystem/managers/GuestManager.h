#pragma once

#include "Guest.h"
#include "MyVector.h"

class GuestManager {
private:
    MyVector<Guest> guests;

    bool isIdTaken(int id) const;
    bool isValidEmail(const char* email) const;
    bool isValidPhone(const char* phone) const;

public:
    void addGuest(int id, const char* name, const char* phone, const char* email);
    Guest* findGuestById(int id);
    void incrementReservationCount(int id);
    void printAllGuests() const;
};
