/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    stack<TreeNode*> memory;
public:
    BSTIterator(TreeNode *root) {
        while(root)
        {
            memory.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !memory.empty();
    }

    /** @return the next smallest number */
    int next() {
        int result;
        TreeNode* temp;
        
        temp = memory.top();
        memory.pop();
        result = temp->val;
        
        temp = temp->right;
        
        while(temp)
        {
            memory.push(temp);
            temp = temp->left;
        }
        
        return result;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */