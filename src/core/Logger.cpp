#include "core/Logger.hpp"


#include <chrono>


namespace homero
{
    std::ofstream Logger::logFile;

    void Logger::Init(const std::string& filename)
    {
        logFile.open(filename, std::ios::app);
    }

    std::string Logger::LevelToString(LogLevel level)
    {
        switch (level)
        {
        case LogLevel::Info:    return "INFO";
        case LogLevel::Warning: return "WARNING";
        case LogLevel::Error:   return "ERROR";
        case LogLevel::Debug:   return "DEBUG";
        default:                return "UNKNOWN";
        }
    }

    void Logger::Output(LogLevel level, const std::string& message)
    {
        const auto now = std::chrono::system_clock::now();
        const std::string timestamp = std::format("{:%H:%M:%S}", now);

        const std::string fullLine = std::format("[{}] [{}] {}\n", timestamp, LevelToString(level), message);

        // Output to file (important for your ASCII engine!)
        if (logFile.is_open())
        {
            logFile << fullLine;
            logFile.flush();
        }

        // Output to IDE debug console
        std::cout << fullLine;
    }
} // namespace homero