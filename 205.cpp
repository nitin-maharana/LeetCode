/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
    int len;
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length())
            return false;
        
        char smemory[256], tmemory[256];
        len = s.length();
        
        memset(smemory, 0, sizeof(smemory));
        memset(tmemory, 0, sizeof(tmemory));
        
        for(int i = 0; i < len; i++)
        {
            if(smemory[s[i]] == 0)
                smemory[s[i]] = t[i];
            else if(smemory[s[i]] != t[i])
                return false;
            
            if(tmemory[t[i]] == 0)
                tmemory[t[i]] = s[i];
            else if(tmemory[t[i]] != s[i])
                return false;
        }
        
        return true;
    }
};