#pragma once

#include "MyString.h"

class User {
private:
    MyString username;
    MyString password;
    MyString role;

public:
    User();
    User(const char* username, const char* password, const char* role);

    const MyString& getUsername() const;
    const MyString& getPassword() const;
    const MyString& getRole() const;

    void printInfo() const;
};
