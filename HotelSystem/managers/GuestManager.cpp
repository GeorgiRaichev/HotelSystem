#include "GuestManager.h"
#include <iostream>
#include <cstring>

bool GuestManager::isIdTaken(int id) const {
    for (int i = 0; i < guests.size(); ++i)
        if (guests[i].getId() == id)
            return true;
    return false;
}

bool GuestManager::isValidEmail(const char* email) const {
    return std::strchr(email, '@') && std::strchr(email, '.');
}

bool GuestManager::isValidPhone(const char* phone) const {
    int len = std::strlen(phone);
    return len >= 6 && len <= 15;
}

void GuestManager::addGuest(int id, const char* name, const char* phone, const char* email) {
    try {
        if (isIdTaken(id)) {
            std::cout << "Guest with ID " << id << " already exists.\n";
            return;
        }

        if (!isValidEmail(email)) {
            std::cout << "Invalid email format.\n";
            return;
        }

        if (!isValidPhone(phone)) {
            std::cout << "Invalid phone number.\n";
            return;
        }

        Guest g(id, name, phone, email);
        guests.push_back(g);
        std::cout << "Guest added successfully.\n";

    }
    catch (...) {
        std::cout << "Error while adding guest.\n";
    }
}

Guest* GuestManager::findGuestById(int id) {
    for (int i = 0; i < guests.size(); ++i)
        if (guests[i].getId() == id)
            return &guests[i];
    return nullptr;
}

void GuestManager::incrementReservationCount(int id) {
    try {
        Guest* g = findGuestById(id);
        if (!g) {
            std::cout << "Guest not found.\n";
            return;
        }
        g->incrementReservations();
        std::cout << "Reservation count updated. Type is now: " << g->getType().c_str() << "\n";
    }
    catch (...) {
        std::cout << "Error while updating reservation count.\n";
    }
}

void GuestManager::printAllGuests() const {
    for (int i = 0; i < guests.size(); ++i)
        guests[i].printInfo();
}
