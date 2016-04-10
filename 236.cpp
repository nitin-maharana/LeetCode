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
//Solution [Assuming both nodes are present]
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q)
            return root;

        TreeNode *left, *right;
        
        left = lowestCommonAncestor(root->left, p, q);
        right = lowestCommonAncestor(root->right, p, q);
        
        if(left && right)
            return root;
        
        return (left ? left : right);
    }
};

//Solution [With no such assumption] [If any of the node is not present, returns NULL]
class Solution {
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q, bool& p1, bool& q1)
    {
        if(root == NULL)
            return NULL;

        TreeNode *left, *right;
        
        if(root == p)
        {
            p1 = true;
            return root;
        }
        
        if(root == q)
        {
            q1 = true;
            return root;
        }
        
        left = lowestCommonAncestor(root->left, p, q, p1, q1);
        right = lowestCommonAncestor(root->right, p, q, p1, q1);
        
        if(left && right)
            return root;

        return (left ? left : right);
    }
    
    TreeNode* findAnother(TreeNode *root, TreeNode *n)
    {
        if(root == NULL)
            return NULL;
        
        if(root == n)
            return root;
        
        TreeNode *left, *right;
        left = findAnother(root->left, n);
        
        if(left)
            return left;
            
        right = findAnother(root->right, n);
        
        return right;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return NULL;
        
        bool p1 = false, q1 = false;
        
        TreeNode *lca = lowestCommonAncestor(root, p, q, p1, q1);
        
        if((p1 && q1) || (p1 && findAnother(lca, q)) || (q1 && findAnother(lca, p)))
            return lca;
        else
            return NULL;
    }
};

//Solution [With no such assumption] [If any of the node is not present, returns NULL] - Optimal one
struct Result {
    TreeNode *node;
    bool isAncestor;
    Result(TreeNode* n, bool isAnc) : node(n), isAncestor(isAnc) {}
};

class Solution {
    TreeNode* findLCA(TreeNode* root, TreeNode* f)
    {
        if(root == NULL || root == f)
            return root;
        
        TreeNode* l = findLCA(root->left, f);
        
        if(l)
            return l;
        
        return findLCA(root->right, f);
    }

    Result* findLCA(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root == NULL)
            return new Result(root, false);
        
        if(root == p)
        {
            TreeNode* res = findLCA(root, q);
            
            return new Result(root, res != NULL);
        }
        
        if(root == q)
        {
            TreeNode* res = findLCA(root, p);
            
            return new Result(root, res != NULL);
        }
        
        Result *l = findLCA(root->left, p, q);
        
        if(l->isAncestor)
            return l;
        
        Result *r = findLCA(root->right, p, q);
        
        if(r->isAncestor)
            return r;
        
        if(l->node && r->node)
            return new Result(root, true);
        
        return new Result(l->node ? l->node : r->node, false);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        Result *res = findLCA(root, p, q);
        
        if(res->isAncestor)
            return res->node;
        
        return NULL;
    }
};