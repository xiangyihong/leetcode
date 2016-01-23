#include "gtest/gtest.h"
#include <vector>
#include <string>

#include "78_Subsets.cpp"

struct ParamsAndExpectedResult
{
	std::vector<int> nums;
	std::vector<std::vector<int>> result;
};

template<typename T>
bool operator==(std::vector<T>& a, std::vector<T>& b)
{
	if (a.size() != b.size())
		return false;

	for (int i = 0; i < a.size(); ++i)
	{
		if (!(a[i] == b[i]))
			return false;
	}
	return true;
}

TEST(Subset, NormalTest)
{
	std::vector<ParamsAndExpectedResult> test_cases =
	{
		{{}, {{}}},
		{{1}, {{}, {1} }},
		{{1,2}, {{}, {2}, {1}, {1,2}}},
		{{1,1}, {{}, {1}, {1,1}}},
		{{1,1,1}, {{}, {1}, {1,1}, {1,1,1}}},
	};

	for (int i = 0; i < test_cases.size(); ++i)
	{
		auto actual = Solution().subsets(test_cases[i].nums);
		EXPECT_TRUE(test_cases[i].result == actual)
			<< "Index: " << i;
	}
}