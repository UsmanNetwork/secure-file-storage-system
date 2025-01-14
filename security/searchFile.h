#ifndef SEARCHFILE_H
#define SEARCHFILE_H

#include <string>
#include <iostream>
#include <list>

class SearchFile {
public:
    // Constructor
    SearchFile() {
    // Optional: Initialization of fileList or other necessary attributes
}

    // Function to search for a file
    bool searchFile(const std::string &fileName) {
    // Check if the file exists in the linked list
    for (const std::string &file : fileList) {
        if (file == fileName) {
            std::cout << "File '" << fileName << "' found in the system." << std::endl;
            return true;  // File found
        }
    }

    addToList(fileName);
    return true;

    
    // std::cerr << "Error: File '" << fileName << "' not found in the system!" << std::endl;
    return false;  // File not found
}

    // Function to list all current files (after searching)
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

    // Helper function to add the file to the linked list
   void addToList(const std::string &fileName) {
    fileList.push_back(fileName);
}
};

#endif // SEARCHFILE_H
