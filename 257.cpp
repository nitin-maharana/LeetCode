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
    void binaryTreePaths(TreeNode *root, string visited, vector<string>& result)
    {
        if(root->left == nullptr && root->right == nullptr)
        {
            visited += to_string(root->val);
            result.push_back(visited);
            return;
        }
        
        if(root->left)
            binaryTreePaths(root->left, visited + to_string(root->val) + "->", result);
            
        if(root->right)
            binaryTreePaths(root->right, visited + to_string(root->val) + "->", result);
        
        return;
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        
        if(root == nullptr)
            return result;
            
        binaryTreePaths(root, "", result);
        
        return result;
    }
};
