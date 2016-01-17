#include <vector>

class Solution 
{
public:
	int removeElement(std::vector<int>& nums, int val) 
	{
		if (nums.size() == 0)
			return 0;

		int end = 0;
		int next = 0;

		while (next < nums.size())
		{
			if (nums[next] != val)
			{
				nums[end] = nums[next];
				++end;
			}
			++next;
		}

#ifdef TEST_VECTOR_EQ
		for (int i = nums.size() - 1; i >= end; --i)
		{
			nums.erase(nums.begin() + i);
		}
#endif
		return end;
		
	}
};