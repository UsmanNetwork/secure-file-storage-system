#include <iostream>
#include <string>
#include "CreateFile.h"
#include "EncryptFile.h"
#include "DecryptFile.h"
#include "SaveFile.h"
#include "LoadFile.h"
#include "SearchFile.h"
#include "RenameFile.h"
#include "DeleteFile.h"
#include "Login.h"
#include "Logout.h"
#include "ValidateCredentials.h"
#include "InitializeSystem.h"
#include "Cleanup.h"
#include "GetFileSize.h"

int main() {
    std::cout << "Welcome to the Secure File Storage System!" << std::endl;

    // Initialize the system (e.g., setup encryption, login system)
    InitializeSystem systemInitializer;
    systemInitializer.initializeSystem();

    // Perform user login (assume credentials are validated)
    std::string username = "admin";
    std::string password = "adminPassword123";
    
    Login loginSystem;
    if (loginSystem.login(username, password)) {
        std::cout << "Login successful!" << std::endl;

        // Example: Create a file (only file name is passed)
        std::string fileName = "sample.txt";
        
        // CreateFile createFile;
        // createFile.createFile(fileName);  // Pass only the file name

        // Example: Get file size
        GetFileSize fileSizer;
        long long fileSize = fileSizer.getFileSize(fileName);
        if (fileSize != -1) {
            std::cout << "The size of the file \"" << fileName << "\" is: " << fileSize << " bytes." << std::endl;
        }

        // Example: Encrypt the file
        std::string encryptionKey = "securekey";  // Define the encryption key
        EncryptFile encryptFile(encryptionKey);   // Pass the encryption key to the EncryptFile constructor
        if (encryptFile.encryptFile(fileName, fileName + ".enc")) {
            std::cout << "File encrypted successfully!" << std::endl;
        } else {
            std::cout << "File encryption failed!" << std::endl;
        }

        // Example: Save the encrypted file content
        // SaveFile saveFile;
        // std::string encryptedContent = "Encrypted content of the file";  // This would be the content you want to save
        // if (saveFile.saveFile(fileName + ".enc", encryptedContent)) {  // Save the encrypted file with the content
        //     std::cout << "Encrypted file saved successfully!" << std::endl;
        // } else {
        //     std::cout << "Error saving the encrypted file!" << std::endl;
        // }

        // Example: Load the file (simulating loading from secure storage)
        LoadFile loadFile;
        loadFile.loadFile(fileName);

        // Example: Search for a file
        SearchFile searchFile;
        if (searchFile.searchFile(fileName)) {
            std::cout << "File found: " << fileName << std::endl;
        } else {
            std::cout << "File not found!" << std::endl;
        }

        // Example: Decrypt the file
        DecryptFile decryptFile(encryptionKey);  // Pass the decryption key here
        if (decryptFile.decryptFile(fileName + ".enc", fileName + ".dec")) {
            std::cout << "File decrypted successfully!" << std::endl;
        } else {
            std::cout << "File decryption failed!" << std::endl;
        }

        // Example: Rename the file
        std::string newFileName = "new_sample.txt";
        RenameFile renameFile;
        renameFile.renameFile(fileName, newFileName);

        // Example: Delete the file
        DeleteFile deleteFile;
        deleteFile.deleteFile(newFileName);

        // Example: Logout
        Logout logoutSystem;
        logoutSystem.logout();
    } else {
        std::cout << "Invalid credentials!" << std::endl;
    }

    // Clean up the system (clear sensitive data, close files, etc.)
    Cleanup cleanupSystem;
    cleanupSystem.cleanup();

    return 0;
}
