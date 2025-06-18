#pragma once

#include "UserManager.h"

class FileManager {
public:
    static void loadUsers(UserManager& userManager);
    static void saveUsers(const UserManager& userManager);
};
