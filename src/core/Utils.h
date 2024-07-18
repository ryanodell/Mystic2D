#ifndef UTILS_H
#define UTILS_H
#include <random>

#include "../Constants.h"
#include "../../GLM/glm.hpp"

namespace Mystic {
glm::vec4 GetColorVec4(Color color);

struct Character {
    unsigned int TextureId;
    glm::ivec2 Size;
    glm::ivec2 Bearing;
    unsigned int Advance;
};

class Random {
   public:
    Random() {}
    Random(int min, int max) : rng(rd()), dist(min, max) { }
    int GetRandomNumber() {
        return dist(rng);
    }
   private:
    std::random_device rd;                    // Seed generator
    std::mt19937 rng;                         // Mersenne Twister random number generator
    std::uniform_int_distribution<int> dist;  // Distribution
};
}  // namespace Mystic

#endif