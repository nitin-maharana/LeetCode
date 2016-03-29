/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
    int *memory;
    int numDecodings(string& s, int i)
    {
        if(i == s.length())
            return 1;
        
        if(memory[i] != -1)
            return memory[i];
        
        if(s[i] == '0')
            return 0;
        
        if((s[i] == '1' && i+1 < s.length() && s[i+1] != '0') || (s[i] == '2' && i+1 < s.length() && s[i+1] >= '1' && s[i+1] <= '6'))
        {
            if(i+2 < s.length() && s[i+2] == '0')
            {
                int res = numDecodings(s, i+1);
                memory[i] = res;
                return res;
            }
            
            int res1, res2;
            
            res1 = numDecodings(s, i+1);
            
            if(res1)
                res2 = numDecodings(s, i+2);
            else
                res2 = 0;
            
            memory[i] = res1+res2;
            return memory[i];
        }
        
        if((s[i] == '1' && i+1 < s.length() && s[i+1] == '0') || (s[i] == '2' && i+1 < s.length() && s[i+1] == '0'))
        {
            int res = numDecodings(s, i+2);
            memory[i] = res;
            return res;
        }
        
        int res = numDecodings(s, i+1);
        memory[i] = res;
        return res;
    }
public:
    int numDecodings(string s) {
        if(s.length() == 0)
            return 0;

        memory = new int[s.length()];

        for(int i = 0; i < s.length(); i++)
            memory[i] = -1;

        return numDecodings(s, 0);
    }
};