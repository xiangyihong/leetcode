#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <memory>

class Solution {
public:


	std::vector<int> findSubstring(std::string& s, std::vector<std::string>& words)
	{


		std::vector<int> result;

		if (words.size() == 0)
			return result;

		std::vector<char> sub_indicator(s.size(), 0);
		for (int i = 0; i < words.size(); ++i)
		{
			int index = -1;
			while (true)
			{
				index = s.find(words[i], index + 1);
				if (index == std::string::npos)
					break;
				sub_indicator[index] = 1;
			}
		}

		std::map<std::string, int> words_frequency;
		for (int i = 0; i < words.size(); ++i)
		{
			++words_frequency[words[i]];
		}

		int word_len = words[0].size();

		for (int i = 0; i < s.size(); ++i)
		{
			if (sub_indicator[i] == 0)
				continue;

			std::map<std::string, int> current_words_frequency = words_frequency;

			bool found = true;
			for (int j = 0; j < words.size(); ++j)
			{
				int index = i + word_len * j;
				std::string tmp = s.substr(index, word_len);
				
				auto it = current_words_frequency.find(tmp);
				if (it == current_words_frequency.end()
					|| it->second == 0)
				{
					found = false;
					break;
				}
				--it->second;
			}

			if (found)
			{
				result.push_back(i);
			}
		}

		return result;
	}
};