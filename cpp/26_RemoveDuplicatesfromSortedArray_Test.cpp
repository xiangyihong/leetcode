#include "gtest/gtest.h"
#include <vector>

#define TEST_EQUAL
#include "26_RemoveDuplicatesfromSortedArray.cpp"



struct ParamsAndExpectedResult
{
	std::vector<int> input;
	std::vector<int> expected_output;
	int result;
};

template<typename T>
bool EqualSortedVector(const std::vector<T>& a, const std::vector<T>& b)
{
	if (a.size() != b.size())
		return false;
	for (int i = 0; i < a.size(); ++i)
	{
		if (a[i] != b[i])
			return false;
	}
	return true;
}
TEST(RemoveDuplicatesfromSortedArray, NormalTest)
{
	std::vector<ParamsAndExpectedResult> test_cases =
	{
		{{1,1,2,3}, {1,2,3}, 3},
		{{}, {}, 0},
		{{1}, {1}, 1},
		{{1,2,2,3,4,5,5,5,5,5}, {1,2,3,4,5}, 5},

	};

	for (int i = 0; i < test_cases.size(); ++i)
	{
		int actual_result = Solution().removeDuplicates(test_cases[i].input);

		EXPECT_EQ(actual_result, test_cases[i].result);
		EXPECT_TRUE(EqualSortedVector(test_cases[i].input, test_cases[i].expected_output));
	}
}