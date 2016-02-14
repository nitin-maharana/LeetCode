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
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
            
        int d1, d2;
        
        d1 = maxDepth(root->left);
        d2 = maxDepth(root->right);
        
        if(d1 > d2)
            return d1+1;
        else
            return d2+1;
    }
};