#include <string>
#include <vector>
#include <map>

class Solution {
public:
	std::vector<std::string> letterCombinations(std::string& digits) 
	{
		std::vector<std::string> result;

		if (digits.size() == 0)
			return result;

		for (int i = 0; i < digits.size(); ++i)
		{
			if (!IsValidDigit(digits[i]))
				return result;
		}

		std::string current_combination(digits.size(), '\0');
		GetCombination(digits, 0, current_combination, result);

		return result;
	}

	void GetCombination(std::string& digits, int index, std::string& current_combination, std::vector<std::string>& result)
	{
		const std::string& letters = GetMappedLetters(digits[index]);

		for (int i = 0; i < letters.size(); ++i)
		{
			current_combination[index] = letters[i];
			if (index == (digits.size() - 1))
			{
				result.push_back(current_combination);
			}
			else
			{
				GetCombination(digits, index + 1, current_combination, result);
			}
		}
	}
	bool IsValidDigit(char c)
	{
		return c >= '2' && c <= '9';
	}
	const std::string& GetMappedLetters(char digit)
	{
		static std::map<char, std::string> DigitToLetters = 
		{
			{'2', "abc"},
			{'3', "def"},
			{'4', "ghi"},
			{'5', "jkl"},
			{'6', "mno"},
			{'7', "pqrs"},
			{'8', "tuv"},
			{'9', "wxyz"}
		};

		auto it = DigitToLetters.find(digit);
		if (it == DigitToLetters.end())
			return "";
		return it->second;
	}
};
