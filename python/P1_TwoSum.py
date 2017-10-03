class Solution:

    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        s = {val: index for index, val in enumerate(nums)}
        for index, val in enumerate(nums):
            matcher = s.get(target - val)
            if matcher and matcher != index:
                return [index, matcher]
