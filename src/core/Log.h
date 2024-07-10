#ifndef LOG_H
#define LOG_H

#include <fstream>
#include <iostream>
#include <memory>
#include <mutex>
#include <string>

namespace Mystic {

enum class LogLevel {
    TRACE,
    INFO,
    WARNING,
    ERROR,
    CRITICAL
};

class Logger {
   public:
    Logger(LogLevel logLevel, const std::string& name, const std::string& fileName = "");
    ~Logger() {
        if (m_file.is_open()) {
            m_file.close();
        }
    }
    void Trace(const std::string& message);
    void Info(const std::string& message);
    void Warn(const std::string& message);
    void Error(const std::string& message);
    void Critical(const std::string& message);

   private:
    void log(LogLevel logLevel, const std::string& message);
    std::string getLogLevelString(LogLevel level);
    LogLevel m_logLevel;
    std::string m_name;
    std::ofstream m_file;
    std::mutex m_mutex;
};

class Log {
   public:
    static void Init() {
        m_coreLogger = std::make_shared<Logger>(LogLevel::TRACE, "CORE");
        m_clientLogger = std::make_shared<Logger>(LogLevel::TRACE, "CLIENT");
    }
    static void Init(LogLevel logLevel) {
        m_coreLogger = std::make_shared<Logger>(logLevel, "CORE");
        m_clientLogger = std::make_shared<Logger>(logLevel, "CLIENT");
    }
    static void Init(LogLevel logLevel, const std::string& logFile) {
        m_coreLogger = std::make_shared<Logger>(logLevel, "CORE", logFile);
        m_clientLogger = std::make_shared<Logger>(logLevel, "CLIENT", logFile);
    }
    inline static std::shared_ptr<Logger>& GetCoreLogger() { return m_coreLogger; }
    inline static std::shared_ptr<Logger>& GetClientLogger() { return m_clientLogger; }

   private:
    static std::shared_ptr<Logger> m_coreLogger;
    static std::shared_ptr<Logger> m_clientLogger;
};

#define MYSTIC_CORE_TRACE(...)    ::Mystic::Log::GetCoreLogger()->Trace(__VA_ARGS__)
#define MYSTIC_CORE_INFO(...)     ::Mystic::Log::GetCoreLogger()->Info(__VA_ARGS__)
#define MYSTIC_CORE_WARN(...)     ::Mystic::Log::GetCoreLogger()->Warn(__VA_ARGS__)
#define MYSTIC_CORE_ERROR(...)    ::Mystic::Log::GetCoreLogger()->Error(__VA_ARGS__)
#define MYSTIC_CORE_CRITICAL(...) ::Mystic::Log::GetCoreLogger()->Critical(__VA_ARGS__)

#define MYSTIC_TRACE(...)         ::Mystic::Log::GetClientLogger()->Trace(__VA_ARGS__)
#define MYSTIC_INFO(...)          ::Mystic::Log::GetClientLogger()->Info(__VA_ARGS__)
#define MYSTIC_WARN(...)          ::Mystic::Log::GetClientLogger()->Warn(__VA_ARGS__)
#define MYSTIC_ERROR(...)         ::Mystic::Log::GetClientLogger()->Error(__VA_ARGS__)
#define MYSTIC_CRITICAL(...)      ::Mystic::Log::GetClientLogger()->Critical(__VA_ARGS__)


}  // namespace Mystic

#endif