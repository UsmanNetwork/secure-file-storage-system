#include "logout.h"

// Constructor
Logout::Logout() {
    // Optional: Initialization of any variables if needed
}

// Function to log out the user
void Logout::logout() {
    // For a simple system, logging out might involve clearing the session or just printing a message
    std::cout << "Logging out..." << std::endl;
    // Optional: You can add any cleanup tasks here (e.g., clearing session data, resetting flags)
    std::cout << "Successfully logged out." << std::endl;
}
