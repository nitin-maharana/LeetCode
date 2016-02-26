/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
    int len;
public:
    bool isPalindrome(string s) {
        len = s.length();
        
        int l, r;
        
        l = 0;
        r = len - 1;
        
        while(l < r)
        {
            if(isalnum(s[l]) && isalnum(s[r]))
            {
                if(tolower(s[l]) == tolower(s[r]))
                {
                    l++;
                    r--;
                    continue;
                }
                else
                    return false;
            }
            
            if(!isalnum(s[l]))
                l++;
            
            if(!isalnum(s[r]))
                r--;
        }
        
        return true;
    }
};