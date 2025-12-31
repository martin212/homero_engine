#ifndef HOMERO_LOGGER_HPP
#define HOMERO_LOGGER_HPP


#include <string>
#include <fstream>
#include <format>
#include <iostream>


namespace homero
{
    enum class LogLevel
    {
        Info,
        Warning,
        Error,
        Debug
    };

    class Logger
    {
    public:
        static void Init(const std::string& filename = "homero.log");

        template<typename... Args>
        static void Log(LogLevel level, std::string_view fmt, Args&&... args)
        {
            const std::string message = std::vformat(fmt, std::make_format_args(args...));
            Output(level, message);
        }

    private:
        static void Output(LogLevel level, const std::string& message);
        static std::ofstream logFile;
        static std::string LevelToString(LogLevel level);
    };
} // namespace homero

#endif // HOMERO_LOGGER_HPP