#pragma once

#include "Room.h"

class ConferenceHall : public Room {
public:
    ConferenceHall(int id, double basePrice, const char* status = "free");

    double calculatePrice(const Date& from, const Date& to) const override;
    Room* clone() const override;
    void printInfo() const override;
};
