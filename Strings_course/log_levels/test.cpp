#include <iostream>
#include <string>
using namespace std;

namespace log_line {
    std::string message(std::string log) {
        // "[ERROR]: Invalid operation"
        int index = log.find(":");
        return log.substr(index + 2);
    }
    std::string log_level(std::string log) {
        int end_of_level = log.find(":");
        return log.substr(1, end_of_level - 2);
    }
    std::string reformat(std::string log) {
        std::string temp =  "(" + log_level(log) + ")";
        std::string swapped = message(log) + " " + temp;
        return swapped;
    }
} // namespace log_line

using namespace log_line;

int main() {
    cout << message("[ERROR]: Invalid operation");
    cout << "\n";
    cout << log_level("[ERROR]: Invalid operation");
    cout << "\n";
    cout << reformat("[ERROR]: Invalid operation");
   return 0;
}