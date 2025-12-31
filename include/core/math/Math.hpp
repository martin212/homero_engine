#ifndef HOMERO_CORE_MATH_MATH_HPP
#define HOMERO_CORE_MATH_MATH_HPP


#include "core/Concepts.hpp"
#include "Vector3.hpp"


namespace homero
{
	namespace math
	{

		// Numeric vectors

		template<Numeric T = float>
		struct Vector2
		{
			T x{}, y{};

			// ... rest of your vector code
		};

		

		// Mathematical functions and constants

		constexpr double pi()
		{
			return 3.14159265358979323846;
		}

		// Example function: Calculate the square of a number
		template<typename T>
		T square(T value)
		{
			return value * value;
		}
	} // namespace math
} // namespace homero

#endif // !HOMERO_CORE_MATH_MATH_HPP
