#include "luhn.h"
#include <string>
#include <algorithm>

namespace luhn {
    bool valid(std::string numberAsString) {
        numberAsString.erase(std::remove(numberAsString.begin(), numberAsString.end(), ' '), numberAsString.end()); // Remove spaces

        if(numberAsString.length() < 2) return false; // checking length

        if (!std::all_of(numberAsString.begin(), numberAsString.end(), [](char c){ return std::isdigit(c); })) {
            return false; // checking if it's not a digit
        }
        int sum = 0;
        int length = numberAsString.length();
        for(int i = length - 1; i >= 0; i--) {
            int digit = numberAsString[i] - '0';
            if((length - i) % 2 == 0) {
                digit *= 2;
                if(digit > 9) digit -= 9;
            }
            sum += digit;
        }
        if(sum % 10 == 0) return true;

        return false;
    }
}  // namespace luhn
