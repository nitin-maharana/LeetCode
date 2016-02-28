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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        
        if(!root)
            return result;
        
        stack<TreeNode*> memory;
        TreeNode *top;
        
        memory.push(root);
        
        while(!memory.empty())
        {
            top = memory.top();
            result.push_back(top->val);
            memory.pop();
            
            if(top->right)
                memory.push(top->right);
            
            if(top->left)
                memory.push(top->left);
        }
        
        return result;
    }
};

//Recursive Solution.
class Solution {
    vector<int> result;
    
    void preorderTraversalUtil(TreeNode* root)
    {
        if(!root)
            return;
        
        result.push_back(root->val);
        preorderTraversalUtil(root->left);
        preorderTraversalUtil(root->right);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        preorderTraversalUtil(root);
        return result;
    }
};