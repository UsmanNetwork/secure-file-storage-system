#include "searchFile.h"

// Constructor to initialize file tracking
SearchFile::SearchFile() {
    // Optional: Initialization of fileList or other necessary attributes
}

// Function to search for a file
bool SearchFile::searchFile(const std::string &fileName) {
    // Check if the file exists in the linked list
    for (const std::string &file : fileList) {
        if (file == fileName) {
            std::cout << "File '" << fileName << "' found in the system." << std::endl;
            return true;  // File found
        }
    }
    
    std::cerr << "Error: File '" << fileName << "' not found in the system!" << std::endl;
    return false;  // File not found
}

// Helper function to add the file to the linked list
void SearchFile::addToList(const std::string &fileName) {
    fileList.push_back(fileName);
}

// Function to list all current files (after searching)
void SearchFile::listCurrentFiles() {
    if (fileList.empty()) {
        std::cout << "No files in the system." << std::endl;
        return;
    }

    std::cout << "Current files in the system:" << std::endl;
    for (const std::string &fileName : fileList) {
        std::cout << "- " << fileName << std::endl;
    }
}
