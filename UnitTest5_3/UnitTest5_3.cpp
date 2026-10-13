#include "pch.h"
#include "CppUnitTest.h"
#include <cmath>

#include "../PR5_3/pr5_3.cpp"   // підключаємо файл із функцією s()
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest53
{
    TEST_CLASS(UnitTest53)
    {
    public:

        // x == 0 -> (cos^2(0) + 1) / e^0 = 2
        TEST_METHOD(TestZero)
        {
            Assert::AreEqual(2.0, s(0), 1e-9);
        }

        // |x| >= 1 -> (cos^2 x + 1) / e^x
        TEST_METHOD(TestAbsGreaterOrEqualOne)
        {
            double x = 1.0;
            double expected = (cos(x) * cos(x) + 1) / exp(x);
            Assert::AreEqual(expected, s(x), 1e-9);

            x = 2.0;
            expected = (cos(x) * cos(x) + 1) / exp(x);
            Assert::AreEqual(expected, s(x), 1e-9);
        }

        // від'ємне значення |x| >= 1
        TEST_METHOD(TestNegativeLarge)
        {
            double x = -2.0;
            double expected = (cos(x) * cos(x) + 1) / exp(x);
            Assert::AreEqual(expected, s(x), 1e-9);
        }

        // 0 < |x| < 1 -> ряд для sinh(2x) / sin(2x)
        TEST_METHOD(TestSmallPositive)
        {
            double x = 0.5;
            double expected = sinh(2 * x) / sin(2 * x);
            Assert::AreEqual(expected, s(x), 1e-5);
        }
    };
}