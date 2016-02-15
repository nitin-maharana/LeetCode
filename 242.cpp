/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    bool isAnagram(string s, string t) {
        
        int memory[26];
        int slen, tlen;
        
        slen = s.length();
        tlen = t.length();

        if(slen != tlen)
            return false;
        
        memset(memory, 0, sizeof(memory));
        
        for(int i = 0; i < slen; i++)
            memory[s[i]-'a']++;
            
        for(int i = 0; i < tlen; i++)
            memory[t[i]-'a']--;
            
        for(int i = 0; i < 26; i++)
            if(memory[i])
                return false;
        
        return true;
    }
};
