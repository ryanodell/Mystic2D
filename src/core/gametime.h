#ifndef GAMETIME_H
#define GAMETIME_H
#include <chrono>

namespace Mystic {
    struct GameTime {
        float totalGameTime = 0;
        float totalElapsedTime = 0;
        bool isRunningSlowly = false;
        GameTime() {
            m_start = std::chrono::high_resolution_clock::now();
        }
        void tick() {
            totalElapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() 
                - m_start).count() * 0.001f * 0.001f * 0.001f;
            totalGameTime += totalElapsedTime;
        }
    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> m_start;
    };
}

#endif