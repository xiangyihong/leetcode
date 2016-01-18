#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <memory>

class Solution {
public:

	struct Counter
	{
		int total;
		int count_down;
		Counter() :total(0), count_down(0)
		{}
	};
	std::vector<int> findSubstring(std::string& s, std::vector<std::string>& words)
	{
		std::vector<int> result;

		if (words.size() == 0)
		return result;

		int word_len = words[0].size();
		int total_len = word_len * words.size();

		int total_words = words.size();

		std::map<std::string, int> duplicate_word_to_counter;

		std::sort(words.begin(), words.end());

		std::string pre = words[0];
		for (int i = 1; i < words.size(); ++i)
		{
		if (pre == words[i])
		{
		++(duplicate_word_to_counter[pre]);
		}
		}


		auto last = std::unique(words.begin(), words.end());
		words.erase(last, words.end());

		std::vector<int> words_counter(words.size(), 0);
		for (int i = 0; i < words.size(); ++i)
		{
		auto it = duplicate_word_to_counter.find(words[i]);
		words_counter[i] = (it == duplicate_word_to_counter.end()) ? 1 : it->second+1;
		}

		std::shared_ptr<std::vector<char>> is_word_ptr = std::make_shared<std::vector<char>>(s.size(), 0);
		std::vector<char>& is_word = *is_word_ptr.get();

		typedef std::vector<std::vector<char>> TwoDemension;
		std::shared_ptr<TwoDemension> indexes_ptr = std::make_shared<TwoDemension>(words.size());
		TwoDemension& indexes = *indexes_ptr.get();
		
		for (int i = 0; i < indexes.size(); ++i)
		{
			indexes[i].resize(s.size(), 0);
		}

		for (int i = 0; i < words.size(); ++i)
		{
			int index = -1;
			while (true)
			{
				index = s.find(words[i], index+1);

				if (index == std::string::npos)
					break;

				indexes[i][index] = 1;
				//is_word[index] = 1;
				
			}
		}

		std::vector<int> actual_words_count(words_counter.size(), 0);
		for (int i = 0; (i+total_len) <= s.size(); ++i)
		{
		if (IsWord(i, indexes)
		&& IsPotentialSubstring(i, word_len, total_words, s.size(), indexes)
		)
		{
		if (IsSubstring(words, i, word_len, total_words, indexes, actual_words_count, words_counter))
		{
		result.push_back(i);
		}

		}
		}
		return result;
	}

	bool IsWord(int index, std::vector<std::vector<char>>& indexes)
	{
		for (int i = 0; i < indexes.size(); ++i)
		{
			if (indexes[i][index] == 1)
				return true;
		}
		return false;
	}
	bool IsPotentialSubstring(int index, int word_len, int word_count, int len, std::vector<std::vector<char>>& indexes)
	{
		for (int i = 0; i < word_count; ++i)
		{
			index = index + word_len * i;
			if (index >= len || !IsWord(index, indexes))
				return false;
		}
		return true;
	}
	bool IsSubstring(std::vector<std::string>& words,
		int index, int word_len, int word_count,
		std::vector<std::vector<char>>& indexes,
		std::vector<int>& actual_words_count,
		std::vector<int>& words_counter)
	{

		for (int i = 0; i < actual_words_count.size(); ++i)
		{
			actual_words_count[i] = 0;
		}
		for (int i = 0; i < word_count; ++i)
		{
			index = index + word_len*i;
			for (int j = 0; j < indexes.size(); ++j)
			{
				if (indexes[j][index] == 1)
				{
					++actual_words_count[j];
					break;
				}
			}
		}

		for (int i = 0; i < actual_words_count.size(); ++i)
		{
			if (actual_words_count[i] != words_counter[i])
				return false;
		}
		return true;

	}
};