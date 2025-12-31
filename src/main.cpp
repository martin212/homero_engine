#include <iostream>
#include <format> // Requires C++20

#include "core/math/Math.hpp"

int main() {
    std::cout << std::format("Welcome to {}, version {}!", "Homero Engine", 0.1) << std::endl;
    return 0;
}