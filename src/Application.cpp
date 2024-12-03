#include "Application.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/rotating_file_sink.h"

int Application::main()
{
    setUpLoggerWithRotatingFiles();

    return 0;
}

void Application::setUpLoggerWithRotatingFiles()
{
    constexpr int logFileMaxSize = 1048576 * 5;
    constexpr int logFiles = 3;
    const auto logger =
            spdlog::rotating_logger_mt("main_logger", "logs/log.txt", logFileMaxSize, logFiles);
    set_default_logger(logger);
}
