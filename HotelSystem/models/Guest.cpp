#include "Guest.h"
#include <iostream>

Guest::Guest(int id, const char* name, const char* phone, const char* email, const char* type)
    : id(id), name(name), phone(phone), email(email), type(type), reservationCount(0) {
}

int Guest::getId() const { return id; }
const MyString& Guest::getName() const { return name; }
const MyString& Guest::getPhone() const { return phone; }
const MyString& Guest::getEmail() const { return email; }
const MyString& Guest::getType() const { return type; }
int Guest::getReservationCount() const { return reservationCount; }

void Guest::setType(const char* newType) {
    type = MyString(newType);
}

void Guest::incrementReservations() {
    reservationCount++;

    if (reservationCount >= 10)
        type = "platinum";
    else if (reservationCount >= 5)
        type = "gold";
    else
        type = "regular";
}

void Guest::printInfo() const {
    std::cout << "Guest ID: " << id << ", Name: " << name.c_str()
        << ", Phone: " << phone.c_str()
        << ", Email: " << email.c_str()
        << ", Type: " << type.c_str()
        << ", Reservations: " << reservationCount << "\n";
}
