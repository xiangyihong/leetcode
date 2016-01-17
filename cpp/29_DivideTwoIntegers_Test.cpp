#include "gtest/gtest.h"
#include <vector>

#include "29_DivideTwoIntegers.cpp"

struct ParamsAndExpectedResult
{
	int divided;
	int divisor;
	int result;
};

TEST(DivideTwoIntegers, NormalTest)
{
	std::vector<ParamsAndExpectedResult> test_cases = 
	{
		{1, 0, MAX_INT},
		{1, 1, 1},
		{MAX_INT, 1, MAX_INT},
		{100, 9, 11},
		{100, 101, 0},
		{100, -1, -100},
		{-100, 1, -100},
		{-100, -1, 100},
		{INT_MIN, 1, INT_MIN},
		{INT_MIN, -1, MAX_INT},
		{ INT_MIN, -2, 1073741824},
	};

	for (int i = 0; i < test_cases.size(); ++i)
	{
		EXPECT_EQ(Solution().divide(test_cases[i].divided, test_cases[i].divisor), test_cases[i].result)
			<< "Index: " << i;
	}
}