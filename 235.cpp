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
        mx = max(p->val, q->val);
        
        while(root)
        {
            if(root->val < mn)
                root = root->right;
            else if(root->val > mx)
                root = root->left;
            else
                return root;
        }
    }
};

//Recursive Solution.
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root == q)
            return root;
            
        if(root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);
        
        if(root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        
        return root;
    }
};

//Recursive Solution. It doesn't assume anything. If any node is not present, returns NULL.
//As well as no need to be distinct nodes.
class Solution {
    TreeNode* lcaUtil(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root == nullptr || root == p || root == q)
            return root;
        
        if(root->val < p->val && root->val < q->val)
            return lcaUtil(root->right, p, q);
        
        if(root->val > p->val && root->val > q->val)
            return lcaUtil(root->left, p, q);
        
        return root;
    }
    
    TreeNode* findNode(TreeNode* root, TreeNode* n)
    {
        if(root == nullptr || root == n)
            return root;
        
        if(root->val < n->val)
            return findNode(root->right, n);
        else
            return findNode(root->left, n);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || root == p || root == q)
            return root;
        
        TreeNode *lca = lcaUtil(root, p, q);
        
        if(findNode(lca, p) && findNode(lca, q))
            return lca;
        
        return NULL;
    }
};
