/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
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
	ListNode* swapPairs(ListNode* head) 
	{
		if (head == NULL || head->next == NULL)
			return head;
		ListNode* cur = head;
		ListNode* pre = cur;

		cur = cur->next;
		pre->next = NULL;
		ListNode* next = cur->next;
		
		while (next != NULL)
		{
			cur->next = pre;
			pre = cur;
			cur = next;
			next = next->next;
		}
		
		cur->next = pre;
		return cur;

	}
};