#include <vector>
#include <climits>
#include <algorithm>

class Solution {
public:
	void nextPermutation(std::vector<int>& nums) 
	{
		if (nums.size() == 0)
			return;

		return GetNextPermutation(nums, 0);
	}

	void GetNextPermutation(std::vector<int>& nums, int index)
	{
		int max_num = INT_MIN;
		int max_index = -1;
		for (int i = index; i < nums.size(); ++i)
		{
			if (max_num < nums[i])
			{
				max_num = nums[i];
				max_index = i;
			}
		}

		int unordered_index = -1;
		for (int i = max_index + 1; (i+1) < nums.size(); ++i)
		{
			if (nums[i] < nums[i + 1])
			{
				unordered_index = i;
				break;
			}
		}

		if (unordered_index != -1)
		{
			return GetNextPermutation(nums, unordered_index);
		}
		else
		{
			if (max_index == 0)
			{
				std::reverse(nums.begin(), nums.end());
			}
			else
			{
				int next_num_index = GetNextNumIndex(nums, max_index, nums[max_index - 1]);
				std::swap(nums[max_index - 1], nums[next_num_index]);

				std::sort(nums.begin() + max_index, nums.end());
			}
		}

	}

	int GetNextNumIndex(std::vector<int>& nums, int index, int num)
	{
		int result = INT_MAX;
		int result_index = -1;
		for (int i = index; i < nums.size(); ++i)
		{
			if ((nums[i] > num) && nums[i] < result)
			{
				result = nums[i];
				result_index = i;
			}
		}
		return result_index;
	}
};
