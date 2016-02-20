/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    bool isPalindrome1(int x) {
        if(x < 0)
            return false;
            
        int temp = x;
        int len = 0;
        
        while(temp)
        {
            len++;
            temp /= 10;
        }
        
        int left, right;
        int leftPower = pow(10, len-1);
        int rightPower = 1;
        
        while(leftPower >= rightPower)
        {
            left = (x / leftPower) % 10;
            right = (x / rightPower) % 10;
            
            if(left != right)
                return false;
                
            leftPower /= 10;
            rightPower *= 10;
        }
        
        return true;
    }

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
