#include "FileManager.h"
#include <fstream>
#include <cstring>
#include <iostream>

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
