#include "decryptFile.h"
#include <fstream>
#include <iostream>
#include <sstream>

// Constructor that sets the decryption key
DecryptFile::DecryptFile(const std::string &key) : decryptionKey(key) {}

// Function to decrypt a file using XOR cipher
bool DecryptFile::decryptFile(const std::string &inputFile, const std::string &outputFile) {
    // Read the encrypted content of the file
    std::string fileContent = readFile(inputFile);
    if (fileContent.empty()) {
        std::cerr << "Error reading the input file!" << std::endl;
        return false;
    }

    // Decrypt the file content (using the same XOR operation as encryption)
    std::string decryptedContent;
    for (size_t i = 0; i < fileContent.size(); ++i) {
        decryptedContent += xorEncryptDecrypt(fileContent[i], decryptionKey[i % decryptionKey.size()]);
    }

    // Write the decrypted content to the output file
    if (!writeFile(outputFile, decryptedContent)) {
        std::cerr << "Error writing to the output file!" << std::endl;
        return false;
    }

    std::cout << "File decrypted successfully!" << std::endl;
    return true;
}

// Helper function to XOR encrypt/decrypt a single character
char DecryptFile::xorEncryptDecrypt(char data, char key) {
    return data ^ key;
}

// Function to read file content into a string
std::string DecryptFile::readFile(const std::string &fileName) {
    std::ifstream file(fileName, std::ios::in | std::ios::binary);
    std::stringstream buffer;

    if (file) {
        buffer << file.rdbuf();
        return buffer.str();
    } else {
        return "";
    }
}

// Function to write data to a file
bool DecryptFile::writeFile(const std::string &fileName, const std::string &data) {
    std::ofstream file(fileName, std::ios::out | std::ios::binary);
    if (file) {
        file.write(data.c_str(), data.size());
        return true;
    }
    return false;
}
