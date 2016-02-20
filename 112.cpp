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
    int sumCopy;
    bool result;
public:
    void hasPathSumUtil(TreeNode* root, int currSum)
    {
        if(!root->left && !root->right)
        {
            if(sumCopy == currSum)
            {
                result = true;
                return;
            }
        }
        
        if(root->left)
            hasPathSumUtil(root->left, currSum + root->left->val);
            
        if(result)
            return;
            
        if(root->right)
            hasPathSumUtil(root->right, currSum + root->right->val);

    }

    bool hasPathSum(TreeNode* root, int sum) {
        result = false;
        
        if(!root)
            return false;

        sumCopy = sum;
        
        hasPathSumUtil(root, root->val);
        
        return result;
    }
};