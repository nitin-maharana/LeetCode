/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
    void letter(vector<string>& result, string& tempResult, string& digits, string *memory, int i, int n)
    {
        if(i == n)
        {
            result.push_back(tempResult);
            return;
        }
        
        for(int j = 0; j < memory[digits[i]-'0'].size(); j++)
        {
            tempResult[i] = memory[digits[i]-'0'][j];
            letter(result, tempResult, digits, memory, i+1, n);
        }
        
        return;
    }
public:
    vector<string> letterCombinations(string digits) {
        string memory[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        vector<string> result;
        string tempResult(digits.size(), '0');
        
        if(digits.size() == 0)
            return result;
        
        letter(result, tempResult, digits, memory, 0, digits.size());
        
        return result;
    }
};