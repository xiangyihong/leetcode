#include <vector>

class Solution 
{
public:
	int removeDuplicates(std::vector<int>& nums) 
	{
		if (nums.size() <= 1)
			return nums.size();

		int current_end = 1;
		int index = 1;
		while (index < nums.size())
		{
			if (nums[index] != nums[index - 1])
			{
				nums[current_end++] = nums[index];
			}
			++index;
		}
#ifdef TEST_VECTOR_EQ
		for (int i = nums.size() - 1; i >= current_end; --i)
		{
			nums.erase(nums.begin() + i);
		}
#endif
		return current_end;
	}
};