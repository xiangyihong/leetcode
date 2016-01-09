#include <string>

class Solution 
{
public:


	std::string intToRoman(int num) 
	{
		std::string result;
		if (num >= 1000)
		{
			result = "M";
			result += intToRoman(num - 1000);
		}
		else if (num < 1000 && num >= 900)
		{
			result = "CM";
			result += intToRoman(num - 900);
		}
		else if (num < 900 && num >= 500)
		{
			result = "D";
			result += intToRoman(num - 500);
		}
		else if (num < 500 && num >= 400)
		{
			result = "CD";
			result += intToRoman(num - 400);
		}
		else if (num >= 100 && num < 400)
		{
			result = "C";
			result += intToRoman(num - 100);
		}
		else if (num < 100 && num >= 90)
		{
			result = "XC";
			result += intToRoman(num - 90);
		}
		else if (num >= 50 && num < 90)
		{
			result = "L";
			result += intToRoman(num - 50);
		}
		else if (num < 50 && num >= 40)
		{
			result = "XL";
			result += intToRoman(num - 40);
		}
		else if (num >= 10 & num < 40)
		{
			result = "X";
			result += intToRoman(num - 10);
		}
		else if (num < 10 && num >= 9)
		{
			result = "IX";
		}
		else if (num >= 5 && num < 9)
		{
			result = "V";
			result += intToRoman(num - 5);
		}
		else if (num < 5 && num >= 4)
		{
			result = "IV";
		}
		else if (num >= 1 && num < 4)
		{
			for (int i = 0; i < num; ++i)
			{
				result += "I";
			}
		}
		
		return result;
	}
};