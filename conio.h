#include <iostream>
#include <cstdlib> // For system function

void clearScreen() {
    #ifdef _WIN32
        std::system("cls");
    #else
        // Assume Unix-like system
        std::system("clear");
    #endif
}

int main() {
    // Use clearScreen() function to clear the screen
    clearScreen();

    // Your other code here...

    return 0;
}
