#include "createFile.h"

// Constructor to initialize file tracking
CreateFile() {
    // Optional: Initialization of fileList or other necessary attributes
}

// Function to create a new file
bool createFile(const std::string &fileName) {
    // Open the file in output mode to create it if it doesn't exist
    std::ofstream file(fileName);

    // Check if the file was created successfully
    if (file) {
        // Add the file to the list of created files
        fileList.push_back(fileName);

        std::cout << "File '" << fileName << "' created successfully." << std::endl;
        file.close();  // Close the file after creating
        return true;
    } else {
        std::cerr << "Error: Could not create the file '" << fileName << "'!" << std::endl;
        return false;
    }
}

// Function to list all created files (using linked list for storage)
void listCreatedFiles() {
    if (fileList.empty()) {
        std::cout << "No files created yet." << std::endl;
        return;
    }

    std::cout << "List of created files:" << std::endl;
    for (const std::string &fileName : fileList) {
        std::cout << "- " << fileName << std::endl;
    }
}
