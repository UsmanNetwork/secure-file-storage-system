#include "login.h"

// Constructor
Login::Login() {
    // Optional: Initialization of any variables if needed
}

// Function to handle user login
bool Login::login(const std::string &username, const std::string &password) {
    std::string storedPassword;

    // Retrieve stored credentials (this could be from a file or database)
    if (!retrieveCredentials(username, storedPassword)) {
        std::cerr << "Error: User not found or credentials retrieval failed!" << std::endl;
        return false;
    }

    // Compare the entered password with the stored password
    if (password == storedPassword) {
        std::cout << "Login successful!" << std::endl;
        return true;
    } else {
        std::cerr << "Error: Incorrect password!" << std::endl;
        return false;
    }
}

// Function to change user password
bool Login::changePassword(const std::string &username, const std::string &oldPassword, const std::string &newPassword) {
    std::string storedPassword;

    // Retrieve stored credentials
    if (!retrieveCredentials(username, storedPassword)) {
        std::cerr << "Error: User not found or credentials retrieval failed!" << std::endl;
        return false;
    }

    // Compare the old password with the stored password
    if (oldPassword != storedPassword) {
        std::cerr << "Error: Old password is incorrect!" << std::endl;
        return false;
    }

    // Store the new password
    if (!storeCredentials(username, newPassword)) {
        std::cerr << "Error: Failed to store new password!" << std::endl;
        return false;
    }

    std::cout << "Password changed successfully!" << std::endl;
    return true;
}

// Helper function to retrieve user credentials from a file
bool Login::retrieveCredentials(const std::string &username, std::string &storedPassword) {
    std::ifstream file("credentials.txt");  // Assuming credentials are stored in a file named "credentials.txt"

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

// Helper function to store new credentials after password change
bool Login::storeCredentials(const std::string &username, const std::string &password) {
    std::ofstream file("credentials.txt", std::ios::app);  // Append mode to add new credentials

    if (!file.is_open()) {
        std::cerr << "Error: Unable to open credentials file for writing!" << std::endl;
        return false;
    }

    // Add username and new password to the file
    file << username << " " << password << std::endl;
    file.close();
    return true;
}
