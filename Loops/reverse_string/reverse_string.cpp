#include "reverse_string.h"
#include <string>

namespace reverse_string {
    std::string reverse_string(std::string ourText) {
        std::string inversedText = "";

        for(int i = static_cast<int>(ourText.length()); i > 0;i--) {
            inversedText += ourText[i-1];
        }
        return inversedText;
    }
}  // namespace reverse_string
