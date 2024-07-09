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

   private:
    LogLevel m_level;
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
    inline static std::shared_ptr<Logger>& GetCoreLogger() { return m_coreLogger; }
    inline static std::shared_ptr<Logger>& GetClientLogger() { return m_clientLogger; }

   private:
    static std::shared_ptr<Logger> m_coreLogger;
    static std::shared_ptr<Logger> m_clientLogger;
};

/* for reference:
#define MYSTIC_CORE_TRACE(...)    ::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define MYSTIC_CORE_INFO(...)     ::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MYSTIC_CORE_WARN(...)     ::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MYSTIC_CORE_ERROR(...)    ::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MYSTIC_CORE_CRITICAL(...) ::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define MYSTIC_TRACE(...)         ::Log::GetClientLogger()->trace(__VA_ARGS__)
#define MYSTIC_INFO(...)          ::Log::GetClientLogger()->info(__VA_ARGS__)
#define MYSTIC_WARN(...)          ::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MYSTIC_ERROR(...)         ::Log::GetClientLogger()->error(__VA_ARGS__)
#define MYSTIC_CRITICAL(...)      ::Log::GetClientLogger()->critical(__VA_ARGS__)
*/

}  // namespace Mystic