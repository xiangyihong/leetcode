#include <iostream>
#include <vector>

class Solution {
public:
	int reverse(int x) 
	{
		if (x == 0)
			return 0;

		bool lNegtive = false;
		if (x < 0)
		{
			lNegtive = true;
			x = -x;
		}

		std::vector<int> v;
		while (x > 0)
		{
			int remain = x % 10;
			x /= 10;
			v.push_back(remain);
		}

		int result = 0;
		int index = 0;
		while (index < v.size())
		{
			int ltmp = result * 10;
			if (ltmp / 10 != result) // overflow, return 0
			{
				return 0;
			}
			result = ltmp;
			result += v[index];
			++index;
		}

		if (lNegtive)
		{
			result = -result;
		}
		return result;
	}
};

int main()
{
	int x = 1534236469;
	std::cout << Solution().reverse(x) << std::endl;
	system("pause");
	return 0;
}