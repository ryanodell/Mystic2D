#include "Log.h"

namespace Mystic {
Logger::Logger(LogLevel logLevel, const std::string& name, const std::string& fileName)
    : m_level(logLevel), m_name(name) {
}
}