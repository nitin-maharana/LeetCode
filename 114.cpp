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
    void flatten(TreeNode* root) {
        if(root == NULL)
            return;

        stack<TreeNode*> memory;
        memory.push(root);
        TreeNode* curr;

        while(!memory.empty())
        {
            curr = memory.top();
            memory.pop();
            
            if(curr->right)
                memory.push(curr->right);
            
            if(curr->left)
                memory.push(curr->left);
            
            if(!memory.empty())
                curr->right = memory.top();
            
            curr->left = NULL;
        }
    }
};