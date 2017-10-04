from unittest import TestCase

from P15_3Sum import Solution


class TestSolution(TestCase):

    def equal(self, list1, list2):

        if len(list1) != len(list2):
            return False

        for item in list1:
            item.sort()
            found = False
            for match in list2:
                match.sort()
                if item == match:
                    found = True
                    break
            if not found:
                return False

        return True

    def test_findTwoSum(self):
        cases = [
            ([-1, 0, 1, 2, -1, -4],
             [[-1, 0, 1], [-1, -1, 2]]),
            ([-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6],
             [[-4, -2, 6], [-4, 0, 4], [-4, 1, 3], [-4, 2, 2], [-2, -2, 4], [-2, 0, 2]]),
            ([-4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0],
             [[-5, 1, 4], [-4, 0, 4], [-4, 1, 3], [-2, -2, 4], [-2, 1, 1], [0, 0, 0]]),
            ([3,0,-2,-1,1,2],
             [[-2, -1, 3], [-2, 0, 2], [-1, 0, 1]])
        ]

        s = Solution()
        for case in cases:
            result = s.threeSum(case[0])
            self.assertTrue(self.equal(result, case[1]), "mismatch, " + str(case))
