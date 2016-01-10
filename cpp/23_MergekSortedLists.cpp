#include <iostream>
#include <vector>
#include <algorithm>

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};


class Solution {
public:


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

	ListNode* mergeKLists(std::vector<ListNode*>& lists)
	{
		std::vector<int> result_vector;
		for (int i = 0; i < lists.size(); ++i)
		{
			ListNode* head = lists[i];
			while (head != NULL)
			{
				result_vector.push_back(head->val);
				head = head->next;
			}
		}

		std::sort(result_vector.begin(), result_vector.end());
		return ConstructListNode(result_vector);
	}

};