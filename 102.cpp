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
    queue<TreeNode*> q1, q2;
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        
        if(!root)
            return result;


        q1.push(root);
            
        vector<int> temp;
        TreeNode *ptr;
        bool alternate = true;
        
        while(!q1.empty() || !q2.empty())
        {
            temp.clear();
            
            if(alternate)
            {
                while(!q1.empty())
                {
                    ptr = q1.front();
                    temp.push_back(ptr->val);
                    
                    if(ptr->left)
                        q2.push(ptr->left);
                        
                    if(ptr->right)
                        q2.push(ptr->right);
                    
                    q1.pop();
                }
            }
            else
            {
                while(!q2.empty())
                {
                    ptr = q2.front();
                    temp.push_back(ptr->val);
                    
                    if(ptr->left)
                        q1.push(ptr->left);
                        
                    if(ptr->right)
                        q1.push(ptr->right);
                    
                    q2.pop();
                }
            }
            
            result.push_back(temp);
            alternate = !alternate;
        }
        
        return result;
    }
};