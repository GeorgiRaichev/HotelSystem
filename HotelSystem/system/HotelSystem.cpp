#include "HotelSystem.h"
#include <iostream>
#include <cstring>

void HotelSystem::run() {
    // Load all data from files
    FileManager::loadUsers(userManager);
    FileManager::loadRooms(roomManager);
    FileManager::loadGuests(guestManager);
    FileManager::loadReservations(reservationManager);

    while (!isLoggedIn) {
        std::cout << "\n=== Hotel Management System ===\n";
        std::cout << "1. Login\n2. Register\n3. Exit\n> ";
        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1: loginMenu(); break;
        case 2: registerMenu(); break;
        case 3:
            std::cout << "Exiting and saving data...\n";
            FileManager::saveUsers(userManager);
            FileManager::saveRooms(roomManager);
            FileManager::saveGuests(guestManager);
            FileManager::saveReservations(reservationManager);
            return;
        default:
            std::cout << "Invalid option. Please choose 1, 2, or 3.\n";
            break;
        }
    }

    mainMenu();
}

void HotelSystem::loginMenu() {
    while (true) {
        try {
            char username[64], password[64];
            std::cout << "\n=== Login ===\n";
            std::cout << "Username: ";
            std::cin >> username;
            std::cout << "Password: ";
            std::cin >> password;

            const User* user = userManager.loginUser(username, password);
            if (!user) {
                throw "Invalid username or password.";
            }

            currentUser = *user;
            isLoggedIn = true;
            ActionLogger::log(currentUser, "logged in successfully");
            break;

        }
        catch (const char* msg) {
            std::cout << "Error: " << msg << "\nPlease try again.\n";
        }
        catch (...) {
            std::cout << "An unexpected error occurred during login.\n";
        }
    }
}

void HotelSystem::registerMenu() {
    while (true) {
        try {
            char username[64], password[64], role[32];
            std::cout << "\n=== Register ===\n";
            std::cout << "Choose username: ";
            std::cin >> username;
            std::cout << "Choose password (min 4 chars): ";
            std::cin >> password;
            std::cout << "Enter role (manager / receptionist / accountant): ";
            std::cin >> role;

            if (std::strcmp(role, "manager") != 0 &&
                std::strcmp(role, "receptionist") != 0 &&
                std::strcmp(role, "accountant") != 0) {
                throw "Invalid role. Please enter: manager, receptionist or accountant.";
            }

            if (!userManager.registerUser(username, password, role)) {
                throw "Username already exists or password is too short.";
            }

            const User* user = userManager.loginUser(username, password);
            if (user) ActionLogger::log(*user, "registered a new user");

            std::cout << "Registration successful. You may now log in.\n";
            break;

        }
        catch (const char* msg) {
            std::cout << "Error: " << msg << "\nPlease try again.\n";
        }
        catch (...) {
            std::cout << "An unexpected error occurred during registration.\n";
        }
    }
}

void HotelSystem::mainMenu() {
    const char* role = currentUser.getRole().c_str();

    if (std::strcmp(role, "manager") == 0) {
        managerMenu();
    }
    else if (std::strcmp(role, "receptionist") == 0) {
        receptionistMenu();
    }
    else if (std::strcmp(role, "accountant") == 0) {
        accountantMenu();
    }
    else {
        std::cout << "Invalid user role. Returning to login screen.\n";
        isLoggedIn = false;
        run();
    }
}
