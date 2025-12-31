include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
# For Windows compatibility
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(EngineTests 
    unit_test_main.cpp 
    001_test_test/first_test.cpp
    math/vector3_tests.cpp
)
target_link_libraries(EngineTests PRIVATE EngineLib GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(EngineTests)