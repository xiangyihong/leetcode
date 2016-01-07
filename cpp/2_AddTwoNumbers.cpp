/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

#include <iostream>
#include <memory>
#include <vector>

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x),
		next(NULL)
	{

	}
};

class Solution {
public:

	ListNode* Add(ListNode* l1, ListNode* l2)
	{
		ListNode* lResult = new ListNode(0);

		if (l1 != NULL && l2 != NULL)
		{
			lResult->val = l1->val + l2->val;
		}
		else if (l1 != NULL)
		{
			lResult->val = l1->val;
		}
		else if (l2 != NULL)
		{
			lResult->val = l2->val;
		}
		return lResult;
	}

	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
	{

		ListNode* lResult = NULL;
		ListNode* lLast = NULL;
		while (l1 != NULL || l2 != NULL)
		{
			ListNode* lTmp = Add(l1, l2);
			if (l1 != NULL)
				l1 = l1->next;
			if (l2 != NULL)
				l2 = l2->next;

			if (lLast == NULL)
			{
				lLast = lTmp;
				lResult = lLast;
			}
			else
			{
				lLast->next = lTmp;
				lLast = lLast->next;
			}
		}

		ListNode* lTmp = lResult;
		int cr = 0;
		while (lTmp != NULL)
		{
			lTmp->val += cr;
			cr = 0;
			while (lTmp->val >= 10)
			{
				cr++;
				lTmp->val -= 10;
			}
			lTmp = lTmp->next;
		}
		if (cr > 0)
		{
			std::shared_ptr<ListNode> lTmpConstructed = std::make_shared < ListNode>(cr);
			lLast->next = Add(lTmpConstructed.get(), NULL);
		}
		return lResult;
	}
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
int main()
{
	int a[] = { 2, 4, 8, 9,8 };
	int b[] = {5, 6, 4};

	std::vector<int> v1(&a[0], &a[0] + sizeof(a) / sizeof(int));
	std::vector<int> v2(&b[0], &b[0] + sizeof(b) / sizeof(int));

	ListNode* l1 = ConstructListNode(v1);
	ListNode* l2 = ConstructListNode(v2);

	ListNode* lResult = Solution().addTwoNumbers(l1, l2);
	PrintList(lResult);
	system("pause");
	return 0;
	

}