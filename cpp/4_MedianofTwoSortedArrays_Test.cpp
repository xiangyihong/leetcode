#include "gtest\gtest.h"

#include "4_MedianofTwoSortedArrays.cpp"

#include <vector>

template<typename Param, typename Result>
struct ParamsAndExpectedResult
{
	Param p1;
	Param p2;
	double result;
};
TEST(MedianofTwoSortedArrays, NormalTest)
{
	std::vector<ParamsAndExpectedResult<std::vector<int>, double> > test_cases = 
	{
		{{1,2,3,4,5}, {6,7,8,9}, 5},
		{{}, {1}, 1},
		{{}, {}, 0},
		{{1}, {2}, 1.5}
	};

	for (int i = 0; i < test_cases.size(); ++i)
	{
		EXPECT_EQ(test_cases[i].result, Solution().findMedianSortedArrays(test_cases[i].p1, test_cases[i].p2));
	}


}