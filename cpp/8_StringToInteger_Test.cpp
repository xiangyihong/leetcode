#include "gtest\gtest.h"
#include "8_StringToInteger.cpp"

#include <string>

using namespace testing;

template<typename ParamType, typename ResultType>
struct ParamAndExpectedResult
{
	ParamType param;
	ResultType result;
};

TEST(SringToIntegerTest, NormalTest)
{

	std::vector<ParamAndExpectedResult<std::string, int> > test_cases = 
	{
		{"-12345", -12345},
		{"12345", 12345},
		{"", 0},
		{"-0", 0},
		{"0", 0},
		{"-2147483648", INT_MIN},
		{"-2147483649", INT_MIN},
		{"2147483647", 2147483647},
		{"2147483648", 2147483647},
		{"+-0", 0},
		{"+123abc ", 123}

	};
	for (int i = 0; i < test_cases.size(); ++i)
	{
		EXPECT_EQ(test_cases[i].result, Solution().myAtoi(test_cases[i].param));
	}
	
}