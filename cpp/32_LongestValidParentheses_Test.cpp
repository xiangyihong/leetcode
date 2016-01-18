#include "gtest/gtest.h"
#include <vector>
#include <string>

#include "32_LongestValidParentheses.cpp"

struct ParamsAndExpectedResult
{
	std::string s;
	int result;
};



TEST(LongestValidParentheses, NormalTest)
{
	std::vector<ParamsAndExpectedResult> test_cases = 
	{
		{"", 0},
		{"(", 0},
		{")()()", 4},
		{")(", 0},
		{")())()", 2},
		{"()(()", 2},
	};

	for (int i = 0; i < test_cases.size(); ++i)
	{
		int actual = Solution().longestValidParentheses(test_cases[i].s);
		EXPECT_EQ(actual, test_cases[i].result);
	}
}