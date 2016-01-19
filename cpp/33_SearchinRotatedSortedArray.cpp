#include <vector>
#include <algorithm>

class Solution {
public:
	int search(std::vector<int>& nums, int target) 
	{
		if (nums.size() == 0)
			return -1;

		if (nums.size() == 1)
		{
			return target == nums[0] ? 0 : -1;
		}
		int pivot = SearchPivot(nums, 0, nums.size());

		int begin = -1;
		int end = -1;

		if (pivot == 0)
		{
			begin = 0;
			end = nums.size();
		}
		else
		{
			if (target < nums[0])
			{
				begin = pivot;
				end = nums.size();
			}
			else
			{
				begin = 0;
				end = pivot;
			}
		}
		
		auto it = std::lower_bound(nums.begin() + begin, nums.begin() + end, target);
		if (it == nums.end() || (*it) != target)
			return -1;
		return std::distance(nums.begin(), it);
	}

	int SearchPivot(std::vector<int>& nums, int begin, int end)
	{
		if (begin + 1 == end)
			return begin;
		
		int last_element = nums[end - 1];
		int first_element = nums[begin];

		if (first_element < last_element)
			return begin;

		int mid = (begin + end) / 2;

		if (nums[mid - 1] > nums[mid])
		{
			return mid;
		}
		else if (nums[mid] < last_element)
		{
			return SearchPivot(nums, begin, mid);
		}
		else
		{
			return SearchPivot(nums, mid, end);
		}
	}
};
