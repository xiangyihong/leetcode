#include <vector>

class Solution {
public:
	int missingNumber(std::vector<int>& nums) 
	{
		int max_num = nums.size();
		int result = 0;
		for (int i = 0; i < max_num; ++i)
		{
			result = result ^ nums[i] ^ (i+1);
		}
		return result;
	}
};