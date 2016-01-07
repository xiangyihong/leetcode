#include <iostream>
#include <string>


class Solution {
public:
	int myAtoi(std::string str) 
	{
		if (str.size() == 0)
			return 0;

		int lStartIndex = 0;
		while (lStartIndex < str.size() && isspace(str[lStartIndex]))
		{
			++lStartIndex;
		}

		if (lStartIndex == str.size())
			return 0;

		bool negtive = false;
		if (str[lStartIndex] == '-')
		{
			negtive = true;
			++lStartIndex;
		}
		else if (str[lStartIndex] == '+')
		{
			++lStartIndex;
		}

		int lResult = 0;
		while (lStartIndex < str.size())
		{
			if (!isdigit(str[lStartIndex]))
				return lResult;

			int ltmp = lResult * 10;
			if(ltmp / 10 != lResult)
				return negtive ? INT_MIN : INT_MAX;

			lResult = ltmp;

			int digit = str[lStartIndex] - '0';
			digit = negtive ? -digit : digit;

			lResult += digit;
			if ((negtive && lResult > 0) || (!negtive && lResult < 0))
			{
				return negtive ? INT_MIN : INT_MAX;
			}
			++lStartIndex;
		}
		return lResult;
	}
};

int main()
{

	std::string s = "-2147483649";
	std::cout << Solution().myAtoi(s) << std::endl;
	system("pause");
	return 0;
}