#include "allergies.h"

#include <array>

namespace allergies {
    static const std::array<std::string, 8> all_allergies = {
        "eggs", "peanuts", "shellfish", "strawberries",
        "tomatoes", "chocolate", "pollen", "cats"
    };

    allergy_test::allergy_test(int score) {
        for (std::size_t i = 0; i < all_allergies.size(); ++i) {
        if (score & (1 << i)) {
            allergies.insert(all_allergies[i]);
        }
        }
    }

    bool allergy_test::is_allergic_to(const std::string& food) const {
        return allergies.find(food) != allergies.end();
    }

    const std::unordered_set<std::string>& allergy_test::get_allergies() const {
        return allergies;
    }
}  // namespace allergies