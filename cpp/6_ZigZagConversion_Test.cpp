#include "gtest/gtest.h"

#include "6_ZigZagConversion.cpp"

#include <vector>

using namespace testing;

struct ParamsAndExpectedResult
{
	std::string input;
	int row;
	std::string result;
};

TEST(ZigZagConversion, NormalTest)
{
	std::vector<ParamsAndExpectedResult> test_cases =
	{
		{"PAYPALISHIRING", 3, "PAHNAPLSIIGYIR"},
		{"", 10, ""},
		{"abcd", 100, "abcd"},
		{"abcdefghijklmnopqrst", 5, "aiqbhjprcgkosdflntem"},
		{"abcdefghijklmnopqrst", 7, "amblnckodjpeiqfhrtgs"},
		{"abcdefghijklmnopqrst", 4, "agmsbfhlnrtceikoqdjp"},
		{"abcdefghijklmnopqrst", 6, "akbjltcimsdhnregoqfp"},
		{"A", 1, "A"}


	};

	for (int i = 0; i < test_cases.size(); ++i)
	{
		EXPECT_EQ(test_cases[i].result, Solution().convert(test_cases[i].input, test_cases[i].row));
	}
}