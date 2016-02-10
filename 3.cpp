/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int repeatCharacter, maximum;
        int len = s.length();
        
        int memory[256];
        
        memset(memory, -1, sizeof(memory));
        
        repeatCharacter = maximum = 0;
        
        for(int i = 0; i < len; i++)
        {
            if(memory[s[i]] != -1)
                repeatCharacter = (memory[s[i]] >= repeatCharacter) ? (memory[s[i]] + 1) : repeatCharacter;

            memory[s[i]] = i;
            
            if((i - repeatCharacter + 1) > maximum)
                maximum = (i - repeatCharacter + 1);
        }
        
        return maximum;
    }
};