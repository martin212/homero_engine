cmake_minimum_required(VERSION 3.20)
project(homero_engine VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. THE LIBRARY (The "Brain")
# Make sure these files EXACTLY exist in these folders
add_library(EngineLib STATIC 
    "src/core/Engine.cpp"
    "include/core/Engine.hpp"
 "src/core/Logger.cpp")
target_include_directories(EngineLib PUBLIC "include")

# 2. THE EXECUTABLE (The "Program")
# Make sure main.cpp exists in src/
add_executable(homero_app "src/main.cpp" "src/core/Logger.cpp")

# 3. THE LINK (Connecting the two)
target_link_libraries(homero_app PRIVATE EngineLib)

# 4. Option to turn tests on/off (CI will turn this ON)
option(BUILD_ENGINE_TESTS "Build unit tests" ON)

if(BUILD_ENGINE_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()