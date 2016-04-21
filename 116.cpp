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
        if(root == nullptr)
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
        if(root == nullptr)
            return;
        
        if(root->left)
            root->left->next = root->right;
        
        if(root->next && root->right)
            root->right->next = root->next->left;
        
        connect(root->left);
        connect(root->right);
    }
};

//One More Recursive Solution - Works for any tree. O(N) - Time, O(H) - Space (Except Recursion Stack).
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

//One More Iterative Solution - Works for any tree. Time - O(N), Space - O(1).
class Solution {
    TreeLinkNode* getNext(TreeLinkNode *root)
    {
        root = root->next;
        
        while(root)
        {
            if(root->left)
                return root->left;
            
            if(root->right)
                return root->right;
            
            root = root->next;
        }
        
        return nullptr;
    }
public:
    void connect(TreeLinkNode *root) {
        if(root == nullptr)
            return;
        
        root->next = nullptr;
        
        TreeLinkNode *ptr1, *ptr2;
        
        ptr1 = root;
        
        while(ptr1)
        {
            ptr2 = ptr1;
            
            while(ptr2)
            {
                if(ptr2->left)
                {
                    if(ptr2->right)
                        ptr2->left->next = ptr2->right;
                    else
                        ptr2->left->next = getNext(ptr2);
                }
                
                if(ptr2->right)
                    ptr2->right->next = getNext(ptr2);
                
                ptr2 = ptr2->next;
            }
            
            if(ptr1->left)
                ptr1 = ptr1->left;
            else if(ptr1->right)
                ptr1 = ptr1->right;
            else
                ptr1 = getNext(ptr1);
        }
        
        return;
    }
};

/*
 * One More Recursive Solution - Works for any tree. Time - O(N), Space - O(1) [Except Recursion Stack].
 * For some input, It would be TLE, as the problem assumes complete binary tree, it expects to be run on less time.
 * As this does more work even for complete tree or any tree. So TLE.
 */
class Solution {
    TreeLinkNode* getNext(TreeLinkNode *root)
    {
        root = root->next;
        
        while(root)
        {
            if(root->left)
                return root->left;
            
            if(root->right)
                return root->right;
            
            root = root->next;
        }
        
        return nullptr;
    }
    
    void connectUtil(TreeLinkNode *root)
    {
        if(root == nullptr)
            return;
        
        if(root->left)
        {
            if(root->right)
                root->left->next = root->right;
            else
                root->left->next = getNext(root);
        }
        
        if(root->right)
            root->right->next = getNext(root);
        
        connectUtil(root->next);
        connectUtil(root->left);
        connectUtil(root->right);
        
        return;
    }
public:
    void connect(TreeLinkNode *root) {
        if(root == nullptr)
            return;
        
        root->next = nullptr;
        
        connectUtil(root);
        
        return;
    }
};