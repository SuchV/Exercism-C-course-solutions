#include "vehicle_purchase.h"
namespace vehicle_purchase {

    // needs_license determines whether a license is needed to drive a type of vehicle. Only "car" and "truck" require a license.
    bool needs_license(std::string kind){
        if(kind == "car" || kind == "truck") return true;
        return false;
    }

    // choose_vehicle recommends a vehicle for selection. It always recommends the vehicle that comes first in lexicographical order.
    std::string choose_vehicle(std::string option1, std::string option2) {
        if(option1 < option2) return option1 + " is clearly the better choice.";
        else if(option1 > option2) return option2 + " is clearly the better choice.";
        else return "both are same";
    }

    // calculate_resell_price calculates how much a vehicle can resell for at a certain age.
    double calculate_resell_price(double original_price, double age) {
        if(age < 3) return 80.0*original_price/100.00;
        if(age >= 3 && age < 10) return 70.0*original_price/100.00;
        if(age >= 10) return 50.0*original_price/100.00;
        return 0.0;
    }

}  // namespace vehicle_purchase