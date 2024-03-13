#pragma once
#include <string>

namespace star_map {
    enum class System {
        Sol,
        BetaHydri,
        EpsilonEridani,
        AlphaCentauri,
        DeltaEridani,
        Omicron2Eridani
    };
}

namespace heaven {
    class Vessel {
    public:
        std::string name;
        int generation;
        star_map::System current_system;
        int busters;
        Vessel(std::string name1, int generation1);
        Vessel(std::string name1, int generation1, star_map::System current_system);
        Vessel replicate(std::string name1);
        void make_buster();
        bool shoot_buster();
    };
    std::string get_older_bob(Vessel name1, Vessel name2);
    bool in_the_same_system(Vessel name1, Vessel name2);
}

