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
    void pathSum(TreeNode* root, vector<vector<int>>& result, vector<int>& tempResult, int& sum, int&  tempSum)
    {
        tempSum += root->val;
        tempResult.push_back(root->val);
        
        if(root->left == NULL && root->right == NULL && tempSum == sum)
        {
            result.push_back(tempResult);
            tempSum -= root->val;
            tempResult.pop_back();
            return;
        }
        
        if(root->left)
            pathSum(root->left, result, tempResult, sum, tempSum);
        
        if(root->right)
            pathSum(root->right, result, tempResult, sum, tempSum);
        
        tempSum -= root->val;
        tempResult.pop_back();
        return;    
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> tempResult;
        int tempSum = 0;
        
        if(root == NULL)
            return result;
        
        pathSum(root, result, tempResult, sum, tempSum);
        
        return result;
    }
};