#pragma once

#include "MyVector.h"
#include "Room.h"

class RoomManager {
private:
    MyVector<Room*> rooms;
    int nextId;

    void free();
    void copyFrom(const RoomManager& other);

public:
    RoomManager();
    RoomManager(const RoomManager& other);
    RoomManager& operator=(const RoomManager& other);
    ~RoomManager();

    void addRoom(Room* room);
    Room* findRoomById(int id) const;
    void printAllRooms() const;
    void printAvailableRooms() const;

    bool canReserve(const Room* room) const;
    bool canChangeStatus(const Room* room, const char* newStatus) const;
    bool setRoomStatus(int roomId, const char* newStatus);

    int getNextId();
};