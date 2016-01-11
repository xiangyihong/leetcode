#include "gtest/gtest.h"

#include "24_SwapNodesinPairs.cpp"

#include <vector>

struct ParamsAndExpectedResult
{
	std::vector<int> input;
	std::vector<int> result;
};


ListNode* ConstructListNode(const std::vector<int>& numbers)
{
	if (numbers.size() == 0)
		return NULL;
	ListNode* lStart = new ListNode(numbers[0]);
	ListNode* lPre = lStart;
	for (int i = 1; i < numbers.size(); ++i)
	{
		ListNode* lTmp = new ListNode(numbers[i]);
		lPre->next = lTmp;
		lPre = lPre->next;
	}
	return lStart;
}


bool EqualList(ListNode* l1, ListNode* l2)
{
	while (l1 != NULL && l2 != NULL)
	{
		if (l1->val == l2->val)
		{
			l1 = l1->next;
			l2 = l2->next;
		}
		else
		{
			return false;
		}
	}
	if (l1 == NULL && l2 == NULL)
		return true;
	return false;
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

TEST(SwapNodesinPairs, NormalTest)
{
	std::vector<ParamsAndExpectedResult> test_cases = 
	{
		{{},{}},
		{{1}, {1}},
		{{1,2}, {2,1}},
		{{1,2,3,4,5}, {2,1,4,3,5}},
	};

	for (int i = 0; i < test_cases.size(); ++i)
	{
		ListNode* l1 = ConstructListNode(test_cases[i].input);
		ListNode* expect = ConstructListNode(test_cases[i].result);
		ListNode* actual = Solution().swapPairs(l1);

		EXPECT_TRUE(EqualList(expect, actual))
			<< "Input: " << test_cases[i].input;

	}
}
