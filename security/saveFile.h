#ifndef SAVEFILE_H
#define SAVEFILE_H

#include <string>
#include <iostream>
#include <list>
#include <fstream>

class SaveFile {
public:
    // Constructor
    SaveFile() {
    // Optional: Initialization of fileList or other necessary attributes
}

    // Function to save content to a file
   bool saveFile(const std::string &fileName, const std::string &content) {
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
    // Function to list all current files (after saving)
   void listCurrentFiles() {
    if (fileList.empty()) {
        std::cout << "No files in the system." << std::endl;
        return;
    }

    std::cout << "Current files in the system:" << std::endl;
    for (const std::string &fileName : fileList) {
        std::cout << "- " << fileName << std::endl;
    }
}

private:
    // Linked list to track created files
    std::list<std::string> fileList;

    // Helper function to check if a file already exists in the list
    bool fileExists(const std::string &fileName) {
    for (const std::string &file : fileList) {
        if (file == fileName) {
            return true;
        }
    }
    return false;
}
    // Helper function to add the file to the linked list
   void addToList(const std::string &fileName) {
    fileList.push_back(fileName);
}
};

#endif // SAVEFILE_H
