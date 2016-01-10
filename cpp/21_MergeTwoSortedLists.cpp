#include <iostream>

struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:


	// returns the first element of the list
	// the first element of the list is elimenated from the list
	ListNode* ShiftNode(ListNode** l1)
	{
		if (l1 == NULL || (*l1 == NULL))
			return NULL;
		ListNode* tmp = (*l1);
		*l1 = (*l1)->next;
		tmp->next = NULL;
		return tmp;
	}

	ListNode* AppendNode(ListNode* l1, ListNode* l2)
	{
		if (l1 == NULL)
			return l2;
		while (l1->next != NULL)
		{
			l1 = l1->next;
		}
		l1->next = l2;
		while (l2->next != NULL)
		{
			l2 = l2->next;
		}
		return l2;
	}
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
	{
		ListNode* result = NULL;
		ListNode* pre = NULL;
		while (l1 != NULL && l2 != NULL)
		{
			if (l1->val < l2->val)
			{
				ListNode* first_node = ShiftNode(&l1);
				pre = AppendNode(pre, first_node);
				if (result == NULL)
					result = pre;
			}
			else if (l2->val < l1->val)
			{
				ListNode* first_node = ShiftNode(&l2);
				pre = AppendNode(pre, first_node);
				if (result == NULL)
					result = pre;
			}
			else
			{
				ListNode* first_node = ShiftNode(&l1);
				pre = AppendNode(pre, first_node);
				if (result == NULL)
					result = pre;

				first_node = ShiftNode(&l2);
				pre = AppendNode(pre, first_node);
			}
		}
		ListNode* remain_list = l1 != NULL ? l1 : l2;
		while (remain_list)
		{
			ListNode* first_node = ShiftNode(&remain_list);
			pre = AppendNode(pre, first_node);
			if (result == NULL)
				result = pre;
		}

		return result;
	}
};