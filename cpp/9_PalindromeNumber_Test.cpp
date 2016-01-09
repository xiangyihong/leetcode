#include "gtest/gtest.h"

#include "9_PalindromeNumber.cpp"


struct ParamAndExpectedResult
{
	int num;
	bool result;
};

TEST(PalindromeNumber, NormalTest)
{
	std::vector<ParamAndExpectedResult> test_cases =
	{
		{0, true},
		{1, true},
		{-1, false},
		{100, false},
		{11, true},
		{99899, true},
	};

	for (int i = 0; i < test_cases.size(); ++i)
	{
		EXPECT_EQ(test_cases[i].result, Solution().isPalindrome(test_cases[i].num));
	}
}