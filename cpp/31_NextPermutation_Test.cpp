#include "gtest/gtest.h"
#include <vector>
#include <string>

#include "31_NextPermutation.cpp"

struct ParamsAndExpectedResult
{
	std::vector<int> input;
	std::vector<int> result;
};


template<typename T>
bool EqualVector(const std::vector<T>& a, const std::vector<T>& b)
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

TEST(NextPermutation, NormalTest)
{
	std::vector<ParamsAndExpectedResult> test_cases =
	{
		{{1,2,3}, {1,3,2}},
		{{3,2,1}, {1,2,3}},
		{{1,3,2}, {2,1,3}},
		{{3,1,2}, {3,2,1}},
		{{2,4,6,-10,8}, { 2,4,6,8,-10 }},
	};

	for (int i = 0; i < test_cases.size(); ++i)
	{
		Solution().nextPermutation(test_cases[i].input);
		EXPECT_TRUE(EqualVector(test_cases[i].input, test_cases[i].result))
			<< "Input: " << i;
	}
}