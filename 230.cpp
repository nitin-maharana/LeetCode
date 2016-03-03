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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> memory;
        
        memory.push(root);
        
        while(root || !memory.empty())
        {
            if(root)
            {
                memory.push(root);
                root = root->left;
            }
            else
            {
                root = memory.top();
                memory.pop();
                
                k--;
                if(!k)
                    return root->val;

                root = root->right;
            }
        }
    }
};

//Recursive Solution.
class Solution {
public:
    int kthSmallest(TreeNode* root, int &k) {
        if(!root)
            return 0;
        
        int result;
        
        result = kthSmallest(root->left, k);
        if(!k)
            return result;
        
        k--;
        if(!k)
            return root->val;
        
        return kthSmallest(root->right, k);
    }
};

//One more Recursive Solution.
class Solution {
    TreeNode *result;
    int kthSmallestUtil(TreeNode *root, int k)
    {
        if(!root)
            return 0;
        
        int l, r;
        
        l = kthSmallestUtil(root->left, k);
        
        if(l+1 == k)
            result = root;
        
        r = kthSmallestUtil(root->right, k-l-1);
        
        return l+r+1;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        kthSmallestUtil(root, k);
        return result->val;
    }
};