#include "UserManager.h"
#include <iostream>
#include <cstring>

bool UserManager::isUsernameTaken(const char* username) const {
    for (int i = 0; i < users.size(); ++i)
        if (users[i].getUsername() == username)
            return true;
    return false;
}

bool UserManager::isValidRole(const char* role) const {
    return std::strcmp(role, "manager") == 0 ||
        std::strcmp(role, "receptionist") == 0 ||
        std::strcmp(role, "accountant") == 0;
}

bool UserManager::isValidPassword(const char* password) const {
    return std::strlen(password) >= 4;
}

bool UserManager::registerUser(const char* username, const char* password, const char* role) {
    try {
        if (isUsernameTaken(username)) {
            std::cout << "Username already exists.\n";
            return false;
        }

        if (!isValidRole(role)) {
            std::cout << "Invalid role.\n";
            return false;
        }

        if (!isValidPassword(password)) {
            std::cout << "Password must be at least 4 characters.\n";
            return false;
        }

        users.push_back(User(username, password, role));
        std::cout << "User registered successfully.\n";
        return true;

    }
    catch (...) {
        std::cout << "Error registering user.\n";
        return false;
    }
}

const User* UserManager::loginUser(const char* username, const char* password) const {
    try {
        for (int i = 0; i < users.size(); ++i) {
            if (users[i].getUsername() == username && users[i].getPassword() == password)
                return &users[i];
        }
        std::cout << "Invalid username or password.\n";
        return nullptr;
    }
    catch (...) {
        std::cout << "Error during login.\n";
        return nullptr;
    }
}

void UserManager::printAllUsers() const {
    for (int i = 0; i < users.size(); ++i)
        users[i].printInfo();
}
int UserManager::size() const {
    return users.size();
}
const User& UserManager::getAt(int index) const {
    return users[index];
}
