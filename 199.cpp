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

//Recursive Solution.
class Solution {
    vector<int> result;
    int level;
    
    void rightSideView(TreeNode *root, int l)
    {
        if(!root)
            return;
        
        if(l == level + 1)
        {
            result.push_back(root->val);
            level++;
        }
        
        rightSideView(root->right, l+1);
        rightSideView(root->left, l+1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return result;
        
        level = 1;
        result.push_back(root->val);
        rightSideView(root, level);
        
        return result;
    }
};