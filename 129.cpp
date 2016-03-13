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
    int sum;
    
    void sumNumbers(TreeNode *root, int tempSum)
    {
        if(root->left == NULL && root->right == NULL)
        {
            sum += tempSum;
            return;
        }
        
        if(root->left)
            sumNumbers(root->left, tempSum*10+root->left->val);
        
        if(root->right)
            sumNumbers(root->right, tempSum*10+root->right->val);
    }
public:
    int sumNumbers(TreeNode* root) {
        sum = 0;
        
        if(root == NULL)
            return 0;
        
        sumNumbers(root, root->val);
        
        return sum;
    }
};