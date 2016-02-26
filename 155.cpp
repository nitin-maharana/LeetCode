/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class MinStack {
    stack<int> actualStack;
    stack<int> minStack;
public:
    void push(int x) {
        actualStack.push(x);
        
        if(minStack.empty())
            minStack.push(x);
        else if(x <= minStack.top())
            minStack.push(x);
    }

    void pop() {
        if(minStack.top() == actualStack.top())
            minStack.pop();
        
        actualStack.pop();
    }

    int top() {
        return actualStack.top();
    }

    int getMin() {
        return minStack.top();
    }
};