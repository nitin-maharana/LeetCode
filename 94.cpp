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

//Iterative Solution.
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        
        if(root == nullptr)
            return result;
        
        stack<TreeNode*> memory;
        
        while(!memory.empty() || root)
        {
            if(root == nullptr)
            {
                root = memory.top();
                memory.pop();
                result.push_back(root->val);
                root = root->right;
            }
            else
            {
                memory.push(root);
                root = root->left;
            }
        }
        
        return result;
    }
};

//Recursive Solution.
class Solution {
    vector<int> result;
    
    void inorderTraversalUtil(TreeNode *root)
    {
        if(root == nullptr)
            return;
        
        inorderTraversalUtil(root->left);
        result.push_back(root->val);
        inorderTraversalUtil(root->right);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        inorderTraversalUtil(root);
        return result;
    }
};
