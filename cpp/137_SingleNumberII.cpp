#include <vector>


class Solution {
public:
	int singleNumber(std::vector<int>& nums) 
	{
		std::vector<int> bit_count(32, 0);
		int result = 0;

		for (int i = 0; i < 32; ++i)
		{
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