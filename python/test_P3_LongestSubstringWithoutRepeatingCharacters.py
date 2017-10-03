from unittest import TestCase

from P3_LongestSubstringWithoutRepeatingCharacters import Solution


class TestSolution(TestCase):
    def test_lengthOfLongestSubstring(self):

        cases = [
            ("abcabcbb", 3),
            ("bbbbb", 1),
            ("pwwkew", 3),
            ("", 0),
            ("au", 2)
        ]

        s = Solution()
        for case in cases:
            result = s.lengthOfLongestSubstring(case[0])
            self.assertEqual(result, case[1], "case mismatch: " + str(case))
