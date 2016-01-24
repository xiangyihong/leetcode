#include "gtest/gtest.h"
#include <vector>
#include <string>

#include "137_SingleNumberII.cpp"

struct ParamsAndExpectedResult
{
	std::vector<int> nums;
	int result;
};

TEST(SingleNumberII, NormalTest)
{
	std::vector<ParamsAndExpectedResult> test_cases =
	{
		{{1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,8,8,8}, 7},
	};

	for (int i = 0; i < test_cases.size(); ++i)
	{
		int actual = Solution().singleNumber(test_cases[i].nums);
		EXPECT_EQ(test_cases[i].result, actual);
	}
}