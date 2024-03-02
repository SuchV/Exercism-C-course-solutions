#pragma once
#include <string>

using namespace star_map;
namespace heaven {
    class Vessel {
        public:
            std::string name;
            int number;
            Vessel(std::string name1, int number1);
            Vessel(std::string name1, int number1, System type);
    };
}

namespace star_map {
    enum class System {
        BetaHydri,
        EpsilonEridani
    };
}
