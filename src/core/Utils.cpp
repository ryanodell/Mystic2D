#include "Utils.h"

namespace Mystic {
glm::vec4 GetColorVec4(Color color) {
    switch (color) {
        case COLOR_RED:
            return glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);
        case COLOR_GREEN:
            return glm::vec4(0.0f, 1.0f, 0.0f, 1.0f);
        case COLOR_BLUE:
            return glm::vec4(0.0f, 0.0f, 1.0f, 1.0f);
        case COLOR_WHITE:
            return glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        case COLOR_BLACK:
            return glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
        default:
            return glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);  // Default to white
    }
}
}  // namespace Mystic