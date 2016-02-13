/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if(strs.empty())
            return "";
        
        sort(strs.begin(), strs.end());
        
        string result = "";
        
        string first = strs[0];
        string last = strs[strs.size()-1];
        
        for(int i = 0; i < first.length() && i < last.length(); i++)
        {
            if(first[i] == last[i])
                result += first[i];
            else
                break;
        }
        
        return result;
    }
};