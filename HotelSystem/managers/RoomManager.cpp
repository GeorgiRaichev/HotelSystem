#include "RoomManager.h"
#include <iostream>
#include <cstring>

RoomManager::RoomManager() : nextId(1) {}

RoomManager::RoomManager(const RoomManager& other) {
    copyFrom(other);
}

RoomManager& RoomManager::operator=(const RoomManager& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

RoomManager::~RoomManager() {
    free();
}

void RoomManager::free() {
    for (int i = 0; i < rooms.size(); i++) {
        delete rooms[i];
    }
    rooms.clear();
}

void RoomManager::copyFrom(const RoomManager& other) {
    nextId = other.nextId;
    for (int i = 0; i < other.rooms.size(); i++) {
        rooms.push_back(other.rooms[i]->clone());
    }
}

void RoomManager::addRoom(Room* room) {
    Room* cloned = room->clone();
    cloned->setStatus("free");
    rooms.push_back(cloned);
}

Room* RoomManager::findRoomById(int id) const {
    for (int i = 0; i < rooms.size(); i++) {
        if (rooms[i]->getId() == id) return rooms[i];
    }
    return nullptr;
}

void RoomManager::printAllRooms() const {
    for (int i = 0; i < rooms.size(); i++) {
        rooms[i]->printInfo();
    }
}

void RoomManager::printAvailableRooms() const {
    for (int i = 0; i < rooms.size(); i++) {
        if (strcmp(rooms[i]->getStatus().c_str(), "free") == 0)
            rooms[i]->printInfo();
    }
}

bool RoomManager::canReserve(const Room* room) const {
    const char* status = room->getStatus().c_str();
    return strcmp(status, "free") == 0;
}

bool RoomManager::canChangeStatus(const Room* room, const char* newStatus) const {
    const char* current = room->getStatus().c_str();

    if (strcmp(current, "reserved") == 0 && strcmp(newStatus, "free") == 0) {
        std::cout << "[ERROR] Cannot set status to 'free'. Room is reserved. Cancel reservation first.\n";
        return false;
    }

    if (strcmp(current, "reserved") == 0 && strcmp(newStatus, "maintenance") == 0) {
        std::cout << "[ERROR] Cannot set status to 'maintenance'. Room is reserved. Cancel reservation first.\n";
        return false;
    }

    return true;
}

bool RoomManager::setRoomStatus(int roomId, const char* newStatus) {
    Room* room = findRoomById(roomId);
    if (!room) {
        std::cout << "[ERROR] Room not found.\n";
        return false;
    }

    if (!canChangeStatus(room, newStatus)) return false;

    room->setStatus(newStatus);
    return true;
}

int RoomManager::getNextId() {
    return nextId++;
}
int RoomManager::size() const {
    return rooms.size();
}

const Room* RoomManager::getAt(int index) const {
    return rooms[index];
}
