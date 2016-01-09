#include "gtest/gtest.h"

#include <vector>
#include <string>

#include "12_IntegertoRoman.cpp"

using namespace testing;

struct ParamsAndExpectedResult
{
	int num;
	std::string result;
};

TEST(IntegertoRoman, NormalTest)
{
	std::vector<ParamsAndExpectedResult> test_cases =
	{
		{1, "I"},
		{4, "IV"},
		{5, "V"},
		{9, "IX"},
		{10, "X"},
		{11, "XI"},
		{15, "XV"},
		{50, "L"},
		{100, "C"},
		{500, "D"},
		{1000, "M"},
		{22, "XXII"},
		{1954, "MCMLIV"},
		{1990, "MCMXC"},
		{2014, "MMXIV"},
		{900, "CM"},
		{1904, "MCMIV"},

	};

	for (int i = 0; i < test_cases.size(); ++i)
	{
		EXPECT_EQ(test_cases[i].result, Solution().intToRoman(test_cases[i].num))
			<< "Input: " << test_cases[i].num;
	}
}