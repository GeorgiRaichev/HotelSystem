#pragma once
#include "MyString.h"
#include "Date.h"

class Room {
protected:
    int id;
    double basePrice;
    MyString status; 

public:
    Room(int id, double basePrice, const char* status);
    virtual ~Room() = default;

    int getId() const;
    double getBasePrice() const;
    const MyString& getStatus() const;
    void setStatus(const char* newStatus);

    virtual double calculatePrice(const Date& from, const Date& to) const = 0;
    virtual Room* clone() const = 0;
    virtual void printInfo() const = 0;
};
