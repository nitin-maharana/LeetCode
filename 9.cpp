/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x < 0)
            return false;
            
        int len = 0;
        int tempNum = x;
        int l, r;
        
        while(tempNum)
        {
            len++;
            tempNum /= 10;
        }
        
        for(int i = pow(10, len-1); i > 1; i /= 100)
        {
            l = x % 10;
            r = x / i;
            
            if(l != r)
                return false;
                
            x -= (i*r);
            x /= 10;
        }
        
        return true;
    }
};
