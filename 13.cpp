/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> memory;
        
        memory['I'] = 1;
        memory['V'] = 5;
        memory['X'] = 10;
        memory['L'] = 50;
        memory['C'] = 100;
        memory['D'] = 500;
        memory['M'] = 1000;
        
        int result = 0;
        int len = s.length();
        
        for(int i = 0; i < len; i++)
        {
            if(i+1 < len)
            {
                if(memory[s[i]] < memory[s[i+1]])
                {
                    result += (memory[s[i+1]] - memory[s[i]]);
                    i++;
                    continue;
                }
            }
            
            result += memory[s[i]];
        }
        
        return result;
    }
};
