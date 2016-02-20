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

    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        
        if(root->left && root->right)
            return min(minDepth(root->left)+1, minDepth(root->right)+1);
        else if(root->left)
            return minDepth(root->left)+1;
        else
            return minDepth(root->right)+1;
    }
};

class Solution1 {
    int minimumDepth;
public:
    void minDepth(TreeNode* root, int depth)
    {
        if(!root->left && !root->right)
        {
            if(depth < minimumDepth)
                minimumDepth = depth;
            
            return;
        }
        
        if(root->left)
            minDepth(root->left, depth+1);
        
        if(root->right)
            minDepth(root->right, depth+1);
    }

    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
            
        minimumDepth = INT_MAX;
        minDepth(root, 1);
        return minimumDepth;
    }
};