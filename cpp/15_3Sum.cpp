#include <vector>
#include <algorithm>
#include <set>

using std::vector;

struct TwoSum
{
	int a;
	int b;
};
class Solution {
public:

	vector<TwoSum> FindTwoSum(vector<int>::iterator begin, vector<int>::iterator end, int sum)
	{
		vector<TwoSum> v;
		for (auto it = begin; it != end; ++it)
		{
			if ((it + 1 != end) && (*it) == *(it + 1))
			{
				if ((*it) + (*it) == sum)
				{
					if ((it == begin) || (*it) != *(it - 1))
					{
						TwoSum s;
						s.a = *it;
						s.b = *it;
						v.push_back(s);
					}

				}
				continue;
			}
			int counter_part = sum - *it;
			if (std::binary_search(it + 1, end, counter_part))
			{
				TwoSum s;
				s.a = std::min(*it, counter_part);
				s.b = std::max(*it, counter_part);
				v.push_back(s);
			}
		}
		return v;
	}

	vector<vector<int>> threeSum(vector<int>& nums)
	{
		vector<vector<int> > result;

		if (nums.size() < 3)
		{
			return result;
		}

		std::sort(nums.begin(), nums.end());

		auto pivot = std::equal_range(nums.begin(), nums.end(), 0);

		if (pivot.second == nums.end())
		{
			if (std::distance(pivot.first, pivot.second) >= 3)
			{
				vector<int> tmp = { 0,0,0 };
				result.push_back(tmp);
			}
			return result;
		}

		bool has_zero = pivot.first != pivot.second;
		// check negtive numbers
		for (auto it = nums.begin(); it != pivot.first; ++it)
		{
			if ((it + 1 != pivot.first) && (*it) == *(it + 1))
			{
				continue;
			}
			if (has_zero && std::binary_search(pivot.second, nums.end(), -(*it)))
			{
				vector<int> tmp = { *it, 0, -(*it) };
				result.push_back(tmp);
			}

			vector<TwoSum> twosums = FindTwoSum(pivot.second, nums.end(), -(*it));
			for (int i = 0; i < twosums.size(); ++i)
			{
				vector<int> tmp = { *it, twosums[i].a, twosums[i].b };
				result.push_back(tmp);
			}
		}

		for (auto it = pivot.second; it != nums.end(); ++it)
		{
			if ((it + 1 != nums.end()) && (*it) == *(it + 1))
			{
				continue;
			}
			//if (std::binary_search(nums.begin(), pivot.first, -(*it)))
			//{
			//	vector<int> tmp = { -(*it), 0, *it };
			//	result.push_back(tmp);
			//}
			vector<TwoSum> twosums = FindTwoSum(nums.begin(), pivot.first, -(*it));
			for (int i = 0; i < twosums.size(); ++i)
			{
				vector<int> tmp = { twosums[i].a, twosums[i].b, *it };
				result.push_back(tmp);
			}
		}

		if (std::distance(pivot.first, pivot.second) >= 3)
		{
			vector<int> tmp = { 0,0,0 };
			result.push_back(tmp);
		}

		mysort(result);
		return result;
	}

	class ThreeIntComp
	{
	public:
		bool operator()(const vector<int>& a, const vector<int>& b)
		{
			bool r = a[0] < b[0];
			if (a[0] == b[0])
			{
				r = a[1] < b[1];
				if (a[1] == b[1])
				{
					return a[2] == b[2];
				}
			}
			return r;
		}

	};
	void mysort(vector<vector<int>>& r)
	{
		std::sort(r.begin(), r.end(), ThreeIntComp());
	}
};

// test case
// [7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6]
// [0,0,0]
// [1,1,-2]