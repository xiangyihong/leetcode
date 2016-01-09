#include <vector>
#include <cstdlib>

class Solution 
{
public:
	bool isPalindrome(int x) 
	{
		if (x < 0)
			return false;
		if (x == 0)
			return true;

		std::vector<int> splited;
		splited.reserve(20);
		int tmp = x;
		while (tmp > 0)
		{
			std::div_t d = std::div(tmp, 10);
			tmp = d.quot;
			splited.push_back(d.rem);
		}

		int n = splited.size();
		int index = 0;
		while (index < n)
		{
			if (splited[index] != splited[n - 1 - index])
			{
				return false;
			}
			++index;
		}
		return true;
	}
};
