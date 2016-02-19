/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    int trailingZeroes(int n) {
        int numZeros = 0;
        
        for(long i = 5; i <= n; i *= 5)
            numZeros += (n/i);
        
        return numZeros;
    }
};