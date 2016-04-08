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
    bool flag;
public:
    
    int isBalancedUtil(TreeNode *root)
    {
        if(!flag)
            return 0;
            
        if(!root)
            return 0;
        
        int l = isBalancedUtil(root->left);
        
        if(!flag)
            return 0;
            
        int r = isBalancedUtil(root->right);
        
        if(!flag)
            return 0;
        
        if(abs(l-r) > 1)
        {
            flag = false;
            return 0;
        }
        
        return ((l < r) ? (r+1) : (l+1));
    }

    bool isBalanced(TreeNode* root) {
        flag = true;
        isBalancedUtil(root);
        return flag;
    }
};

//One more solution without global variable.
class Solution {
    int isBalancedUtil(TreeNode* root)
    {
        if(root == nullptr)
            return 0;
        
        int l, r;
        
        l = isBalancedUtil(root->left);
        
        if(l == -1)
            return -1;
        
        r = isBalancedUtil(root->right);
        
        if(r == -1)
            return -1;
        
        if(abs(l - r) > 1)
            return -1;
        
        return max(l, r) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        return (isBalancedUtil(root) != -1);
    }
};