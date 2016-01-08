#include <vector>

class Solution 
{
public:
	double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) 
	{
		int n1 = nums1.size();
		int n2 = nums2.size();

		if (n1 == 0 && n2 == 0)
			return 0.0;

		std::vector<int> sorted_nums;
		int index1 = 0;
		int index2 = 0;

		while (index1 < n1 && index2 < n2)
		{
			if (nums1[index1] < nums2[index2])
			{
				sorted_nums.push_back(nums1[index1]);
				++index1;
			}
			else if (nums1[index1] > nums2[index2])
			{
				sorted_nums.push_back(nums2[index2]);
				++index2;
			}
			else
			{
				sorted_nums.push_back(nums1[index1]);
				sorted_nums.push_back(nums2[index2]);
				++index1;
				++index2;
			}
		}

		std::vector<int>& remainning_list = index1 < n1 ? nums1 : nums2;
		int remainning_index = index1 < n1 ? index1 : index2;
		while (remainning_index < remainning_list.size())
		{
			sorted_nums.push_back(remainning_list[remainning_index]);
			++remainning_index;
		}

		int middle_index1 = (n1 + n2) / 2;
		int middle_index2 = (n1 + n2 - 1) / 2;
		return (sorted_nums[middle_index1] + sorted_nums[middle_index2]) / 2.0;
	}
};