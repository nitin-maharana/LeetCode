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
    bool isValidBST(TreeNode* root, long l, long r)
    {
        if(root == NULL)
            return true;
        
        if(root->val <= l || root->val >= r)
            return false;
        
        return (isValidBST(root->left, l, root->val) && isValidBST(root->right, root->val, r));
    }
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }
};