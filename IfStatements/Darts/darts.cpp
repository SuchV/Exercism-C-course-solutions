#include "darts.h"
#include <cmath>

namespace darts {
    int score(double x, double y) {
        double vectorLen = sqrt((pow(x,2)+pow(y,2)));
        if (vectorLen > 10) return 0;
        if (vectorLen > 5) return 1;
        if (vectorLen > 1) return 5;
        return 10;
    }
} // namespace darts