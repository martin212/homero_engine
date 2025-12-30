cmake_minimum_required(VERSION 3.20)
project(homero_engine VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. ENGINE LIBRARY
# We use "file(GLOB_RECURSE...)" to automatically find .cpp files 
# so you don't have to manually list every new file you create.
file(GLOB_RECURSE ENGINE_SOURCES 
    "src/*.cpp"
    "include/*.hpp"
)

# Filter out main.cpp from the library so it doesn't conflict
list(FILTER ENGINE_SOURCES EXCLUDE REGEX "src/main.cpp")

add_library(EngineLib STATIC ${ENGINE_SOURCES})
set_target_properties(EngineLib PROPERTIES LINKER_LANGUAGE CXX)

# This allows you to #include "core/Engine.hpp" without the "include/" prefix
target_include_directories(EngineLib PUBLIC include)

# 2. EXECUTABLE
add_executable(homero_app src/main.cpp)
target_link_libraries(homero_app PRIVATE EngineLib)