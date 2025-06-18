#include "User.h"
#include <iostream>

User::User() : username(""), password(""), role("") {}

User::User(const char* username, const char* password, const char* role)
    : username(username), password(password), role(role) {
}

const MyString& User::getUsername() const { return username; }
const MyString& User::getPassword() const { return password; }
const MyString& User::getRole() const { return role; }

void User::printInfo() const {
    std::cout << "User: " << username.c_str() << ", Role: " << role.c_str() << "\n";
}
