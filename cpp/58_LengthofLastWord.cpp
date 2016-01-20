#include <string>


class Solution {
public:
	int lengthOfLastWord(std::string& s) 
	{
		if (s.empty())
			return 0;

		auto left_strip_index = s.find_first_not_of(' ');
		

		if (left_strip_index == std::string::npos)
		{
			return 0;
		}

		auto right_strip_index = s.find_last_not_of(' ');

		int last_word_index = -1;
		auto last_space_index = s.find_last_of(' ', right_strip_index);
		if (last_space_index == std::string::npos || last_space_index < left_strip_index)
		{
			last_word_index = left_strip_index;
		}
		else
		{
			last_word_index = last_space_index + 1;
		}

		return right_strip_index - last_word_index + 1;
	}
};