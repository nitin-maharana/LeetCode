/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    bool isVowel(char c)
    {
        switch(c)
        {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U': return true;
            default: return false;
        }
    }
    
    string reverseVowels(string s) {
        int l, r;
        
        l = 0;
        r = s.length()-1;
        
        while(l < r)
        {
            if(!isVowel(s[l]))
                l++;
            else if(!isVowel(s[r]))
                r--;
            else
                swap(s[l++], s[r--]);
        }
        
        return s;
    }
};