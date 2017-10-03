from unittest import TestCase

from P1_TwoSum import Solution


class TestSolution(TestCase):
    def test_twoSum(self):
        s = Solution()

        cases = [([2, 7, 11, 15], 9, [0, 1]),
                 ([2, 1, 3, 5], 4, [1, 2])]

        for case in cases:
            result = s.twoSum(case[0], case[1])
            self.assertEqual(result, case[2], "mismatch for case: " + str(case))
