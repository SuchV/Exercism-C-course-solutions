#include "eliuds_eggs.h"
#include <cmath>
#include <string>

#include <iostream>

namespace chicken_coop {
    int positions_to_quantity(int number) {
        int bitCounter = 0;
        int temp = 0;
        int power = 1;
        int i = 0;
        while (power <= number / 2) {
            power *= 2;
            i++;
        }
        while(temp < number) {
            if (temp + pow(2, i) <= number ) {
                temp += pow(2, i);
                bitCounter++;
            }
            i--;
            std::cout << bitCounter << std::endl;
        }

        return 0;
    }
}  // namespace chicken_coop


int main() {
    chicken_coop::positions_to_quantity(16);
}