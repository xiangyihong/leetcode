#include "gtest/gtest.h"
#include <vector>
#include <string>

#include "105_ConstructBinaryTreefromPreorderandInorderTraversal.cpp"

struct ParamsAndExpectedResult
{
	std::vector<int> preorder;
	std::vector<int> inorder;
};


void InorderTraverse(TreeNode* root, std::vector<int>& result)
{
	if (root == NULL)
		return;

	InorderTraverse(root->left, result);
	result.push_back(root->val);
	InorderTraverse(root->right, result);
}

std::vector<int> ConvertTreeNodeToVector(TreeNode* root)
{
	std::vector<int> result;

	InorderTraverse(root, result);
	return result;
}

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

TEST(ConstructBinaryTreefromPreorderandInorderTraversal, NormalTest)
{
	std::vector<ParamsAndExpectedResult> test_cases =
	{
		{{1,2,4,5,3,6}, {4,2,5,1,6,3}},
	};

	for (int i = 0; i < test_cases.size(); ++i)
	{
		TreeNode* actual_node = Solution().buildTree(test_cases[i].preorder, test_cases[i].inorder);
		std::vector<int> actual_inorder = ConvertTreeNodeToVector(actual_node);

		EXPECT_TRUE(EqualVector(test_cases[i].inorder, actual_inorder))
			<< "Index: " << i;
	}
}