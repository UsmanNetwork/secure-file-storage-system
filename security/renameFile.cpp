#include "renameFile.h"
#include <algorithm>  // For std::find

// Constructor to initialize file tracking
RenameFile::RenameFile() {
    // Optional: Initialization of fileList or other necessary attributes
}

// Function to rename a file
bool RenameFile::renameFile(const std::string &oldFileName, const std::string &newFileName) {
    // Check if the old file exists in the list
    if (!removeFromList(oldFileName)) {
        std::cerr << "Error: File '" << oldFileName << "' not found in the system!" << std::endl;
        return false;
    }

    // Try to rename the file on the disk
    if (std::rename(oldFileName.c_str(), newFileName.c_str()) != 0) {
        std::cerr << "Error: Could not rename the file on the disk!" << std::endl;
        return false;
    }

    // Add the new file name to the list of created files
    addToList(newFileName);

    std::cout << "File renamed from '" << oldFileName << "' to '" << newFileName << "' successfully." << std::endl;
    return true;
}

// Helper function to remove the file from the linked list
bool RenameFile::removeFromList(const std::string &fileName) {
    auto it = std::find(fileList.begin(), fileList.end(), fileName);
    if (it != fileList.end()) {
        fileList.erase(it);
        return true;
    }
    return false;
}

// Helper function to add the new file to the linked list
void RenameFile::addToList(const std::string &fileName) {
    fileList.push_back(fileName);
}

// Function to list all current files (after renaming)
void RenameFile::listCurrentFiles() {
    if (fileList.empty()) {
        std::cout << "No files in the system." << std::endl;
        return;
    }

    std::cout << "Current files in the system:" << std::endl;
    for (const std::string &fileName : fileList) {
        std::cout << "- " << fileName << std::endl;
    }
}
