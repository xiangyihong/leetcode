# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        cv = 0
        first = l1
        second = l2
        head = first
        pre = None
        while first and second:
            sum = first.val + second.val + cv
            if sum >= 10:
                sum -= 10
                cv = 1
            else:
                cv = 0
            first.val = sum
            pre = first
            first = first.next
            second = second.next
        remain = None
        if first:
            remain = first
        elif second:
            remain = second
        while remain:
            sum = remain.val + cv
            if sum >= 10:
                sum -= 10
                cv = 1
            else:
                cv = 0
            remain.val = sum
            pre.next = remain
            pre = remain
            remain = remain.next
        if cv:
            last = ListNode(1)
            pre.next = last
        return head
