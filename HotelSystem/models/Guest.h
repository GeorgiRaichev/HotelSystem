#pragma once

#include "../core/MyString.h"

class Guest {
private:
    int id;
    MyString name;
    MyString phone;
    MyString email;
    MyString type;
    int reservationCount;

public:
    Guest(int id, const char* name, const char* phone, const char* email, const char* type = "regular");

    int getId() const;
    const MyString& getName() const;
    const MyString& getPhone() const;
    const MyString& getEmail() const;
    const MyString& getType() const;
    int getReservationCount() const;

    void setType(const char* newType);
    void incrementReservations();
    void printInfo() const;
};
