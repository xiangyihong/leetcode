class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """

        result = 0
        negtive = False
        if x < 0:
            negtive = True
            x = -x

        while x:
            tmp = x % 10
            x = x // 10
            result = result * 10 + tmp

        if negtive:
            result = -result
            if result < -2147483648:
                result = 0
        else:
            if result > 0x7fffffff:
                result = 0

        return result


