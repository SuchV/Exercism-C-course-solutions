#include "atbash_cipher.h"
#include <string>
#include <cctype>

#include <iostream>

// For better solution, look at atbash_cipher_v2.cpp

namespace atbash_cipher {
    const std::string ALPHABET = "abcdefghijklmnopqrstuvwxyz";
    const std::string REVERSED = "zyxwvutsrqponmlkjihgfedcba";

    std::string encode(std::string text) {
        std::string encoded = "";
        int charIndex = 0;
        int nonSpaceCount = 0;
        for (size_t i = 1; i < text.length()+1; i++) {
            if(isdigit(text[i-1])) {
                encoded += text[i-1];
            }
            else if(text[i-1] == ' '){
                nonSpaceCount += 1;
            }
            else {
                charIndex = ALPHABET.find(tolower(text[i-1]));
                encoded += REVERSED[charIndex];
            }
            if((encoded.length() - nonSpaceCount) % 5 == 0) encoded = std::string(encoded) + " ";
        }
        return encoded;
    }
    std::string decode(std::string text) {
        std::string encoded = "";
        int charIndex = 0;
        for (size_t i = 0; i < text.length(); i++) {
            charIndex = REVERSED.find(tolower(text[i]));
            encoded += ALPHABET[charIndex];
        }
        return encoded;
    }
}  // namespace atbash_cipher

using namespace atbash_cipher;
#include <iostream>

int main() {
    std::string text = " 1234567890";
    std::cout << atbash_cipher::encode(text);
    // std::cout << atbash_cipher::decode(encode(text));
    return 0;
}
