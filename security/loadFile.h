#ifndef LOADFILE_H
#define LOADFILE_H

#include <string>
#include <iostream>
#include <list>
#include <fstream>

class LoadFile {
public:
    // Constructor
  std::string  loadFile(const std::string &fileName) {
    // Check if the file exists in the list of created files
    if (!fileExists(fileName)) {
        std::cerr << "Error: File '" << fileName << "' not found in the system!" << std::endl;
        return "";
    }

    // Open the file in input mode
    std::ifstream file(fileName, std::ios::in | std::ios::binary);

    // Check if the file was successfully opened
    if (!file) {
        std::cerr << "Error: Could not open the file '" << fileName << "' for reading!" << std::endl;
        return "";
    }
   std::string content;
    file.seekg(0, std::ios::end);  // Move to the end of the file to get its size
    content.resize(file.tellg());  // Resize the string to the file size
    file.seekg(0, std::ios::beg);  // Move back to the beginning of the file
    file.read(&content[0], content.size());  // Read the file content into the string
    file.close();  // Close the file after reading

    std::cout << "File '" << fileName << "' loaded successfully." << std::endl;
    return content;
}

    // Function to load content from a file
    

    // Function to list all current files (after loading)
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

#endif // LOADFILE_H
