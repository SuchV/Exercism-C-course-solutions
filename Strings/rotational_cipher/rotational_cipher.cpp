#include "rotational_cipher.h"
#include <cctype>

namespace rotational_cipher {
    const std::string ALPHABET = "abcdefghijklmnopqrstuvwxyz";
    std::string rotate(std::string text, int rotation) {
        std::string encoded = "";
        int charIndex = 0;
        for(size_t i=0; i < text.length(); i++){
            if(!isalpha(text[i])) {
                encoded += text[i];
            }
            else {
                charIndex = ALPHABET.find(tolower(text[i]));
                if(isupper(text[i])) {
                    encoded += toupper(ALPHABET[(charIndex+rotation)%26]);
                }
                else {
                    encoded += ALPHABET[(charIndex+rotation)%26];
                }
            }
        }
        return encoded;
    }
}  // namespace rotational_cipher


#include <iostream>

int main() {
    std::cout << rotational_cipher::rotate("zzz", 5);
}