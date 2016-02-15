/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        int count = 1;
        
        for(int i = s.length()-1; i >= 0; i--, count *= 26)
            result += ((s[i]-'A'+1)*count);
        
        return result;
    }
};
