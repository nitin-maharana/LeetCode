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
    queue<TreeNode*> q1, q2;
public:
    bool isSymmetric(TreeNode *l, TreeNode *r)
    {
        q1.push(l);
        q2.push(r);
        
        TreeNode *l1, *h1;
        
        while(!q1.empty() && !q2.empty())
        {
            l1 = q1.front();
            h1 = q2.front();
            
            q1.pop();
            q2.pop();
            
            if(!l1 && !h1)
                continue;
                
            if(!l1 || !h1 || (l1->val != h1->val))
                return false;
                
            q1.push(l1->left);
            q1.push(l1->right);
            
            q2.push(h1->right);
            q2.push(h1->left);
        }
        
        return true;
    }

    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        
        return isSymmetric(root->left, root->right);
    }
};

//Recursive Solution.
class Solution {
public:
    bool isSymmetric(TreeNode* l, TreeNode* r)
    {
        if(!l && !r)
            return true;
            
        if((!l || !r || (l->val != r->val))
            return false;
            
        return (isSymmetric(l->left, r->right) && isSymmetric(l->right, r->left));
    }

    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
            
        return isSymmetric(root->left, root->right);
    }
};