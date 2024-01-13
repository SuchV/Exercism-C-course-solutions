#include "bob.h"
#include <string>
#include <algorithm>
#include <cctype>

namespace bob {
    std::string hey(std::string ourLine) {
        if (std::all_of(ourLine.begin(), ourLine.end(), [](unsigned char c){ return std::isupper(c); })) {
            if (ourLine.back() == '?') {
                return "Sure.";
            }
            return "Whoa, chill out!";
        }
    }
}  // namespace bob
