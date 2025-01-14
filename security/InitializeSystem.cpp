#include "initializeSystem.h"
#include <iostream>

// Constructor
InitializeSystem::InitializeSystem() {
    // Optional: Initialization of any variables if needed
}

// Function to initialize the system
void InitializeSystem::initializeSystem() {
    std::cout << "Initializing system..." << std::endl;

    // Create necessary files
    createFiles();
    
    // Set up initial user credentials or system configuration
    setupInitialConfiguration();

    std::cout << "System initialized successfully!" << std::endl;
}

// Function to create the necessary files for the system
void InitializeSystem::createFiles() {
    // Check if the credentials file exists, create it if not
    std::ifstream checkFile("credentials.txt");
    if (!checkFile) {
        std::ofstream credentialsFile("credentials.txt");
        if (credentialsFile) {
            std::cout << "Created credentials.txt file." << std::endl;
            credentialsFile.close();
        } else {
            std::cerr << "Failed to create credentials.txt file." << std::endl;
        }
    }
    checkFile.close();
    
    // Add more files if needed (for example, logs, storage configuration, etc.)
}

// Function to set up initial user credentials or system configuration
void InitializeSystem::setupInitialConfiguration() {
    // For example, you might want to create an admin account or default configuration
    std::ifstream checkCredentials("credentials.txt");
    if (checkCredentials) {
        std::string username, password;
        // Read existing users (if any)
        while (checkCredentials >> username >> password) {
            // Check if default credentials exist
            if (username == "admin") {
                std::cout << "Admin account already set up." << std::endl;
                checkCredentials.close();
                return;
            }
        }
        checkCredentials.close();

        // If no admin found, create a default admin account (hashed password)
        std::ofstream credentialsFile("credentials.txt", std::ios::app);
        if (credentialsFile) {
            std::cout << "Creating default admin account..." << std::endl;
            // Here we use a default password, which should be hashed before storing
            credentialsFile << "admin " << "adminPassword123" << std::endl;
            std::cout << "Default admin account created." << std::endl;
        } else {
            std::cerr << "Failed to open credentials file for setup." << std::endl;
        }
    } else {
        std::cerr << "Failed to open credentials file." << std::endl;
    }
}
