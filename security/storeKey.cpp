#include "storeKey.h"

// Constructor
StoreKey::StoreKey() {
    // Optional: Initialization of any variables if needed
}

// Function to store the encryption key in a file
bool StoreKey::storeKey(const std::string &key, const std::string &fileName) {
    // Check if the file can be opened for writing
    if (!canOpenFile(fileName)) {
        std::cerr << "Error: Cannot open the file '" << fileName << "' for writing!" << std::endl;
        return false;
    }

    // Open the file in output mode
    std::ofstream file(fileName, std::ios::out | std::ios::trunc); // Use truncation to overwrite existing content

    // Check if the file was successfully opened
    if (!file) {
        std::cerr << "Error: Could not open the file '" << fileName << "' for writing!" << std::endl;
        return false;
    }

    // Write the key to the file
    file << key;
    file.close();  // Close the file after writing

    std::cout << "Key successfully stored in '" << fileName << "'." << std::endl;
    return true;
}

// Helper function to check if the file can be opened for writing
bool StoreKey::canOpenFile(const std::string &fileName) {
    std::ofstream file(fileName);
    return file.is_open();
}
