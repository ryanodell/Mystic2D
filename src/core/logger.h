#ifndef LOG_H
#define LOG_H
#include "spdlog/spdlog.h"

namespace mystic {
    class logger{
    public:
        static void init();
        static std::shared_ptr<spdlog::logger>& getInstance() { return spdLogger; }        
    private:
        static std::shared_ptr<spdlog::logger> spdLogger;
    };
}

#define MYSTIC_TRACE(...)         ::mystic::logger::getInstance()->trace(__VA_ARGS__)
#define MYSTIC_INFO(...)          ::mystic::logger::getInstance()->info(__VA_ARGS__)
#define MYSTIC_WARN(...)          ::mystic::logger::getInstance()->warn(__VA_ARGS__)
#define MYSTIC_ERROR(...)         ::mystic::logger::getInstance()->error(__VA_ARGS__)
#define MYSTIC_CRITICAL(...)      ::mystic::logger::getInstance()->critical(__VA_ARGS__)

#endif