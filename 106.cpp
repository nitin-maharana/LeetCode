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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int l, int r, int i)
    {
        if(l > r || i < 0)
            return NULL;
        
        int found = -1;
        
        for(int j = l; j <= r; j++)
        {
            if(inorder[j] == postorder[i])
            {
                found = j;
                break;
            }
        }
        
        if(found == -1)
            return buildTree(inorder, postorder, l, r, i-1);
        
        TreeNode* head;
        
        head = new TreeNode(postorder[i]);
        
        head->left = buildTree(inorder, postorder, l, found-1, i-1);
        
        head->right = buildTree(inorder, postorder, found+1, r, i-1);
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, postorder, 0, inorder.size()-1, postorder.size()-1);
    }
};