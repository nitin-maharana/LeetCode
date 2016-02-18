/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */
 
class Queue {
    stack<int> s1, s2;
public:
    // Push element x to the back of queue.
    void push(int x) {
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        
        s1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if(empty())
            return;
            
        peek();
        
        s2.pop();
    }

    // Get the front element.
    int peek(void) {
        if(!s2.empty())
            return s2.top();
            
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        
        return s2.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return (s1.empty() && s2.empty());
    }
};
