#include "deleteFile.h"

// Constructor to initialize file tracking
DeleteFile::DeleteFile() {
    // Optional: Initialization of fileList or other necessary attributes
}

// Function to delete a file
bool DeleteFile::deleteFile(const std::string &fileName) {
    // Check if the file exists in the list
    if (!removeFromList(fileName)) {
        std::cerr << "Error: File '" << fileName << "' not found in the system!" << std::endl;
        return false;
    }

    // Try to remove the file from the disk
    if (std::remove(fileName.c_str()) != 0) {
        std::cerr << "Error: Could not delete the file '" << fileName << "' from the disk!" << std::endl;
        return false;
    }

    std::cout << "File '" << fileName << "' deleted successfully." << std::endl;
    return true;
}

// Helper function to remove the file from the linked list
bool DeleteFile::removeFromList(const std::string &fileName) {
    auto it = std::find(fileList.begin(), fileList.end(), fileName);
    if (it != fileList.end()) {
        fileList.erase(it);
        return true;
    }
    return false;
}

// Function to list all current files (after deletion)
void DeleteFile::listCurrentFiles() {
    if (fileList.empty()) {
        std::cout << "No files in the system." << std::endl;
        return;
    }

    std::cout << "Current files in the system:" << std::endl;
    for (const std::string &fileName : fileList) {
        std::cout << "- " << fileName << std::endl;
    }
}
