#if !defined(LUHN_H)
#define LUHN_H

#include <string>
#include <algorithm>

namespace luhn {
    bool valid(std::string numberAsString);
}  // namespace luhn

#endif // LUHN_H