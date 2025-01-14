#include "cleanup.h"
#include <iostream>
#include <fstream>

Cleanup::Cleanup() {
    // Optional initialization if needed
}

// Function to clean up the system
void Cleanup::cleanup() {
    std::cout << "Cleaning up system..." << std::endl;

    // Close any open files
    closeFiles();

    // Clear sensitive data from memory
    clearSensitiveData();

    std::cout << "Cleanup completed!" << std::endl;
}

// Function to close files (if any are open)
void Cleanup::closeFiles() {
    // Close any files you opened during the system operation
    // Example: Closing a file that stores user credentials or logs
    std::ofstream credentialsFile("credentials.txt", std::ios::out | std::ios::trunc);
    if (credentialsFile.is_open()) {
        std::cout << "Closed credentials file." << std::endl;
        credentialsFile.close();
    } else {
        std::cerr << "No file to close or failed to close credentials file." << std::endl;
    }

    // Add more files that need to be closed here, if applicable (log files, configuration files, etc.)
}

// Function to clear sensitive data from memory (e.g., passwords, encryption keys)
void Cleanup::clearSensitiveData() {
    // Example: Clearing any sensitive data variables from memory
    // If you have sensitive variables, like passwords or encryption keys, clear them from memory
    std::string password = "adminPassword123";  // Example password (should not be used in practice like this)
    password.clear();  // Clears the password from memory
    std::cout << "Cleared sensitive data from memory." << std::endl;

    // Add more sensitive data clearing tasks if necessary (encryption keys, session tokens, etc.)
}
