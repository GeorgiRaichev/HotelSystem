#include "FileManager.h"
#include <fstream>
#include <cstring>
#include <iostream>
#include "Date.h"

void FileManager::loadUsers(UserManager& userManager) {
    std::ifstream file("users.txt");
    if (!file.is_open()) return;

    char line[256];
    while (file.getline(line, sizeof(line))) {
        char* username = std::strtok(line, ",");
        char* password = std::strtok(nullptr, ",");
        char* role = std::strtok(nullptr, ",");

        if (username && password && role)
            userManager.registerUser(username, password, role);
    }

    file.close();
}

void FileManager::saveUsers(const UserManager& userManager) {
    std::ofstream file("users.txt");
    if (!file.is_open()) {
        std::cout << "Could not open users.txt for writing.\n";
        return;
    }

    for (int i = 0; i < userManager.size(); ++i) {
        const User& u = userManager.getAt(i);
        file << u.getUsername().c_str() << ","
            << u.getPassword().c_str() << ","
            << u.getRole().c_str() << "\n";
    }

    file.close();
}

void FileManager::loadRooms(RoomManager& roomManager) {
    std::ifstream file("rooms.txt");
    if (!file.is_open()) return;

    char line[256];
    while (file.getline(line, sizeof(line))) {
        char* type = std::strtok(line, ",");
        char* idStr = std::strtok(nullptr, ",");
        char* priceStr = std::strtok(nullptr, ",");
        char* status = std::strtok(nullptr, ",");

        if (!type || !idStr || !priceStr || !status) continue;

        int id = std::atoi(idStr);
        double price = std::atof(priceStr);

        Room* room = nullptr;

        if (std::strcmp(type, "SingleRoom") == 0)
            room = new SingleRoom(id, price, status);
        else if (std::strcmp(type, "DoubleRoom") == 0)
            room = new DoubleRoom(id, price, status);
        else if (std::strcmp(type, "LuxuryRoom") == 0)
            room = new LuxuryRoom(id, price, status);
        else if (std::strcmp(type, "ConferenceHall") == 0)
            room = new ConferenceHall(id, price, status);
        else if (std::strcmp(type, "Apartment") == 0)
            room = new Apartment(id, price, status);

        if (room)
            roomManager.addRoom(room); 
    }

    file.close();
}

void FileManager::saveRooms(const RoomManager& roomManager) {
    std::ofstream file("rooms.txt");
    if (!file.is_open()) return;

    for (int i = 0; i < roomManager.size(); ++i) {
        const Room* room = roomManager.getAt(i);

        const char* type = "Unknown";
        if (dynamic_cast<const SingleRoom*>(room)) type = "SingleRoom";
        else if (dynamic_cast<const DoubleRoom*>(room)) type = "DoubleRoom";
        else if (dynamic_cast<const LuxuryRoom*>(room)) type = "LuxuryRoom";
        else if (dynamic_cast<const ConferenceHall*>(room)) type = "ConferenceHall";
        else if (dynamic_cast<const Apartment*>(room)) type = "Apartment";

        file << type << "," << room->getId() << ","
            << room->getBasePrice() << ","
            << room->getStatus().c_str() << "\n";
    }

    file.close();
}

void FileManager::loadGuests(GuestManager& guestManager) {
    std::ifstream file("guests.txt");
    if (!file.is_open()) return;

    char line[256];
    while (file.getline(line, sizeof(line))) {
        char* idStr = std::strtok(line, ",");
        char* name = std::strtok(nullptr, ",");
        char* phone = std::strtok(nullptr, ",");
        char* email = std::strtok(nullptr, ",");
        char* type = std::strtok(nullptr, ",");
        char* countStr = std::strtok(nullptr, ",");

        if (!idStr || !name || !phone || !email || !type || !countStr) continue;

        int id = std::atoi(idStr);
        int reservationCount = std::atoi(countStr);

        guestManager.loadGuest(id, name, phone, email, type, reservationCount);
    }

    file.close();
}

void FileManager::saveGuests(const GuestManager& guestManager) {
    std::ofstream file("guests.txt");
    if (!file.is_open()) return;

    for (int i = 0; i < guestManager.size(); ++i) {
        const Guest& g = guestManager.getAt(i);
        file << g.getId() << "," << g.getName().c_str() << ","
            << g.getPhone().c_str() << "," << g.getEmail().c_str() << ","
            << g.getType().c_str() << "," << g.getReservationCount() << "\n";
    }

    file.close();
}

Date parseDate(const char* str) {
    int d = 0, m = 0, y = 0;
    std::sscanf(str, "%d.%d.%d", &d, &m, &y);
    return Date(d, m, y);
}

void FileManager::loadReservations(ReservationManager& resManager) {
    std::ifstream file("reservations.txt");
    if (!file.is_open()) return;

    char line[256];
    while (file.getline(line, sizeof(line))) {
        char* idStr = std::strtok(line, ",");
        char* guestStr = std::strtok(nullptr, ",");
        char* roomStr = std::strtok(nullptr, ",");
        char* fromStr = std::strtok(nullptr, ",");
        char* toStr = std::strtok(nullptr, ",");
        char* priceStr = std::strtok(nullptr, ",");

        if (!idStr || !guestStr || !roomStr || !fromStr || !toStr || !priceStr) continue;

        int id = std::atoi(idStr);
        int guestId = std::atoi(guestStr);
        int roomId = std::atoi(roomStr);
        double totalPrice = std::atof(priceStr);

        Date from = parseDate(fromStr);
        Date to = parseDate(toStr);

        resManager.loadReservation(id, guestId, roomId, from, to, totalPrice);
    }

    file.close();
}

void FileManager::saveReservations(const ReservationManager& resManager) {
    std::ofstream file("reservations.txt");
    if (!file.is_open()) return;

    for (int i = 0; i < resManager.size(); ++i) {
        const Reservation& r = resManager.getAt(i);
        file << r.getId() << "," << r.getGuestId() << "," << r.getRoomId() << ","
            << (r.getFromDate().getDay() < 10 ? "0" : "") << r.getFromDate().getDay() << "."
            << (r.getFromDate().getMonth() < 10 ? "0" : "") << r.getFromDate().getMonth() << "."
            << r.getFromDate().getYear() << ","
            << (r.getToDate().getDay() < 10 ? "0" : "") << r.getToDate().getDay() << "."
            << (r.getToDate().getMonth() < 10 ? "0" : "") << r.getToDate().getMonth() << "."
            << r.getToDate().getYear() << ","
            << r.getTotalPrice() << "\n";
    }

    file.close();
}