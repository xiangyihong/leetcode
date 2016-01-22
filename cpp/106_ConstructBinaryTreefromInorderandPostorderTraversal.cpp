/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
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
	TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder) 
	{
		return ConstructTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
	}

	TreeNode* ConstructTree(std::vector<int>& inorder,
		int inorder_start,
		int inorder_end,
		std::vector<int>& postorder,
		int postorder_start,
		int postorder_end)
	{
		if (inorder_start > inorder_end)
			return NULL;

		int root_val = postorder[postorder_end];

		int root_index = -1;
		for (int i = inorder_start; i <= inorder_end; ++i)
		{
			if (inorder[i] == root_val)
			{
				root_index = i;
				break;
			}
		}

		int left_len = root_index - inorder_start;
		int right_len = inorder_end - root_index;

		TreeNode* root = new TreeNode(root_val);
		if (left_len > 0)
		{
			root->left = ConstructTree(inorder,
				inorder_start,
				root_index - 1,
				postorder,
				postorder_start,
				postorder_start + left_len-1);
		}
		if (right_len > 0)
		{
			root->right = ConstructTree(inorder,
				root_index + 1,
				inorder_end,
				postorder,
				postorder_start + left_len,
				postorder_end - 1);
		}

		return root;
	}
};