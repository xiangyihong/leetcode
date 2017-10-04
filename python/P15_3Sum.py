class Solution(object):

    def findThreeSum(self, ones, twos, result):

        for k in ones.keys():
            # 1.
            match_value = -k
            if match_value % 2 == 0:
                half = match_value // 2
                count = twos.get(half)
                if count and count >= 2:
                    result.append([k, half, half])
            for x in twos.keys():
                if (x + x) < match_value:
                    exists = twos.get(match_value - x)
                    if exists:
                        result.append([k, x, match_value - x])

    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """

        negatives = {}
        zeros_count = 0
        positives = {}

        for val in nums:
            if val > 0:
                positives[val] = positives.get(val, 0) + 1
            elif val < 0:
                negatives[val] = negatives.get(val, 0) + 1
            else:
                zeros_count += 1


        result = []
        # case 1: no zero
        self.findThreeSum(negatives, positives, result)
        self.findThreeSum(positives, negatives, result)

        # case 2: one zero
        if zeros_count > 0:
            for k in positives.keys():
                match = negatives.get(-k)
                if match:
                    result.append([-k, 0, k])

        # case 3: three zeros
        if zeros_count >= 3:
            result.append([0, 0, 0])

        for case in result:
            case.sort()

        return result
