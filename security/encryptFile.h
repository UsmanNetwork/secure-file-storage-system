#ifndef ENCRYPTFILE_H
#define ENCRYPTFILE_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

class EncryptFile {
public:
    // Constructor
    EncryptFile(const std::string &key) : encryptionKey(key) {}
    // Function to encrypt a file
   bool encryptFile(const std::string &inputFile, const std::string &outputFile) {
    // Read the content of the file
    std::string fileContent = readFile(inputFile);
    if (fileContent.empty()) {
        std::cerr << "Error reading the input file!" << std::endl;
        return false;
    }

    // Encrypt the file content
    std::string encryptedContent;
    for (size_t i = 0; i < fileContent.size(); ++i) {
        encryptedContent += xorEncryptDecrypt(fileContent[i], encryptionKey[i % encryptionKey.size()]);
    }

    // Write the encrypted content to the output file
    if (!writeFile(outputFile, encryptedContent)) {
        std::cerr << "Error writing to the output file!" << std::endl;
        return false;
    }

    std::cout << "File encrypted successfully!" << std::endl;
    return true;
}

private:
    // XOR Encryption helper function
  char xorEncryptDecrypt(char data, char key) {
    return data ^ key;
}


    // Helper function to read file content
   std::string readFile(const std::string &fileName) {
    std::ifstream file(fileName, std::ios::in | std::ios::binary);
    std::stringstream buffer;

    if (file) {
        buffer << file.rdbuf();
        return buffer.str();
    } else {
        return "";
    }
}


    // Helper function to write encrypted content to file
   bool writeFile(const std::string &fileName, const std::string &data) {
    std::ofstream file(fileName, std::ios::out | std::ios::binary);
    if (file) {
        file.write(data.c_str(), data.size());
        return true;
    }
    return false;
}

    // Encryption key
    std::string encryptionKey;
};

#endif // ENCRYPTFILE_H
