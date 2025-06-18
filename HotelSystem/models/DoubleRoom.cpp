#include "DoubleRoom.h"
#include <iostream>

DoubleRoom::DoubleRoom(int id, double basePrice, const char* status)
    : Room(id, basePrice, status) {
}

double DoubleRoom::calculatePrice(const Date& from, const Date& to) const {
    int nights = from.daysBetween(to);
    return nights * (basePrice + 10.0);
}

Room* DoubleRoom::clone() const {
    return new DoubleRoom(*this);
}

void DoubleRoom::printInfo() const {
    std::cout << "[Double Room] ID: " << id
        << ", Base price: " << basePrice
        << ", Status: " << status.c_str() << "\n";
}
