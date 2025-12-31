#ifndef HOMERO_CORE_MATH_VECTOR3
#define HOMERO_CORE_MATH_VECTOR3


#include <cmath>
#include <ostream>
#include <string>

#include "core/Concepts.hpp"


namespace homero::math
{
	template<Numeric T = float>
	struct Vector3
	{
		T x{};
		T y{};
		T z{};

		Vector3() = default;
		constexpr Vector3(T x, T y, T z)
			: x(x), y(y), z(z)
		{
		}

		// C++20 spaceship operator for automatic ==, !=, <, etc.
		constexpr auto operator<=>(const Vector3&) const = default;

		// Basic addition
		constexpr Vector3 operator+(const Vector3& other) const
		{
			return { x + other.x, y + other.y, z + other.z };
		}

		// Basic subtraction
		constexpr Vector3 operator-(const Vector3& other) const
		{
			return { x - other.x, y - other.y, z - other.z };
		}

		// Scalar multiplication
		constexpr Vector3 operator*(T scalar) const
		{
			return { x * scalar, y * scalar, z * scalar };
		}

		// Scalar division
		constexpr Vector3 operator/(T scalar) const
		{
			return { x / scalar, y / scalar, z / scalar };
		}

		// Dot product
		constexpr T dotProduct(const Vector3& other) const
		{
			return x * other.x + y * other.y + z * other.z;
		}

		// Cross product
		constexpr Vector3 crossProduct(const Vector3& other) const
		{
			return {
				y * other.z - z * other.y,
				z * other.x - x * other.z,
				x * other.y - y * other.x
			};
			/*
			a = (ax, ay, az)
			b = (bx, by, bz)
			a × b = (ay * bz - az * by, = (cx, = c
					 az * bx - ax * bz,    cy,
					 ax * by - ay * bx)    cz)
			*/
		}

		// Magnitude/module (length) of the vector
		// std::hypot is not constexpr in C++20, so this is non-constexpr.
		T magnitude() const
		{
			// Get the promoted type for this specific T
			using calc_t = precision_t<T>;

			return static_cast<T>(std::hypot(static_cast<calc_t>(x),
											static_cast<calc_t>(y),
											static_cast<calc_t>(z)));
		}

		// Normalize the vector (make it unit length)
		// Non-constexpr because it calls magnitude() which calls std::hypot
		Vector3 normalize() const
		{
			// compute mag using calc_t for consistent precision during comparison/division
			using calc_t = precision_t<T>;

			const calc_t mag = static_cast<calc_t>(magnitude());
			if (mag > calc_t{ 0 })
			{
				return { static_cast<T>(static_cast<calc_t>(x) / mag),
						static_cast<T>(static_cast<calc_t>(y) / mag),
						static_cast<T>(static_cast<calc_t>(z) / mag) };
			}

			return { T{ 0 }, T{ 0 }, T{ 0 } }; // Avoid division by zero
		}

		// To string representation (for debugging)
		std::string toString() const
		{
			return "Vector3(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ")";
		}

		// Output stream operator overload for easy printing
		friend std::ostream& operator<<(std::ostream& os, const Vector3& v)
		{
			os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
			return os;
		}
	};
} // namespace homero::math

#endif // !HOMERO_CORE_MATH_VECTOR3
