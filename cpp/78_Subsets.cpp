#include <vector>
#include <algorithm>

class Solution {
public:
	std::vector<std::vector<int>> subsets(std::vector<int>& nums) 
	{
		std::sort(nums.begin(), nums.end());

		std::vector<std::vector<int>> result;
		std::vector<int> current_subset(nums.size(), 0);
		GetSubset(nums, 0, nums.size(), 0, current_subset, result);

		return result;
	}

	void GetSubset(std::vector<int>& nums, int index, int len, int current_index, std::vector<int>& current_subset, std::vector<std::vector<int>>& result)
	{
		if (index >= len)
		{
			if (index == 0)
			{
				result.push_back(std::vector<int>());
			}
			return;
		}
			

		int repeated = 1;
		int val = nums[index];
		for (int i = index + 1; i < len; ++i)
		{
			if (nums[i] == val)
			{
				++repeated;
			}
		}

		int next_index = index + repeated;

		if (repeated == 1)
		{
			for (int i = 0; i < 2; ++i)
			{
				
				if (i == 1)
				{
					current_subset[current_index] = nums[index];
				}
				int next_current_index = i == 1 ? current_index + 1 : current_index;
				if (next_index == len)
				{
					current_subset.resize(next_current_index);
					result.push_back(current_subset);
					current_subset.resize(len);
				}
				else
				{
					GetSubset(nums, index + 1, len, next_current_index, current_subset, result);
				}
			}
			
		}
		else
		{
			std::vector<std::vector<int>> duplicate_subset = DuplicateSubset(val, repeated);
			for (int i = 0; i < duplicate_subset.size(); ++i)
			{
				int next_current_index = current_index;
				for (int j = 0;
				 j < duplicate_subset[i].size(); 
					 ++j, ++next_current_index)
				{
					current_subset[next_current_index] = duplicate_subset[i][j];
				}
				 if (next_index == len)
				 {
					 current_subset.resize(next_current_index);
					 result.push_back(current_subset);
					 current_subset.resize(len);
				 }
				 else
				 {
					 GetSubset(nums, next_index, len, next_current_index, current_subset, result);
				 }
				 
			}
		}
	}

	std::vector<std::vector<int>> DuplicateSubset(int val, int count)
	{
		std::vector<std::vector<int>> result;

		result.push_back(std::vector<int>());
		for (int i = 1; i <= count; ++i)
		{
			result.push_back(std::vector<int>(i, val));
		}
		return result;
	}
};