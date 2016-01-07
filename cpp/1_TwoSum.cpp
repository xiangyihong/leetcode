#include <vector>
#include <map>
#include <algorithm>

using std::vector;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		typedef std::map<int, std::vector<int> > ValueToIndexes;
		ValueToIndexes lIndexes;
		for (int i = 0; i < nums.size(); ++i)
		{
			ValueToIndexes::iterator it = lIndexes.find(nums[i]);
			if (it == lIndexes.end())
			{
				it = lIndexes.insert(std::make_pair(nums[i], std::vector<int>())).first;
			}
			it->second.push_back(i);
		}

		std::vector<int> lResult;
		for (int i = 0; i < nums.size(); ++i)
		{
			int match_value = target - nums[i];
			ValueToIndexes::iterator it = lIndexes.find(match_value);
			if (it != lIndexes.end())
			{
				for (int j = 0; j < it->second.size(); ++j)
				{
					if (it->second[j] != i)
					{
						lResult.push_back(i+1);
						lResult.push_back(it->second[j]+1);
						std::sort(lResult.begin(), lResult.end());
						return lResult;
					}
				}
			}
		}
		return lResult;
	}
};

