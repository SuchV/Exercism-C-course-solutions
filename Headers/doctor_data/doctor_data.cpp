#include "doctor_data.h"

namespace heaven {
    Vessel::Vessel(std::string name1, int generation1) {
        name = name1;
        generation = generation1;
    }

    Vessel::Vessel(std::string name1, int generation1, star_map::System current_system1) {
        name = name1;
        generation = generation1;
        current_system = current_system1;
    }

    Vessel Vessel::replicate(std::string name1) {
        return Vessel{name1, this->generation + 1, this->current_system};
    }

    void Vessel::make_buster() {
        this->Vessel::busters = 1;
    }

    bool Vessel::shoot_buster() {
        if (this->Vessel::busters == 1) {
            this->Vessel::busters -= 1;
            return true;
        }
        return false;
    }

    std::string get_older_bob(Vessel name1, Vessel name2) {
        if (name1.generation < name2.generation) return name1.name;
        return name2.name;
    }

    bool in_the_same_system(Vessel name1, Vessel name2) {
        if (name1.current_system == name2.current_system) return true;
        return false;
    }
}
