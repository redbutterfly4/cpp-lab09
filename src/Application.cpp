#include "Application.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/rotating_file_sink.h"
#include "StackOnArray.h"
#include "StackOnList.h"

int Application::main()
{
    setUpLoggerWithRotatingFiles();
    spdlog::info("Application start.");

    StackOnList<int> stackOnList {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    stackOnList.push(11);

    return 0;
}

void Application::setUpLoggerWithRotatingFiles()
{
    constexpr int logFileMaxSize = 1048576 * 5;
    constexpr int logFiles = 3;
    const auto logger =
            spdlog::rotating_logger_mt("main_logger", "logs/log.txt", logFileMaxSize, logFiles);
    spdlog::set_default_logger(logger);

    spdlog::set_level(spdlog::level::trace);
    spdlog::debug("Initialized logger.");
}
