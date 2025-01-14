#ifndef GENERATEKEY_H
#define GENERATEKEY_H

#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

class GenerateKey {
public:
    // Constructor
  GenerateKey() {
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Initialize random seed using current time
}

    // Function to generate a simple encryption key
    std::string generateKey(int length) {
    std::string key = "";

    // Generate the key by creating random characters
    for (int i = 0; i < length; ++i) {
        key += generateRandomChar();
    }

    std::cout << "Generated Key: " << key << std::endl;
    return key;
}

private:
    // Helper function to generate a random character
    char GenerateKey::generateRandomChar() {
    // Generate a random printable character (ASCII range: 32-126)
    return static_cast<char>(std::rand() % 95 + 32);
}
};

#endif // GENERATEKEY_H
