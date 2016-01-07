#include <string>
#include <iostream>
#include <algorithm>

class Solution {
public:
	int lengthOfLongestSubstring(std::string s) 
	{
		if (s.size() <= 1)
			return s.size();

		int len = 0;
		int lBegin = 0;
		int lEnd = 1;
		int lMaxBegin = 0;
		int lMaxEnd = 1;

	
		while (lEnd < s.size())
		{
			int lTmpIndex = lBegin;
			int lLastFoundIndex = -1;
			while (lTmpIndex < lEnd)
			{
				if (s[lTmpIndex] == s[lEnd])
				{
					lLastFoundIndex = lTmpIndex;
				}
				++lTmpIndex;
			}
			if (lLastFoundIndex != -1)
			{
				if ((lEnd - lBegin) > (lMaxEnd - lMaxBegin))
				{
					lMaxBegin = lBegin;
					lMaxEnd = lEnd;
				}
				lBegin = lLastFoundIndex + 1;
			}

			++lEnd;
		}
		if ((lEnd - lBegin) > (lMaxEnd - lMaxBegin))
		{
			lMaxBegin = lBegin;
			lMaxEnd = lEnd;
		}
		return lMaxEnd - lMaxBegin;
	}
};

int main()
{
	std::string s = "au";
	std::cout << Solution().lengthOfLongestSubstring(s) << std::endl;
	system("pause");
	return 0;
}