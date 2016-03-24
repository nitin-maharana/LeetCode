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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& preorder, int l, int r, int i)
    {
        if(l > r || i >= preorder.size())
            return NULL;
        
        int found;
        
        for(int j = l; j <= r; j++)
        {
            if(inorder[j] == preorder[i])
            {
                found = j;
                break;
            }
        }
        
        TreeNode* head;
        
        head = new TreeNode(preorder[i]);
        
        head->left = buildTree(inorder, preorder, l, found-1, i+1);
        
        head->right = buildTree(inorder, preorder, found+1, r, i+1+found-l);
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(inorder, preorder, 0, inorder.size()-1, 0);
    }
};