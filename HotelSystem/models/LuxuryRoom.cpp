#include "LuxuryRoom.h"
#include <iostream>

LuxuryRoom::LuxuryRoom(int id, double basePrice, const char* status)
    : Room(id, basePrice, status) {
}

double LuxuryRoom::calculatePrice(const Date& from, const Date& to) const {
    int nights = from.daysBetween(to);
    return nights * basePrice * 1.25; 
}

Room* LuxuryRoom::clone() const {
    return new LuxuryRoom(*this);
}

void LuxuryRoom::printInfo() const {
    std::cout << "[Luxury Room] ID: " << id
        << ", Base price: " << basePrice
        << ", Status: " << status.c_str() << "\n";
}
