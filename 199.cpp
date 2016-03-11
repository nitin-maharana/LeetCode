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

//Iterative Solution - 2-Queue method.
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        
        if(root == NULL)
            return result;
        
        queue<TreeNode*> memory1, memory2;
        TreeNode *last;
        
        memory1.push(root);
        
        while(!memory1.empty() || !memory2.empty())
        {
            if(!memory1.empty())
            {
                while(!memory1.empty())
                {
                    last = memory1.front();
                    memory1.pop();
                    
                    if(last->left)
                        memory2.push(last->left);
                    
                    if(last->right)
                        memory2.push(last->right);
                }
            }
            else
            {
                while(!memory2.empty())
                {
                    last = memory2.front();
                    memory2.pop();
                    
                    if(last->left)
                        memory1.push(last->left);
                    
                    if(last->right)
                        memory1.push(last->right);
                }
            }
            
            result.push_back(last->val);
        }
        
        return result;
    }
};

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