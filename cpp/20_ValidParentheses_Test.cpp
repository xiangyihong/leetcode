#include "gtest/gtest.h"
#include <vector>
#include <string>

#include "20_ValidParentheses.cpp"

struct ParamsAndExpectedResult
{
	std::string s;
	bool result;
};

TEST(ValidParentheses, NormalTest)
{
	std::vector<ParamsAndExpectedResult> test_cases =
	{
		{"", true},
		{"(", false},
		{")", false},
		{")(", false},
		{"((()())", false},
		{"((()()))", true},
		{"{([[[]]])}{}", true},
		{"{{{[[[(((]]]", false},
	};

	for (int i = 0; i < test_cases.size(); ++i)
	{
		bool actual = Solution().isValid(test_cases[i].s);
		EXPECT_EQ(test_cases[i].result, actual);
	}
}