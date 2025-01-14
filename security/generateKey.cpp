#include "generateKey.h"

// Constructor to initialize random number generation
GenerateKey::GenerateKey() {
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Initialize random seed using current time
}

// Function to generate a simple encryption key of given length
std::string GenerateKey::generateKey(int length) {
    std::string key = "";

    // Generate the key by creating random characters
    for (int i = 0; i < length; ++i) {
        key += generateRandomChar();
    }

    std::cout << "Generated Key: " << key << std::endl;
    return key;
}

// Helper function to generate a random character
char GenerateKey::generateRandomChar() {
    // Generate a random printable character (ASCII range: 32-126)
    return static_cast<char>(std::rand() % 95 + 32);
}
