#include "Log.h"
namespace Mystic {
std::shared_ptr<Logger> Log::m_coreLogger;
std::shared_ptr<Logger> Log::m_clientLogger;

Logger::Logger(LogLevel logLevel, const std::string& name, const std::string& fileName)
    : m_logLevel(logLevel), m_name(name) {
    if (!fileName.empty()) {
        m_file.open(fileName, std::ios::out | std::ios::app);
        if (!m_file.is_open()) {
            std::cerr << "Failed to open log file: " << fileName << std::endl;
        }
    }
}
void Logger::log(LogLevel logLevel, const std::string& message) {
    if (logLevel >= m_logLevel) {
        std::lock_guard<std::mutex> lock(m_mutex);
        std::string logMessage = getLogLevelString(logLevel) + ": " + message;
        if (m_file.is_open()) {
            m_file << logMessage << std::endl;
        }
        std::cout << logMessage << std::endl;
    }
}

void Logger::Trace(const std::string& message) { log(LogLevel::TRACE, message); }
void Logger::Info(const std::string& message) { log(LogLevel::INFO, message); }
void Logger::Warn(const std::string& message) { log(LogLevel::WARNING, message); }
void Logger::Error(const std::string& message) { log(LogLevel::ERROR, message); }
void Logger::Critical(const std::string& message) { log(LogLevel::CRITICAL, message); }

std::string Logger::getLogLevelString(LogLevel level) {
    switch (level) {
        case LogLevel::TRACE:
            return "TRACE";
        case LogLevel::INFO:
            return "INFO";
        case LogLevel::WARNING:
            return "WARNING";
        case LogLevel::ERROR:
            return "ERROR";
        case LogLevel::CRITICAL:
            return "CRITICAL";
        default:
            return "UNKNOWN";
    }
}
}  // namespace Mystic