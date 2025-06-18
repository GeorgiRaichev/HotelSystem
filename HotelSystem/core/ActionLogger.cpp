#include "ActionLogger.h"
#include <fstream>
#include <ctime>
#include <iostream>

void ActionLogger::log(const User& user, const char* action) {
    std::ofstream file("logs.txt", std::ios::app);
    if (!file.is_open()) {
        std::cerr << "Failed to open logs.txt\n";
        return;
    }

    time_t now = time(nullptr);
    tm* lt = localtime(&now);
    char timestamp[64];
    strftime(timestamp, sizeof(timestamp), "[%Y-%m-%d %H:%M:%S]", lt);

    file << timestamp << " "
        << user.getUsername().c_str() << " ("
        << user.getRole().c_str() << "): "
        << action << "\n";

    file.close();
}
