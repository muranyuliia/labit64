#include "pch.h"
#include "CppUnitTest.h"
#include "../labit64/labit64.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
        TEST_METHOD(TestCountElementsLessThanC)
        {
            double testArray[5] = { 1.0, 2.0, 3.0, 4.0, 5.0 };
            double C = 3.0;

            int result = countElementsLessThanC(testArray, 5, C);

            Assert::AreEqual(2, result); // Перевірка результату.
        }

        // Додайте інші тести для інших функцій.
    

	};
}
