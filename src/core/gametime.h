#ifndef GAMETIME_H
#define GAMETIME_H

namespace mystic {
    struct gameTime {
        float totalGameTime = 0;
        float totalElapsedTime = 0;
        bool isRunningSlowly = false;
    };
}

#endif