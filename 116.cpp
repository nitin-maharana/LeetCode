/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

//Iterative Solution.
class Solution {
    queue<TreeLinkNode*> memory;
public:
    void connect(TreeLinkNode *root) {
        if(!root)
            return;

        memory.push(root);
        
        TreeLinkNode *front;
        
        while(!memory.empty())
        {
            front = memory.front();
            memory.pop();
            
            if(front->left)
            {
                front->left->next = front->right;
                memory.push(front->left);
            }
            
            if(front->next && front->right)
                front->right->next = front->next->left;
            
            if(front->right)
                memory.push(front->right);
        }
    }
};

//Recursive Solution.
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root)
            return;
        
        if(root->left)
            root->left->next = root->right;
        
        if(root->next && root->right)
            root->right->next = root->next->left;
        
        connect(root->left);
        connect(root->right);
    }
};

//One More Recursive Solution.
class Solution {
    void connect(TreeLinkNode* root, unordered_map<int, TreeLinkNode*>& memory, int level)
    {
        if(root == nullptr)
            return;
        
        if(memory.find(level) != memory.end())
            memory[level]->next = root;

        memory[level] = root;
        
        connect(root->left, memory, level+1);
        connect(root->right, memory, level+1);
        
        return;
    }
public:
    void connect(TreeLinkNode *root) {
        if(root == nullptr)
            return;
        
        unordered_map<int, TreeLinkNode*> memory;
        connect(root, memory, 0);
        
        return;
    }
};