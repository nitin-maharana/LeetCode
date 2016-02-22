/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.length();
        int result = 0;
        
        len--;
        
        while(len >= 0)
        {
            if(s[len] != ' ')
                break;
            len--;
        }
        
        while(len >= 0)
        {
            if(s[len--] == ' ')
                break;
            else
                result++;
        }
        
        return result;
    }
};