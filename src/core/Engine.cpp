#include "core/Engine.hpp"


#include <iostream>

#include "core/Logger.hpp"


namespace homero
{
    void Initialize()
    {
        Logger::Init("homero_engine.log");
        Logger::Log(LogLevel::Info, "Homero Engine version {} started.", 0.1);
    }
} // namespace homero