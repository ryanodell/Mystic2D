#include "Log.h"
namespace Mystic {
std::shared_ptr<Logger> Log::m_coreLogger;
std::shared_ptr<Logger> Log::m_clientLogger;

Logger::Logger(LogLevel logLevel, const std::string& name, const std::string& fileName)
    : m_level(logLevel), m_name(name) {
}
}