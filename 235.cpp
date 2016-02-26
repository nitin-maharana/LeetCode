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

//Recursive Solution.
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return root;
            
        if((root->val >= p->val && root->val <= q->val) || (root->val >= q->val && root->val <= p->val))
            return root;
            
        if(root->val < p->val || root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);
        else
            return lowestCommonAncestor(root->left, p, q);
    }
};
