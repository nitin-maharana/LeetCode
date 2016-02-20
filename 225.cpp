/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Stack {
    queue<int> q;
public:
    // Push element x onto stack.
    void push(int x) {
        q.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        int len = q.size();
        
        len--;
        
        while(len--)
        {
            q.push(q.front());
            q.pop();
        }
        
        q.pop();
    }

    // Get the top element.
    int top() {
        return q.back();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
};