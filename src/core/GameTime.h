#ifndef GAMETIME_H
#define GAMETIME_H
#include <chrono>

namespace Mystic {
    struct GameTime {
        float TotalGameTime = 0;
        float TotalElapsedTime = 0;
        bool IsRunningSlowly = false;
        GameTime() {
            m_start = std::chrono::high_resolution_clock::now();
        }
        void Tick() {
            TotalElapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() 
                - m_start).count() * 0.001f * 0.001f * 0.001f;
            TotalGameTime += TotalElapsedTime;
        }
    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> m_start;
    };
}

#endif