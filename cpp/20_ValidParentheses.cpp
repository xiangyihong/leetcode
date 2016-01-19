#include <string>
#include <stack>

class Solution {
public:
	bool isValid(std::string s) 
	{
		if (s.size() == 0)
			return true;

		if (s.size() == 1 || !IsLeftParenthese(s[0]))
			return false;

		std::stack<char> parenthese_stack;

		for (int i = 0; i < s.size(); ++i)
		{
			if (IsLeftParenthese(s[i]))
			{
				parenthese_stack.push(s[i]);
			}
			else
			{
				
				if (!parenthese_stack.empty())
				{
					char pre = parenthese_stack.top();
					if (IsMatch(pre, s[i]))
					{
						parenthese_stack.pop();
					}
					else
					{
						return false;
					}
				}
				else
				{
					return false;
				}
			}
		}
		if (parenthese_stack.empty())
		{
			return true;
		}
		return false;
	}

	bool IsLeftParenthese(char c)
	{
		return c == '(' || c == '[' || c == '{';
	}
	bool IsMatch(char a, char b)
	{
		if ((a == '(' && b == ')') ||
			(a == '[' && b == ']') ||
			(a == '{' && b == '}'))
		{
			return true;
		}
		return false;
	}
};
