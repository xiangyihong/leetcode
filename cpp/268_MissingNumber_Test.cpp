#include "gtest/gtest.h"
#include <vector>
#include <string>

#include "268_MissingNumber.cpp"


struct ParamsAndExpectedResult
{
	std::vector<int> nums;
	int result;
};

TEST(MissingNumber, NormalTest)
{
	std::vector<ParamsAndExpectedResult> test_cases =
	{
		{{0}, 1},
		{{0,1,3}, 2},
	};

	for (int i = 0; i < test_cases.size(); ++i)
	{
		int actual = Solution().missingNumber(test_cases[i].nums);
		EXPECT_EQ(actual, test_cases[i].result)
			<< "Index: " << i;
	}
}