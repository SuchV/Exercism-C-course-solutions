#include "doctor_data.h"

using namespace star_map;
namespace heaven {
    class Vessel {
        public:
            std::string name;
            int number;
            System type;
            Vessel(std::string name1, int number1) {
                name = name1;
                number = number1;
            }
            Vessel(std::string name1, int number1, System type1) {
                name = name1;
                number = number1;
                type = type1;
            }
    };
}

namespace star_map {
    enum class System {
        BetaHydri,
        EpsilonEridani
    };
}