#include <vector>

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

class Solution {
public:
	TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) 
	{
		return ConstructTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
	}

	TreeNode* ConstructTree(std::vector<int>& preorder,
		int preorder_start,
		int preorder_end,
		std::vector<int>& inorder,
		int inorder_start,
		int inorder_end)
	{
		if (preorder_start > preorder_end)
			return NULL;

		int root_val = preorder[preorder_start];

		int root_index = inorder_start;
		for (; root_index <= inorder_end; ++root_index)
		{
			if (inorder[root_index] == root_val)
				break;
		}

		int left_len = root_index - inorder_start;
		int right_len = inorder_end - root_index;

		TreeNode* root = new TreeNode(root_val);
		if (left_len > 0)
		{
			root->left = ConstructTree(preorder,
				preorder_start + 1,
				preorder_start + left_len,
				inorder,
				inorder_start,
				root_index-1);
		}
		if (right_len > 0)
		{
			root->right = ConstructTree(preorder,
				preorder_start + left_len + 1,
				preorder_end,
				inorder,
				root_index + 1,
				inorder_end);
		}
		return root;
	}
};
