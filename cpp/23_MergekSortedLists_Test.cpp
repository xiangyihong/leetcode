#include "gtest/gtest.h"

#include "23_MergekSortedLists.cpp"
#include <vector>

struct ParamsAndExpectedResult
{
	std::vector<std::vector<int>> mlist;
	std::vector<int> mresult;
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

void PrintList(ListNode* l1)
{
	while (l1 != NULL)
	{
		std::cout << l1->val << "\t";
		l1 = l1->next;
	}
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

struct DeleteList
{
	void operator()(ListNode* l1)
	{
		while (l1)
		{
			ListNode* next = l1->next;
			delete l1;
			l1 = next;
		}
	}
};

TEST(MergekSortedLists, NormalTest)
{
	std::vector<ParamsAndExpectedResult> test_cases = 
	{
		//{{{1}, {}, {2}}, {1,2}},
		//{{{}, {}, {}}, {} },
		//{{{1},{2,3}, {1,4}}, {1,1,2,3,4}},
		{ { { -10,-9,-9,-3,-1,-1,0 },{ -5 },{ 4 },{ -8 },{},{ -9,-6,-5,-4,-2,2,3 },{ -3,-3,-2,-1,0 } } , {}},
	};

	for (int i = 0; i < test_cases.size(); ++i)
	{
		std::vector<ListNode*> lists;
		for (int j = 0; j < test_cases[i].mlist.size(); ++j)
		{
			ListNode* tmp = ConstructListNode(test_cases[i].mlist[j]);
			lists.push_back(tmp);
		}

		ListNode* result = ConstructListNode(test_cases[i].mresult);
		ListNode* actual = Solution().mergeKLists(lists);
		EXPECT_TRUE(EqualList(result, actual));
	}
}

