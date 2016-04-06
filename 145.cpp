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

//Using one stack but modifies the input tree.
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;

        if(root == NULL)
            return result;

        stack<TreeNode*> memory;
        TreeNode *curr;

        memory.push(root);

        while(!memory.empty())
        {
            curr = memory.top();

            if(curr->left)
            {
                memory.push(curr->left);
                curr->left = NULL;
            }
            else if(curr->right)
            {
                memory.push(curr->right);
                curr->right = NULL;
            }
            else
            {
                result.push_back(curr->val);
                memory.pop();
            }
        }

        return result;
    }
};