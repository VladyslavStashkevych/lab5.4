#include "pch.h"
#include "CppUnitTest.h"
#include "../lab5.4/lab5.4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1 {
	TEST_CLASS(UnitTest1) {
public:

		TEST_METHOD(TestMethod1) {
			double sum = SumIter(-1, 1);
			Assert::AreEqual(0., sum);

			sum = SumRecUpP(1, -1);
			Assert::AreEqual(0., sum);

			sum = SumRecUpM(-1, 1);
			Assert::AreEqual(0., sum);

			sum = SumRecDownP(1, -1, 0);
			Assert::AreEqual(0., sum);

			sum = SumRecDownM(-1, 1, 0);
			Assert::AreEqual(0., sum);
		}
	};
}
