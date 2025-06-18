#pragma once

#include "User.h"
#include "MyVector.h"

class UserManager {
private:
    MyVector<User> users;

    bool isUsernameTaken(const char* username) const;
    bool isValidRole(const char* role) const;
    bool isValidPassword(const char* password) const;

public:
    bool registerUser(const char* username, const char* password, const char* role);
    const User* loginUser(const char* username, const char* password) const;
    void printAllUsers() const;
    int size() const;
    const User& getAt(int index) const;
};
