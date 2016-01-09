#include <string>

class Solution
{
public:
	bool isMatch(std::string& s, std::string& p)
	{
		int len1 = s.size();
		int len2 = p.size();

		if (len2 > 0)
		{
			return hMatch(s, 0, p, 0);
		}
		else if (len1 == 0 && len2 == 0)
			return true;
		else
			return false;
	}

	bool equal(char a, char b)
	{
		if (b == '.')
			return true;
		return a == b;
	}
	bool hMatch(const std::string& s, int index1, const std::string& p, int index2)
	{
		int len1 = s.size();
		int len2 = p.size();

		if (index1 == len1 && index2 == len2)
			return true;
		else if (index2 == len2)
			return false;

		if (index2 + 1 < len2 && p[index2 + 1] == '*')
		{
			while (index2 + 2 < len2 && p[index2 + 2] == '*')
			{
				++index2;
			}
			int substitute_count = 0;
			
			while (index1 + substitute_count  <= len1)
			{
				if (substitute_count > 0)
				{
					if (!equal(s[index1 + substitute_count-1] , p[index2]))
					{
						return false;
					}
				}

				if (hMatch(s, index1 + substitute_count, p, index2 + 2))
				{
					return true;
				}
				++substitute_count;
			}
		}
		else if (equal(s[index1], p[index2]))
		{
			return hMatch(s, index1 + 1, p, index2 + 1);
		}
		return false;
	}
};