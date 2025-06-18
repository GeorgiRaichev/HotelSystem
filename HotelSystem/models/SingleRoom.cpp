#include "SingleRoom.h"
#include <iostream>

SingleRoom::SingleRoom(int id, double basePrice, const char* status)
    : Room(id, basePrice, status) {
}

double SingleRoom::calculatePrice(const Date& from, const Date& to) const {
    int nights = from.daysBetween(to);
    return nights * basePrice;
}

Room* SingleRoom::clone() const {
    return new SingleRoom(*this);
}

void SingleRoom::printInfo() const {
    std::cout << "[Single Room] ID: " << id
        << ", Base price: " << basePrice
        << ", Status: " << status.c_str() << "\n";
}
