from unittest import TestCase

from P7_ReverseInteger import Solution


class TestSolution(TestCase):
    def test_reverse(self):

        cases = [
            (10, 1),
            (123, 321),
            (-123, -321),
            (0, 0),
            (1534236469, 0),
            (-2147483648, 0)
        ]

        s = Solution()
        for case in cases:
            result = s.reverse(case[0])
            self.assertEqual(result, case[1], "case mismatch: " + str(case))