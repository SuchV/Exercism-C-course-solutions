#include "armstrong_numbers.h"
#include <string>
#include <cmath>
#include <stdexcept>

namespace armstrong_numbers {
    bool is_armstrong_number(int number) {
        std::string numberAsString = std::to_string(number);
        int numberLength = numberAsString.length();
        int sum = 0;
        for(int i=0; i<numberLength; i++){
            sum += pow((numberAsString[i] - '0'), numberLength);
        }
        if (sum == number) return true; 
        return false;
    }
}  // namespace armstrong_numbers

#include <iostream>
int main() {
    std::cout << armstrong_numbers::is_armstrong_number(153);
}