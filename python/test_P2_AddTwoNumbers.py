from unittest import TestCase

import P2_AddTwoNumbers


class TestSolution(TestCase):

    @staticmethod
    def convert(l):
        head = P2_AddTwoNumbers.ListNode(l[0])
        pre = head

        for val in l[1:]:
            cur = P2_AddTwoNumbers.ListNode(val)
            pre.next = cur
            pre = cur

        return head

    @staticmethod
    def equal(left, right):
        while left and right:
            if left.val != right.val:
                return False
            left = left.next
            right = right.next
        if left or right:
            return False
        return True

    def test_addTwoNumbers(self):
        s = P2_AddTwoNumbers.Solution()

        cases = [
            ([2, 4, 3], [5, 6, 4], [7, 0, 8]),
            ([0], [0], [0]),
            ([1, 2, 3], [1, 2], [2, 4, 3]),
            ([9, 9, 9], [1], [0, 0, 0, 1])
        ]

        for case in cases:
            list1 = self.convert(case[0])
            list2 = self.convert(case[1])
            expected = self.convert(case[2])

            result = s.addTwoNumbers(list1, list2)

            self.assertTrue(self.equal(result, expected), "failure in case: " + str(case))
