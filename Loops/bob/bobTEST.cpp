#include "bob.h"
#include <string>
#include <iostream>
#include <cctype>
#include <iostream>
#include <algorithm>

namespace bob {
    std::string hey(std::string ourLine) {
        // Trim whitespace at the end of the input string
        ourLine.erase(std::find_if(ourLine.rbegin(), ourLine.rend(), [](unsigned char c){ return !std::isspace(c); }).base(), ourLine.end());

        bool isQuestion = ourLine.back() == '?';
        bool isYelling = std::any_of(ourLine.begin(), ourLine.end(), [](unsigned char c){ return std::isalpha(c); }) && std::all_of(ourLine.begin(), ourLine.end(), [](unsigned char c){ return !std::isalpha(c) || std::isupper(c); });
        bool isSilent = ourLine.find_first_not_of(" \t\n\r\f\v") == std::string::npos;

        if (isSilent) {
            return "Fine. Be that way!";
        } else if (isYelling && isQuestion) {
            return "Calm down, I know what I'm doing!";
        } else if (isYelling) {
            return "Whoa, chill out!";
        } else if (isQuestion) {
            return "Sure.";
        } else {
            return "Whatever.";
        }
    }
}  // namespace bob


int main() {
    std::cout << bob::hey("Okay if like my  spacebar  quite a bit?   ");
    return 0;
}