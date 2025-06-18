#include "Room.h"

Room::Room(int id, double basePrice, const char* status)
    : id(id), basePrice(basePrice), status(status) {
}

int Room::getId() const {
    return id;
}

double Room::getBasePrice() const {
    return basePrice;
}

const MyString& Room::getStatus() const {
    return status;
}

void Room::setStatus(const char* newStatus) {
    status = MyString(newStatus);
}
