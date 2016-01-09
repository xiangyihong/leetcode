#include <string>

class Solution 
{
public:
	std::string convert(std::string& s, int numRows)
	{
		if (numRows == 1)
			return s;

		std::string result;

		int group_num = numRows + (numRows - 2);

		for (int row_index = 0; row_index < numRows; ++row_index)
		{
			int group_index = 0;
			while (group_index < s.size())
			{
				int first_index = group_index + row_index;
				if (first_index < s.size())
				{
					result.push_back(s[first_index]);
				}
				if (row_index != 0 && row_index != (numRows - 1))
				{
					int next_index = (group_num - row_index) + group_index;
					if (next_index < s.size())
					{
						result.push_back(s[next_index]);
					}
				}
				
				group_index += group_num;
			}
			
		}

		return result;
	}
};