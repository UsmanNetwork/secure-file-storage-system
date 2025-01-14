#include "saveFile.h"

// Constructor to initialize file tracking
SaveFile::SaveFile() {
    // Optional: Initialization of fileList or other necessary attributes
}

// Function to save content to a file
bool SaveFile::saveFile(const std::string &fileName, const std::string &content) {
    // Check if the file already exists in the list
    if (!fileExists(fileName)) {
        // If the file doesn't exist, add it to the list of created files
        addToList(fileName);
    }

    // Open the file in output mode to create or overwrite it
    std::ofstream file(fileName, std::ios::out | std::ios::binary);

    // Check if the file was successfully opened
    if (!file) {
        std::cerr << "Error: Could not open the file '" << fileName << "' for saving!" << std::endl;
        return false;
    }

    // Write the content to the file
    file.write(content.c_str(), content.size());
    file.close();  // Close the file after writing

    std::cout << "File '" << fileName << "' saved successfully." << std::endl;
    return true;
}

// Helper function to check if a file exists in the linked list
bool SaveFile::fileExists(const std::string &fileName) {
    for (const std::string &file : fileList) {
        if (file == fileName) {
            return true;
        }
    }
    return false;
}

// Helper function to add the file to the linked list
void SaveFile::addToList(const std::string &fileName) {
    fileList.push_back(fileName);
}

// Function to list all current files (after saving)
void SaveFile::listCurrentFiles() {
    if (fileList.empty()) {
        std::cout << "No files in the system." << std::endl;
        return;
    }

    std::cout << "Current files in the system:" << std::endl;
    for (const std::string &fileName : fileList) {
        std::cout << "- " << fileName << std::endl;
    }
}
