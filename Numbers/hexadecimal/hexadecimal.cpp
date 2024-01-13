#include "hexadecimal.h"
#include <cmath>
#include <map>
#include <string>

//a2 = 162
namespace hexadecimal {
    int convert(std::string hex) {
        int converted = 0;
        int powValue = hex.length()-1;
        std::map<char, int> hexChars;
        hexChars['a'] = 10; hexChars['b'] = 11; hexChars['c'] = 12; hexChars['d'] = 13; hexChars['e'] = 14; hexChars['f'] = 15;
        
        for(int i = 0; i < static_cast<int>(hex.length()); i++) {
            if(hexChars.find(hex[i]) != hexChars.end()) {
                converted += hexChars[hex[i]] * pow(16, powValue); 
            }
            else if(isdigit(hex[i])) {
                converted += (hex[i] - '0') * pow(16, powValue);
            }
            else {
                return 0;
            }
            powValue--;
        }
        return converted;
    }
}  // namespace hexadecimal
