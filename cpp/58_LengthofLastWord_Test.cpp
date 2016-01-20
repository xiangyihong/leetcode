#include "gtest/gtest.h"
#include <vector>
#include <string>

#include "58_LengthofLastWord.cpp"

struct ParamsAndExpectedResult
{
	std::string s;
	int result;
};

TEST(LengthofLastWord, NormalTest)
{
	std::vector<ParamsAndExpectedResult> test_cases =
	{
		{"", 0},
		{"abcd", 4},
		{" abcd", 4},
		{"    ", 0},
		{"        abcd            abcdefg      ", 7},
	};

	for (int i = 0; i < test_cases.size(); ++i)
	{
		int actual = Solution().lengthOfLastWord(test_cases[i].s);
		EXPECT_EQ(actual, test_cases[i].result)
			<< "Index: " << i;
	}
}