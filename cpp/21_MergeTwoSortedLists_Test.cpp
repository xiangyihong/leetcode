#include "gtest/gtest.h"

#include "21_MergeTwoSortedLists.cpp"

#include <vector>
#include <memory>
#include <iostream>

using namespace testing;


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

struct PramsAndExpectedResult
{
	std::vector<int> l1;
	std::vector<int> l2;
	std::vector<int> result;
};

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

TEST(MergeTwoSortedLists, NormalTest)
{
	std::vector<PramsAndExpectedResult> test_cases =
	{
		{{}, {}, {}},
		{{1}, {2}, {1,2}},
		{{1}, {}, {1}},
		{{}, {1}, {1}},
		{{1,2,3},{2,3}, {1,2,2,3,3}},
		{{1,3,5,7,9}, {2,4,6,8,10}, {1,2,3,4,5,6,7,8,9,10} },

	};

	for (int i = 0; i < test_cases.size(); ++i)
	{
		//auto l1 = std::make_shared<ListNode>(ConstructListNode(test_cases[i].l1));
		//auto l2 = std::make_shared<ListNode>(ConstructListNode(test_cases[i].l2));
		//auto result = std::make_shared<ListNode>(ConstructListNode(test_cases[i].result));

		//std::shared_ptr<ListNode> actual(Solution().mergeTwoLists(l1.get(), l2.get()));
		//EXPECT_TRUE(EqualList(result.get(), actual.get()))
		ListNode* l1 = ConstructListNode(test_cases[i].l1);
		ListNode* l2 = ConstructListNode(test_cases[i].l2);
		ListNode* result = ConstructListNode(test_cases[i].result);

		ListNode* actual = Solution().mergeTwoLists(l1, l2);
		EXPECT_TRUE(EqualList(result, actual))
			<< "Input: l1:" << test_cases[i].l1 << " l2:" << test_cases[i].l2;
	}

}