#ifndef RENAMEFILE_H
#define RENAMEFILE_H

#include <string>
#include <iostream>
#include <list>
#include <fstream>
#include<algorithm>

class RenameFile {
public:
    // Constructor
   RenameFile() {
    // Optional: Initialization of fileList or other necessary attributes
}

    // Function to rename a file
   bool renameFile(const std::string &oldFileName, const std::string &newFileName) {
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
    // Function to list all current files (after renaming)
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
    
    // Helper function to remove the file from the linked list
  bool removeFromList(const std::string &fileName) {
    auto it = std::find(fileList.begin(), fileList.end(), fileName);
    if (it != fileList.end()) {
        fileList.erase(it);
        return true;
    }
    return false;
}

    // Helper function to add a new file to the linked list
   void addToList(const std::string &fileName) {
    fileList.push_back(fileName);
}
};

#endif // RENAMEFILE_H
