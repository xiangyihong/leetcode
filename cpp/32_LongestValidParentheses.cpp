#include <string>
#include <stack>
#include <vector>

class Solution {
public:
	struct MatchStatus
	{
		int index;
		char has_match;
		char value;
	};
	int longestValidParentheses(std::string& s) 
	{
		if (s.size() <= 1)
			return 0;

		std::vector<char> matches(s.size(), 0);
		std::stack<MatchStatus> parentheses_stack;

		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == ')')
			{
				if (parentheses_stack.empty() || parentheses_stack.top().value == ')')
				{
					matches[i] = 0;
				}
				else if (parentheses_stack.top().value == '(')
				{
					int pre_index = parentheses_stack.top().index;
					matches[i] = 1;
					matches[pre_index] = 1;
					parentheses_stack.pop();
				}
			}
			else if (s[i] == '(')
			{
				MatchStatus tmp;
				tmp.index = i;
				tmp.value = '(';
				parentheses_stack.push(tmp);
			}
		}

		
		int current_steak = matches[0] == 1 ? 1 : 0;
		int max_steak = current_steak;

		for (int i = 1; i < matches.size(); ++i)
		{
			if (matches[i] == 1)
			{
				if (matches[i] != matches[i - 1])
				{
					current_steak = 1;
				}
				else
				{
					++current_steak;
					if (current_steak > max_steak)
					{
						max_steak = current_steak;
					}
				}
			}
		}
		return max_steak;
	}
};