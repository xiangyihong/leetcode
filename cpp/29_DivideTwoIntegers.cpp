#include <climits>
#include <cstdint>

#ifndef MAX_INT
#define MAX_INT INT_MAX
#endif

class Solution {
public:
	int divide(int dividend, int divisor) 
	{
		if (divisor == 0)
			return MAX_INT;

		if (dividend == INT_MIN && divisor == -1)
			return MAX_INT;

		if (divisor == 1)
			return dividend;
		if (divisor == -1)
			return -dividend;

		int64_t dividend_64 = dividend;
		int64_t divisor_64 = divisor;

		int negtive_count = 0;
		if (dividend_64 < 0)
		{
			++negtive_count;
			dividend_64 = -dividend_64;
		}
		if (divisor_64 < 0)
		{
			++negtive_count;
			divisor_64 = -divisor_64;
		}
		int result = 0;
		int64_t remain = dividend_64;
		while (remain >= divisor_64)
		{
			int64_t lower = 0;
			int64_t upper = 0;
			int shift = 0;
			int mul = 0;
			upper = divisor_64 << shift;
			while (upper <= remain && shift < 31)
			{
				lower = upper;
				++shift;
				upper = divisor_64 << shift;

				if (mul == 0)
					mul = 1;
				else
					mul <<= 1;
			}
			
			result += mul;
			remain -= lower;
		}
		return (negtive_count & 1) ? -result : result;
	}
};