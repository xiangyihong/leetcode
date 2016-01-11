/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
#include <vector>
#include <algorithm>
#include <utility>

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
	ListNode* swapPairs(ListNode* head) 
	{
		if (head == NULL || head->next == NULL)
			return head;

		int cur_index = 1;
		ListNode* cur = head;
		ListNode* pre = cur;

		cur = cur->next;
		++cur_index;
		while (cur != NULL)
		{
			if ((cur_index & 1) == 0) // even index
			{
				std::swap(pre->val, cur->val);
			}
			pre = cur;
			cur = cur->next;
			++cur_index;
		}
		return head;
	}
};