/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    int reverse(int x) {
        long result = 0l;

        while(x)
        {
            result = result*10l + (x%10);
            x /= 10;
        }
        
        if(result > INT_MAX || result < INT_MIN)
            return 0;
            
        return (int)result;
    }
};
