#include "Apartment.h"
#include <iostream>

Apartment::Apartment(int id, double basePrice, const char* status)
    : Room(id, basePrice, status) {
}

double Apartment::calculatePrice(const Date& from, const Date& to) const {
    int nights = from.daysBetween(to);
    double discount = (nights >= 7) ? 0.85 : 1.0;
    return nights * basePrice * discount;
}

Room* Apartment::clone() const {
    return new Apartment(*this);
}

void Apartment::printInfo() const {
    std::cout << "[Apartment] ID: " << id
        << ", Base price: " << basePrice
        << ", Status: " << status.c_str() << "\n";
}
