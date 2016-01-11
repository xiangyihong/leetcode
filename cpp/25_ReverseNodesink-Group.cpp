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

	// returns the new head of given group
	// reverse k elements
	// if elements are less than k
	// reverse them anyway
	ListNode* ReverseLinkGroup(ListNode* head, int k)
	{
		if (head == NULL || head->next == NULL || k == 1)
			return head;

		ListNode* last_one = head;
		ListNode* pre = NULL;
		ListNode* cur = head;

		pre = cur;
		cur = cur->next;
		ListNode* next = cur->next;
		int index = 2;
		while (next != NULL && index < k)
		{

			cur->next = pre;
			pre = cur;
			cur = next;
			next = next->next;
			++index;
		}
		cur->next = pre;
		last_one->next = next;
		return cur;
	}

	ListNode* reverseKGroup(ListNode* head, int k)
	{
		if (head == NULL || head->next == NULL || k == 1)
			return head;

		ListNode* new_head = NULL;
		ListNode* cur = head;
		ListNode* group_end = NULL;
		ListNode* pre_group_end = NULL;

		ListNode* first_element_of_group = head;
		// steps:
		// 1. find whether there are enough elements for a full group
		// 2. if do, reverse this group
		// 3. last group element's next point to the new group's head
		while (first_element_of_group != NULL)
		{
			// iterate to next group
			int index = 1;
			ListNode* cur_group_head = first_element_of_group;
			ListNode* cur = first_element_of_group;
			while (cur != NULL && index < k)
			{
				cur = cur->next;
				++index;
			}
			if (cur == NULL)
			{
				first_element_of_group = NULL;
			}
			else // (index == k)
			{
				ListNode* new_group_head = ReverseLinkGroup(cur_group_head, k);
				if (new_head == NULL)
				{
					new_head = new_group_head;
				}
				// cur_group_head becomes the last element of the group after the reverse
				group_end = cur_group_head;

				if (pre_group_end == NULL)
				{
					pre_group_end = group_end;
				}
				else
				{
					pre_group_end->next = new_group_head;
					pre_group_end = group_end;
				}
				first_element_of_group = group_end->next;
			}



		}

		// no reverse is done
		if (new_head == NULL)
		{
			new_head = head;
		}
		return new_head;
	}
};