/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    bool isValid(string s) {
        stack<char> memory;
        char temp;
        
        for(char c: s)
        {
            if(c == '(' || c == '{' || c == '[')
                memory.push(c);
            else if(c == ')' || c == '}' || c == ']')
            {
                if(memory.empty())
                    return false;
                
                temp = memory.top();
                memory.pop();
                
                if(!((temp == '(' && c == ')') || (temp == '{' && c == '}') || (temp == '[' && c == ']')))
                    return false;
            }
        }
        
        if(memory.empty())
            return true;
        else
            return false;
    }
};