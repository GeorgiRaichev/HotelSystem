#include "HotelSystem.h"
#include <iostream>

int main() {
    try {
        HotelSystem system;
        system.run();  
    }
    catch (const char* msg) {
        std::cout << "Fatal error: " << msg << "\n";
    }
    catch (...) {
        std::cout << "An unexpected fatal error occurred.\n";
    }

    return 0;
}
