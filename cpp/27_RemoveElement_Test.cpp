#include "gtest/gtest.h"
#include <vector>
#include <algorithm>

#include "27_RemoveElement.cpp"

struct PramsAndExpectedResult
{
	std::vector<int> input;
	int num;
	std::vector<int> result;
	int result_length;
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


template<typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vec)
{
	out << "[";
	for (int i = 0; i < vec.size(); ++i)
	{
		if (i != 0)
		{
			out << " ";
		}
		out << vec[i];
		if (i != vec.size() - 1)
		{
			out << ",";
		}
	}
	out << "]";
	return out;
}


TEST(RemoveElement, NormalTest)
{
	std::vector<PramsAndExpectedResult> test_cases = 
	{
		{{}, 10, {}, 0},
		{{1}, 10, {1}, 1},
		{{10}, 10, {}, 0},
		{{1,10,2,9,10,33,10,99,10,10,10}, 10, {1,2,9,33,99}, 5},
	};

	for (int i = 0; i < test_cases.size(); ++i)
	{
		int actual_length = Solution().removeElement(test_cases[i].input, test_cases[i].num);

		EXPECT_EQ(actual_length, test_cases[i].result_length);
		EXPECT_TRUE(EqualVector(test_cases[i].result, test_cases[i].input)) 
			<< "Input: " << test_cases[i].input << " Num: " << test_cases[i].num;
	}
}