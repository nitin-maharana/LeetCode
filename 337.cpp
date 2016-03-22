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
    pair<int,int> robUtil(TreeNode* root)
    {
        if(root == NULL)
            return make_pair(0, 0);
        
        pair<int, int> left, right;
        
        left = robUtil(root->left);
        right = robUtil(root->right);
        
        int include, notInclude;
        
        include = root->val + left.second + right.second;
        notInclude = max(left.first, left.second) + max(right.first, right.second);
        
        return make_pair(include, notInclude);
    }
public:
    int rob(TreeNode* root) {
        pair<int,int> result;
        result = robUtil(root);
        return max(result.first, result.second);
    }
};