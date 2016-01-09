#include "gtest/gtest.h"

#include "10_RegularExpressionMatching.cpp"

#include <string>
#include <vector>

struct ParamsAndExpectedResult
{
	std::string s;
	std::string regex;
	bool result;
};

TEST(RegularExpressionMatching, NormalTest)
{
	std::vector<ParamsAndExpectedResult> test_cases = 
	{
		{"aa", "a", false},
		{"aa", "aa", true},
		{"aaa", "aa", false},
		{"aa", "a*", true},
		{"aa", ".*", true},
		{"ab",".*", true},
		{"aab", "c*a*b", true},
		{"ab", "*", false},
		{"", "", true},
		{"aaba", "ab*a*c*a" , false},
		{"", ".", false},
		{"", ".*", true},
	};

	for (int i = 0; i < test_cases.size(); ++i)
	{
		ASSERT_EQ(test_cases[i].result, Solution().isMatch(test_cases[i].s, test_cases[i].regex));
	}
}