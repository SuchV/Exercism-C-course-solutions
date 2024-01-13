#include "trinary.h"
#include <string>
#include <cmath>
#include <iostream>
// # "102012"
//     1       0       2       0       1       2    # the number
// 1*3^5 + 0*3^4 + 2*3^3 + 0*3^2 + 1*3^1 + 2*3^0    # the value
//   243 +     0 +    54 +     0 +     3 +     2 =  302


namespace trinary {
    int to_decimal(std::string tNumber) {
        if(!isdigit(tNumber[0])) return 0;
        int converted = 0;
        int powValue = tNumber.length()-1;
        for(int i = 0; i < static_cast<int>(tNumber.length()); i++) {
            converted += (tNumber[i] - '0') * pow(3, powValue);
            powValue--;
        }
        return converted;
    }
}  // namespace trinary


int main() {
    std::cout << trinary::to_decimal("102012");
    return 0;
}
