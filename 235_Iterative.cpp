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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int mn, mx;
        
        mn = min(p->val, q->val);
        mx = p->val + q->val - mn;
        
        while(root)
        {
            if(root->val < mn)
                root = root->right;
            else if(root->val > mx)
                root = root->left;
            else
                return root;
        }
        
        return root;
    }
};
