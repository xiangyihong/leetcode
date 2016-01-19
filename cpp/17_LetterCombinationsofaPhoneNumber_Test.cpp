#include "gtest/gtest.h"
#include <vector>
#include <string>

#include "17_LetterCombinationsofaPhoneNumber.cpp"

struct ParamsAndExpectedResult
{
	std::string digits;
	std::vector<std::string> result;
};


template<typename T>
bool EqualVector(const std::vector<T>& a, const std::vector<T>& b)
{
	if (a.size() != b.size())
		return false;


	for (int i = 0; i < a.size(); ++i)
	{
		if (a[i] != b[i])
			return false;
	}
	return true;
}

TEST(LetterCombinationsofaPhoneNumber, NormalTest)
{
	std::vector<ParamsAndExpectedResult> test_cases =
	{
		{"", {}},
		{"1", {}},
		{"012", {}},
		{"2", {"a", "b", "c"}},
		{"23", { "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf" }},
		{"237", { "adp","adq","adr","ads","aep","aeq","aer","aes","afp","afq","afr","afs","bdp","bdq","bdr","bds","bep","beq","ber","bes","bfp","bfq","bfr","bfs","cdp","cdq","cdr","cds","cep","ceq","cer","ces","cfp","cfq","cfr","cfs" }},

	};

	for (int i = 0; i < test_cases.size(); ++i)
	{
		auto actual = Solution().letterCombinations(test_cases[i].digits);
		EXPECT_TRUE(EqualVector(test_cases[i].result, actual))
			<< "Index: " << i;
	}
}