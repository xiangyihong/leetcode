#include <vector>


class Solution {
public:
	int singleNumber(std::vector<int>& nums) 
	{
		std::vector<int> bit_count(32, 0);
		int result = 0;

		for (int i = 0; i < 32; ++i)
		{
			// count the frequency of ith bit
			// if the count of ith bit is a multiple of 3
			// single number's ith bit must be 0
			for (int j = 0; j < nums.size(); ++j)
			{
				if (nums[j] & (1 << i))
					++bit_count[i];
			}

			result |= (bit_count[i] % 3) << i;
		}
		return result;
	}
};