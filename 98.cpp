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
    bool isValidBST(TreeNode* root, long l, long r)
    {
        if(root == NULL)
            return true;
        
        if(root->val <= l || root->val >= r)
            return false;
        
        return (isValidBST(root->left, l, root->val) && isValidBST(root->right, root->val, r));
    }
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }
};

//One more solution with inorder traversal
class Solution {
    void isValidBST(TreeNode* root, vector<int>& memory)
    {
        if(root == NULL)
            return;
        
        isValidBST(root->left, memory);
        memory.push_back(root->val);
        isValidBST(root->right, memory);
    }
public:
    bool isValidBST(TreeNode* root) {
        
        if(root == NULL)
            return true;
        
        vector<int> memory;
        isValidBST(root, memory);
        
        for(int i = 1; i < memory.size(); i++)
            if(memory[i] <= memory[i-1])
                return false;
        
        return true;
    }
};

//One more solution with inorder traversal and constant memory
class Solution {
    bool isValidBST(TreeNode* root, long& curr)
    {
        if(root == nullptr)
            return true;
        
        if(isValidBST(root->left, curr))
        {
            if(curr >= root->val)
                return false;
            
            curr = root->val;
            
            return isValidBST(root->right, curr);
        }
        else
            return false;
    }
public:
    bool isValidBST(TreeNode* root) {
        long curr = LONG_MIN;
        return isValidBST(root, curr);
    }
};