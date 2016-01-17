#include "gtest/gtest.h"

#include <vector>
#include <string>

#include "28_ImplementstrStr.cpp"

struct ParamsAndExpectedResult
{
	std::string s;
	std::string sub;
	int index;
};

TEST(ImplementstrStr, NormalTest)
{
	std::vector<ParamsAndExpectedResult> test_cases = 
	{
		{"", "", 0},
		{"a", "", 0},
		{"", "a", -1},
		{"abcd", "b", 1},
		{"abcd","e", -1},
	};

	for (int i = 0; i < test_cases.size(); ++i)
	{
		EXPECT_EQ(Solution().strStr(test_cases[i].s, test_cases[i].sub), test_cases[i].index);
	}
}