// #include "logger.h"
// #include <spdlog/sinks/basic_file_sink.h>
// #include <spdlog/sinks/stdout_color_sinks.h>

// namespace mystic {
//     std::string log_name = "mystic_logger";
//     std::shared_ptr<spdlog::logger> logger::spdLogger;
//     void logger::init() {
//         std::vector<spdlog::sink_ptr> sinks;
//         sinks.push_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
//         sinks.push_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>(log_name + ".log", true));
//         spdLogger = std::make_shared<spdlog::logger>(log_name, sinks.begin(), sinks.end());
//         spdlog::register_logger(spdLogger);
//         spdLogger->set_level(spdlog::level::debug); // Set default log level
//         spdLogger->set_pattern("[%Y-%m-%d %H:%M:%S] [%^%l%$] %v");
//     }
// };