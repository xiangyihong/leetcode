#include "gtest/gtest.h"
#include <vector>
#include <string>

#include "33_SearchinRotatedSortedArray.cpp"

struct ParamsAndExpectedResult
{
	std::vector<int> nums;
	int target;
	int result;
};

TEST(SearchinRotatedSortedArray, NormalTest)
{
	std::vector<ParamsAndExpectedResult> test_cases =
	{
		{{}, 3, -1},
		{{1,2,3}, 3, 2},
		{{1,2,3}, 2, 1},
		{{1,2,3}, 4, -1},
		{{4,5,6,0,1,2,3}, 3, 6},
		{{4,5,6,0,1,2,3}, 5, 1},
		{{4,5,6,0,1,2,3}, 10, -1},
	};

	for (int i = 0; i < test_cases.size(); ++i)
	{
		int actual = Solution().search(test_cases[i].nums, test_cases[i].target);
		EXPECT_EQ(actual, test_cases[i].result)
			<< "Index: " << i;
	}
}