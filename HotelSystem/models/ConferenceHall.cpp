#include "ConferenceHall.h"
#include <iostream>

ConferenceHall::ConferenceHall(int id, double basePrice, const char* status)
    : Room(id, basePrice, status) {
}

double ConferenceHall::calculatePrice(const Date& from, const Date& to) const {
    int days = from.daysBetween(to);
    return days * basePrice + 100.0; 
}

Room* ConferenceHall::clone() const {
    return new ConferenceHall(*this);
}

void ConferenceHall::printInfo() const {
    std::cout << "[Conference Hall] ID: " << id
        << ", Base price: " << basePrice
        << ", Status: " << status.c_str() << "\n";
}
