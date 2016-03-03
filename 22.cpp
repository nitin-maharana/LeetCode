/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
    vector<string> result;
    
    void generateParenthesis(int n, int left, int right, int index, string& tempResult)
    {
        if(!left && !right)
            result.push_back(tempResult);
        
        if(left)
        {
            tempResult[index] = '(';
            generateParenthesis(n, left-1, right, index+1, tempResult);
        }
        
        if(right > left)
        {
            tempResult[index] = ')';
            generateParenthesis(n, left, right-1, index+1, tempResult);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        string tempResult(2*n, 'X');
        generateParenthesis(n, n, n, 0, tempResult);
        
        return result;
    }
};