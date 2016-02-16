/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    int climbStairs(int n) {
        if(n < 4)
            return n;
            
        int prev, prevToPrev, swapVar;
        
        prevToPrev = 2;
        prev = 3;
        
        for(int i = 4; i <= n; i++)
        {
            swapVar = prev;
            prev = prevToPrev + prev;
            prevToPrev = swapVar;
        }
        
        return prev;
    }
};
