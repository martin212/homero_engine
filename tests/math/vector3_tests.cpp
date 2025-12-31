#include <gtest/gtest.h>

#include "core/math/Vector3.hpp"

namespace homero::tests::math
{
	using homero::math::Vector3;

	// Test Vector3 creation and equality
	TEST(Vector3Test, CreationAndEquality)
	{
		// Integer vectors
		const Vector3<int> iV1(1, 2, 3);
		const Vector3<int> iV2(1, 2, 3);
		const Vector3<int> iV3(4, 5, 6);
		EXPECT_EQ(iV1, iV2);
		EXPECT_NE(iV1, iV3);

		// Float vectors
		const Vector3<float> fV1(1.0f, 2.0f, 3.0f);
		const Vector3<float> fV2(1.0f, 2.0f, 3.0f);
		const Vector3<float> fV3(4.0f, 5.0f, 6.0f);
		EXPECT_EQ(fV1, fV2);
		EXPECT_NE(fV1, fV3);

		// Double vectors
		const Vector3<double> dV1(1.0, 2.0, 3.0);
		const Vector3<double> dV2(1.0, 2.0, 3.0);
		const Vector3<double> dV3(4.0, 5.0, 6.0);
		EXPECT_EQ(dV1, dV2);
		EXPECT_NE(dV1, dV3);
	}

	// Test Vector3 int operations

	TEST(Vector3Test, IntAddition)
	{
		const Vector3<int> v1(1, 2, 3);
		const Vector3<int> v2(4, 5, 6);
		const Vector3<int> expected(5, 7, 9);
		const Vector3<int> result = v1 + v2;
		EXPECT_EQ(result, expected);
	}

	TEST(Vector3Test, IntSubtraction)
	{
		const Vector3<int> v1(4, 5, 6);
		const Vector3<int> v2(1, 2, 3);
		const Vector3<int> expected(3, 3, 3);
		const Vector3<int> result = v1 - v2;
		EXPECT_EQ(result, expected);
	}

	TEST(Vector3Test, IntMultiplication)
	{
		const Vector3<int> v(1, 2, 3);
		const int scalar = 2;
		const Vector3<int> expected(2, 4, 6);
		const Vector3<int> result = v * scalar;
		EXPECT_EQ(result, expected);
	}

	TEST(Vector3Test, IntDivision)
	{
		const Vector3<int> v(4, 6, 8);
		const int scalar = 2;
		const Vector3<int> expected(2, 3, 4);
		const Vector3<int> result = v / scalar;
		EXPECT_EQ(result, expected);
	}

	TEST(Vector3Test, IntDotProduct)
	{
		const Vector3<int> v1(1, 2, 3);
		const Vector3<int> v2(4, 5, 6);
		const int expected = 32; // 1*4 + 2*5 + 3*6
		const int result = v1.dotProduct(v2);
		EXPECT_EQ(result, expected);
	}

	TEST(Vector3Test, IntCrossProduct)
	{
		const Vector3<int> v1(1, 0, 0);
		const Vector3<int> v2(0, 1, 0);
		const Vector3<int> expected(0, 0, 1);
		const Vector3<int> result = v1.crossProduct(v2);
		EXPECT_EQ(result, expected);
	}

	TEST(Vector3Test, IntMagnitude)
	{
		const Vector3<int> v(3, 4, 0);
		const int expected = 5; // sqrt(3^2 + 4^2 + 0^2) = 5
		const int result = v.magnitude();
		EXPECT_EQ(result, expected);
	}

	TEST(Vector3Test, IntNormalize)
	{
		const Vector3<int> v(3, 0, 0);
		const Vector3<int> expected(1, 0, 0); // Normalized vector
		const Vector3<int> result = v.normalize();
		EXPECT_EQ(result, expected);
	}


	// Test Vector3 float operations

	TEST(Vector3Test, FloatAddition)
	{
		const Vector3<float> v1(1.0f, 2.0f, 3.0f);
		const Vector3<float> v2(4.0f, 5.0f, 6.0f);
		const Vector3<float> expected(5.0f, 7.0f, 9.0f);
		const Vector3<float> result = v1 + v2;
		EXPECT_EQ(result, expected);
	}

	TEST(Vector3Test, FloatSubtraction)
	{
		const Vector3<float> v1(4.0f, 5.0f, 6.0f);
		const Vector3<float> v2(1.0f, 2.0f, 3.0f);
		const Vector3<float> expected(3.0f, 3.0f, 3.0f);
		const Vector3<float> result = v1 - v2;
		EXPECT_EQ(result, expected);
	}

	TEST(Vector3Test, FloatMultiplication)
	{
		const Vector3<float> v(1.0f, 2.0f, 3.0f);
		const float scalar = 2.0f;
		const Vector3<float> expected(2.0f, 4.0f, 6.0f);
		const Vector3<float> result = v * scalar;
		EXPECT_EQ(result, expected);
	}

	TEST(Vector3Test, FloatDivision)
	{
		const Vector3<float> v(4.0f, 6.0f, 8.0f);
		const float scalar = 2.0f;
		const Vector3<float> expected(2.0f, 3.0f, 4.0f);
		const Vector3<float> result = v / scalar;
		EXPECT_EQ(result, expected);
	}

	TEST(Vector3Test, FloatDotProduct)
	{
		const Vector3<float> v1(1.0f, 2.0f, 3.0f);
		const Vector3<float> v2(4.0f, 5.0f, 6.0f);
		const float expected = 32.0f; // 1*4 + 2*5 + 3*6
		const float result = v1.dotProduct(v2);
		EXPECT_EQ(result, expected);
	}

	TEST(Vector3Test, FloatCrossProduct)
	{
		Vector3<float> v1(1.0f, 0.0f, 0.0f);
		Vector3<float> v2(0.0f, 1.0f, 0.0f);
		Vector3<float> expected(0.0f, 0.0f, 1.0f);
		Vector3<float> result = v1.crossProduct(v2);
		EXPECT_EQ(result, expected);
	}

	TEST(Vector3Test, FloatMagnitude)
	{
		const Vector3<float> v(3.0f, 4.0f, 0.0f);
		const float expected = 5.0f; // sqrt(3^2 + 4^2 + 0^2) = 5
		const float result = v.magnitude();
		EXPECT_FLOAT_EQ(result, expected);
	}

	TEST(Vector3Test, FloatNormalize)
	{
		const Vector3<float> v(3.0f, 0.0f, 0.0f);
		const Vector3<float> expected(1.0f, 0.0f, 0.0f); // Normalized vector
		const Vector3<float> result = v.normalize();
		EXPECT_EQ(result, expected);
	}


	// Test Vector3 double operations

	TEST(Vector3Test, DoubleAddition)
	{
		const Vector3<double> v1(1.0, 2.0, 3.0);
		const Vector3<double> v2(4.0, 5.0, 6.0);
		const Vector3<double> expected(5.0, 7.0, 9.0);
		const Vector3<double> result = v1 + v2;
		EXPECT_EQ(result, expected);
	}

	TEST(Vector3Test, DoubleSubtraction)
	{
		const Vector3<double> v1(4.0, 5.0, 6.0);
		const Vector3<double> v2(1.0, 2.0, 3.0);
		const Vector3<double> expected(3.0, 3.0, 3.0);
		const Vector3<double> result = v1 - v2;
		EXPECT_EQ(result, expected);
	}

	TEST(Vector3Test, DoubleMultiplication)
	{
		const Vector3<double> v(1.0, 2.0, 3.0);
		const double scalar = 2.0;
		const Vector3<double> expected(2.0, 4.0, 6.0);
		const Vector3<double> result = v * scalar;
		EXPECT_EQ(result, expected);
	}

	TEST(Vector3Test, DoubleDivision)
	{
		const Vector3<double> v(4.0, 6.0, 8.0);
		const double scalar = 2.0;
		const Vector3<double> expected(2.0, 3.0, 4.0);
		const Vector3<double> result = v / scalar;
		EXPECT_EQ(result, expected);
	}

	TEST(Vector3Test, DoubleDotProduct)
	{
		const Vector3<double> v1(1.0, 2.0, 3.0);
		const Vector3<double> v2(4.0, 5.0, 6.0);
		const double expected = 32.0; // 1*4 + 2*5 + 3*6
		const double result = v1.dotProduct(v2);
		EXPECT_EQ(result, expected);
	}

	TEST(Vector3Test, DoubleCrossProduct)
	{
		Vector3<double> v1(1.0, 0.0, 0.0);
		Vector3<double> v2(0.0, 1.0, 0.0);
		Vector3<double> expected(0.0, 0.0, 1.0);
		Vector3<double> result = v1.crossProduct(v2);
		EXPECT_EQ(result, expected);
	}

	TEST(Vector3Test, DoubleMagnitude)
	{
		const Vector3<double> v(3.0, 4.0, 0.0);
		const double expected = 5.0; // sqrt(3^2 + 4^2 + 0^2) = 5
		const double result = v.magnitude();
		EXPECT_DOUBLE_EQ(result, expected);
	}

	TEST(Vector3Test, DoubleNormalize)
	{
		const Vector3<double> v(3.0, 0.0, 0.0);
		const Vector3<double> expected(1.0, 0.0, 0.0); // Normalized vector
		const Vector3<double> result = v.normalize();
		EXPECT_EQ(result, expected);
	}
}