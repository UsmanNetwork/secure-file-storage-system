#include "retrieveKey.h"

// Constructor
RetrieveKey::RetrieveKey() {
    // Optional: Initialization of any variables if needed
}

// Function to retrieve the encryption key from a file
std::string RetrieveKey::retrieveKey(const std::string &fileName) {
    // Check if the file can be opened
    if (!canOpenFile(fileName)) {
        std::cerr << "Error: Cannot open the file '" << fileName << "' for reading!" << std::endl;
        return "";
    }

    // Open the file in input mode
    std::ifstream file(fileName, std::ios::in);

    // Check if the file was successfully opened
    if (!file) {
        std::cerr << "Error: Could not open the file '" << fileName << "' for reading!" << std::endl;
        return "";
    }

    // Read the key from the file
    std::string key;
    std::getline(file, key);  // Read the entire line (the key)
    file.close();  // Close the file after reading

    if (key.empty()) {
        std::cerr << "Error: The key file '" << fileName << "' is empty!" << std::endl;
        return "";
    }

    std::cout << "Key successfully retrieved from '" << fileName << "'." << std::endl;
    return key;
}

// Helper function to check if the file exists and can be opened
bool RetrieveKey::canOpenFile(const std::string &fileName) {
    std::ifstream file(fileName);
    return file.is_open();
}
