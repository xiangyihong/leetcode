#include <string>

class Solution {
public:
	int strStr(std::string& haystack, std::string& needle) 
	{
		if (needle.size() == 0)
			return 0;

		int index = 0;
		int sub_len = needle.size();
		int len = haystack.size();

		while ((index + sub_len) <= len)
		{
			if (haystack[index] == needle[0])
			{
				bool found = true;
				for (int i = 1; i < sub_len; ++i)
				{
					if (haystack[index + i] != needle[i])
					{
						found = false;
						break;
					}
				}
				if (found)
				{
					return index;
				}
			}
			++index;
		}
		return -1;
	}
};