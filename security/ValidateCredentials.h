#ifndef VALIDATECREDENTIALS_H
#define VALIDATECREDENTIALS_H

#include <string>
#include <iostream>
#include <fstream>

class ValidateCredentials {
public:
    // Constructor
    
ValidateCredentials() {
    // Optional: Initialization of any variables if needed
}
    // Function to validate user credentials
   bool validateCredentials(const std::string &username, const std::string &password) {
    std::string storedPassword;

    // Retrieve the stored password for the username
    if (!retrieveStoredPassword(username, storedPassword)) {
        std::cerr << "Error: Username not found!" << std::endl;
        return false;  // Username not found
    }

    // Compare the entered password with the stored password
    if (password == storedPassword) {
        std::cout << "Credentials are valid!" << std::endl;
        return true;  // Password is correct
    } else {
        std::cerr << "Error: Incorrect password!" << std::endl;
        return false;  // Password is incorrect
    }
}

private:
    // Helper function to retrieve stored password for a given username
   bool retrieveStoredPassword(const std::string &username, std::string &storedPassword) {
    std::ifstream file("credentials.txt");  // File where credentials are stored

    if (!file.is_open()) {
        std::cerr << "Error: Unable to open credentials file!" << std::endl;
        return false;
    }

    std::string storedUsername;
    while (file >> storedUsername >> storedPassword) {
        if (storedUsername == username) {
            file.close();
            return true;  // Found matching username, stored password in 'storedPassword'
        }
    }

    file.close();
    return false;  // Username not found
}
};
#endif // VALIDATECREDENTIALS_H
