#include "atbash_cipher.h"
#include <string>
#include <cctype>
#include <algorithm>

#include <iostream>

namespace atbash_cipher {
    const std::string ALPHABET = "abcdefghijklmnopqrstuvwxyz";
    const std::string REVERSED = "zyxwvutsrqponmlkjihgfedcba";

    std::string encode(std::string text) {
        std::string encoded = "";
        int charIndex = 0;
        int nonSpaceCount = 0;

        text.erase(std::remove(text.begin(), text.end(), ' '), text.end()); // Remove spaces
        text.erase(std::remove(text.begin(), text.end(), ','), text.end()); // Remove commas
        text.erase(std::remove(text.begin(), text.end(), '.'), text.end()); // Remove periods
        
        for (size_t i = 0; i < text.length(); i++) {
            if(isdigit(text[i])) {
                encoded += text[i];
                nonSpaceCount++;
            }
            else {
                charIndex = ALPHABET.find(tolower(text[i]));
                encoded += REVERSED[charIndex];
                nonSpaceCount++;
            }
            if(nonSpaceCount % 5 == 0 && i != text.length() - 1) {
                encoded += " ";
            }
        }
        return encoded;
    }
    std::string decode(std::string text) {
        std::string encoded = "";
        int charIndex = 0;
        text.erase(std::remove(text.begin(), text.end(), ' '), text.end()); // Remove spaces

        for (size_t i = 0; i < text.length(); i++) {
            if(isdigit(text[i])) {
                encoded += text[i];
            }
            else {
                charIndex = REVERSED.find(text[i]);
                encoded += ALPHABET[charIndex];
            }
        }
        return encoded;
    }
}   // namespace atbash_cipher

using namespace atbash_cipher;
#include <iostream>

int main() {
    std::string text = "gvhgr mt123 gvhgr mt";
    // std::cout << atbash_cipher::encode(text);
    std::cout << atbash_cipher::decode(text);
    return 0;
}
