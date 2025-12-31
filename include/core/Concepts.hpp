#ifndef HOMERO_CORE_CONCEPTS_HPP
#define HOMERO_CORE_CONCEPTS_HPP


#include <concepts>
#include <type_traits>


namespace homero
{
    // Defines what types can be used for calculations
    template<typename T>
    concept Numeric = std::is_arithmetic_v<T>;

    // Precision type for internal calculations:
    // - Use long double for integral T to preserve fractional intermediate results.
    // - Otherwise, use T (float/double/long double).
    template<typename T>
    using precision_t = std::conditional_t<std::is_integral_v<T>, long double, T>;

    // You can add more later, e.g., 
    // concept StringLike = std::is_convertible_v<T, std::string_view>;
} // namespace homero

#endif // HOMERO_CORE_CONCEPTS_HPP