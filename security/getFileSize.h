#ifndef GETFILESIZE_H
#define GETFILESIZE_H

#include <string>
#include <iostream>

class GetFileSize {
public:
    // Constructor
  GetFileSize() {
    // Optional initialization if needed
}

    // Function to get the size of a file
   long long getFileSize(const std::string &fileName) {
    if (!fileExists(fileName)) {
        std::cerr << "Error: File does not exist." << std::endl;
        return -1;  // Return -1 to indicate an error
    }

    // Open the file in binary mode
    std::ifstream file(fileName, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file." << std::endl;
        return -1;
    }

    // Move the file pointer to the end of the file
    file.seekg(0, std::ios::end);

    // Get the size of the file
    long long size = file.tellg();

    // Close the file
    file.close();

    return size;  // Return the file size in bytes
}


private:
    // Helper function to check if the file exists
    bool fileExists(const std::string &fileName) {
    std::ifstream file(fileName);
    return file.good();
}

};

#endif // GETFILESIZE_H
