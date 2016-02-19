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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        int level = 0;
        
        if(!root)
            return result;
            
        q1.push(root);
        vector<int> tempRes;
        
        TreeNode *tempPtr;
        
        while(!q1.empty() || !q2.empty())
        {
            tempRes.clear();
            
            if(level % 2)
            {
                while(!q2.empty())
                {
                    tempPtr = q2.front();
                    tempRes.push_back(tempPtr->val);
                    if(tempPtr->left)
                        q1.push(tempPtr->left);
                    
                    if(tempPtr->right)
                        q1.push(tempPtr->right);
                        
                    q2.pop();
                }
            }
            else
            {
                while(!q1.empty())
                {
                    tempPtr = q1.front();
                    tempRes.push_back(tempPtr->val);
                    if(tempPtr->left)
                        q2.push(tempPtr->left);
                    
                    if(tempPtr->right)
                        q2.push(tempPtr->right);
                        
                    q1.pop();
                }
            }
            
            level++;
            result.push_back(tempRes);
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
};