#ifndef LOGOUT_H
#define LOGOUT_H

#include <iostream>

class Logout {
public:
    // Constructor
    Logout() {
    // Optional: Initialization of any variables if needed
}


    // Function to log out the user
    void logout() {
    // For a simple system, logging out might involve clearing the session or just printing a message
    std::cout << "Logging out..." << std::endl;
    // Optional: You can add any cleanup tasks here (e.g., clearing session data, resetting flags)
    std::cout << "Successfully logged out." << std::endl;
}
};

#endif // LOGOUT_H
