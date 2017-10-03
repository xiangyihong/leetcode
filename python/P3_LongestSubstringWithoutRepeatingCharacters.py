class Solution(object):

    @staticmethod
    def update(longest, start, cur):
        new_length = cur - start
        if new_length > (longest[1] - longest[0] + 1):
            longest[0] = start
            longest[1] = cur - 1
            return True
        return False

    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        if len(s) == 0:
            return 0

        longest = [0, 0]
        start_index = 0
        cur_index = 1
        while cur_index < len(s):
            c = s[cur_index]
            new_start = -1
            for i in range(start_index, cur_index):
                if c == s[i]:
                    new_start = i + 1
                    if self.update(longest, start_index, cur_index):
                        break
            if new_start == -1:
                cur_index += 1
                if cur_index == len(s):
                    self.update(longest, start_index, cur_index)

            else:
                start_index = new_start
                cur_index += 1
        return longest[1] - longest[0] + 1
