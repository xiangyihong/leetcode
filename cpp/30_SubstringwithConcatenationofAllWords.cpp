#include <vector>
#include <string>

class Solution {
public:
	std::vector<int> findSubstring(std::string& s, std::vector<std::string>& words)
	{
		std::vector<int> result;

		if (words.size() == 0)
			return result;

		int word_len = words[0].size();
		int total_len = word_len * words.size();

		std::vector<int> is_word(s.size(), 0);
		std::vector<std::vector<int>> indexes(words.size());
		for (int i = 0; i < indexes.size(); ++i)
		{
			indexes[i].resize(s.size(), 0);
		}

		for (int i = 0; i < words.size(); ++i)
		{
			int index = -1;
			while (true)
			{
				index = s.find(words[i], index + 1);

				if (index == std::string::npos)
					break;

				indexes[i][index] = 1;
				is_word[index] = 1;

			}
		}

		for (int i = 0; (i + total_len) <= s.size(); ++i)
		{
			if ((is_word[i] == 1) && IsPotentialSubstring(i, word_len, words.size(), s.size(), is_word))
			{
				if (IsSubstring(s, i, word_len, indexes))
				{
					result.push_back(i);
				}

			}
		}
		return result;
	}

	bool IsPotentialSubstring(int index, int word_len, int word_count, int len, std::vector<int>& is_word)
	{
		for (int i = 0; i < word_count; ++i)
		{
			index = index + word_len * i;
			if (index >= len || !is_word[index])
				return false;
		}
		return true;
	}
	bool IsSubstring(std::string& s, int index, int word_len, std::vector<std::vector<int>>& indexes)
	{
		std::vector<int> unpicked_words_index;
		for (int i = 0; i < indexes.size(); ++i)
		{
			unpicked_words_index.push_back(i);
		}
		while (!unpicked_words_index.empty())
		{
			bool found = false;
			for (auto it = unpicked_words_index.begin();
			it != unpicked_words_index.end();
				++it)
			{
				int word_index = *it;
				if (indexes[word_index][index] == 1)
				{
					unpicked_words_index.erase(it);
					index += word_len;
					found = true;
					break;
				}
			}

			if (!found)
				return false;
		}
		return true;
	}
};