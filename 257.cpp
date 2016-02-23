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
    vector<string> result;
    
    void binaryTreePaths(TreeNode *root, string visited)
    {
        if(!root->left && !root->right)
        {
            visited += to_string(root->val);
            result.push_back(visited);
            return;
        }
        
        if(root->left)
            binaryTreePaths(root->left, visited + to_string(root->val) + "->");
            
        if(root->right)
            binaryTreePaths(root->right, visited + to_string(root->val) + "->");
        
        return;
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root)
            return result;
            
        binaryTreePaths(root, "");
        
        return result;
    }
};