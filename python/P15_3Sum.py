import bisect

class Solution(object):

    def find(self, values, target, start_index):
        index = bisect.bisect_left(values, target, start_index)
        if index < len(values) and values[index] == target:
            return index
        return None

    def findTwoSum(self, values, target):

        result = []
        for i in range(len(values)):
            if i > target / 2:
                break
            match_value = target - values[i]
            if self.find(values, match_value, i + 1):
                result.append([values[i], match_value])
        return result

    def findThreeSum(self, ones, twos, result):
        pre = None
        for val in ones:
            if pre and pre == val:
                continue
            tmp_sum = -val
            matches = self.findTwoSum(twos, tmp_sum)
            if matches:
                for item in matches:
                    result.append([val, item[0], item[1]])
            pre = val

    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """

        negatives = []
        zeros = []
        positives = []

        for val in enumerate(nums):
            if val > 0:
                positives.append(val)
            elif val < 0:
                negatives.append(val)
            else:
                zeros.append(val)

        positives.sort()

        result = []
        # case 1: no zero
        self.findThreeSum(negatives, positives, result)
        self.findThreeSum(positives, negatives, result)

        # case 2: one zero
        if len(zeros) > 0:
            for val in negatives:
                match = self.find(positives, -val, 0)
                if match:
                    result.append([val, 0, -val])

        # case 3: three zeros
        if len(zeros) >= 3:
            result.append([0, 0, 0])

        return result
