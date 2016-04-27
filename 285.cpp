/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(root == nullptr || p == nullptr)
        	return nullptr;

        if(p->right)
        {
        	p = p->right;

        	while(p->left)
        		p = p->left;

        	return p;
        }

        TreeNode *result, *curr;
        result = nullptr;
        curr = root;

        while(curr != p)
        {
        	if(p->val < curr->val)
        	{
        		result = curr;
        		curr = curr->left;
        	}
        	else
        		curr = curr->right;
        }

        return result;
    }
};