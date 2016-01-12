#include <vector>
#include <string>
#include <memory>

class Solution 
{
public:
	std::vector<std::string> generateParenthesis(int n) 
	{
		std::vector<std::string> result;
		std::shared_ptr<char> container(new char[2 * n + 1]);
		container.get()[2 * n] = '\0';

		Fill(container.get(), 0, 2 * n, n, n, result);
		return result;
	}

	void Fill(char* container, int index, int n, int left, int right, std::vector<std::string>& oResult)
	{
		if (index == n)
		{
			container[index] = '\0';
			std::string tmp = container;
			oResult.push_back(tmp);
			return;
		}
		if (index > n)
			return;

		if (left > 0)
		{
			container[index] = '(';
			Fill(container, index + 1, n, left - 1, right, oResult);
		}
		
		if (right > 0)
		{
			int filled_left_count = (n >> 1) - left;
			int filled_right_count =(n >> 1) - right;
			if (filled_left_count > filled_right_count)
			{
				container[index] = ')';
				Fill(container, index + 1, n, left, right - 1, oResult);
			}
		}
	}
};