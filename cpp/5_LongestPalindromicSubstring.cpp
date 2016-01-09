#include <string>
#include <vector>

const int MAX_NUM = 1000;

static int gPalindromTable[MAX_NUM][MAX_NUM];

class Solution 
{
public:

	bool IsSubsetPalindromic(const std::string& s, int start, int end)
	{
		int len = s.size();
		if (start >= len || end >= len)
		{
			return false;
		}

		if (start >= end)
			return true;

		if (gPalindromTable[start][end] == 0)
		{
			if (s[start] == s[end])
			{
				bool palindrom = false;
				if (start + 1 == end)
					palindrom = true;
				else
					palindrom = IsSubsetPalindromic(s, start + 1, end - 1);
				gPalindromTable[start][end] = palindrom ? 1 : -1;
				return palindrom;
			}
			else
			{
				gPalindromTable[start][end] = -1;
				return false;
			}
		}
		return gPalindromTable[start][end];
	}

	void FillPalindromTable(const std::string& s)
	{
		int len = s.size();

		for (int i = 0; i < len; ++i)
		{
			for (int j = i+1; j < len; ++j)
			{
				IsSubsetPalindromic(s, i, j);
			}
		}
	}
	std::string longestPalindrome(std::string& s) 
	{
		if (s.size() <= 1)
			return s;

		int len = s.size();

		for (int i = 0; i < len; ++i)
		{
			for (int j = 0; j < len; ++j)
			{
				gPalindromTable[i][j] = 0;
			}
		}

		FillPalindromTable(s);

		int max_start = 0;
		int max_end = 0;
		int max_len = 1;
		for (int i = 0; i < len; ++i)
		{
			for (int j = i + 1; j < len; ++j)
			{
				if (gPalindromTable[i][j] == 1)
				{
					if ((j - i + 1) > max_len)
					{
						max_start = i;
						max_end = j;
						max_len = max_end - max_start + 1;
					}
				}
			}
		}

		return s.substr(max_start, max_len);
	}
};

