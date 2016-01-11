#include "gtest/gtest.h"
#include <vector>

#include "25_ReverseNodesink-Group.cpp"

struct ParamsAndExpectedResult
{
	std::vector<int> nums;
	int k;
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

TEST(ReverseNodesinkGroup, NormalTest)
{
	std::vector<ParamsAndExpectedResult> test_cases = 
	{
		{{}, 1, {}},
		{{1,2},1,{1,2}},
		{{}, 100, {}},
		{{1}, 100, {1}},
		{{1,2,3}, 100, {1,2,3}},
		{{1,2,3,4,5,6}, 3, {3,2,1,6,5,4}},
		{{1,2,3,4,5,6,7,8,9,10,11}, 3, {3,2,1,6,5,4,9,8,7,10,11}},
	};

	for (int i = 0; i < test_cases.size(); ++i)
	{
		ListNode* nums = ConstructListNode(test_cases[i].nums);
		ListNode* actual = Solution().reverseKGroup(nums, test_cases[i].k);

		ListNode* expected = ConstructListNode(test_cases[i].result);

		EXPECT_TRUE(EqualList(expected, actual))
			<< "Input: " << test_cases[i].nums << "\tk: " << test_cases[i].k;
	}
}