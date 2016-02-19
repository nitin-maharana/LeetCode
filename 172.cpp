/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    int trailingZeroes1(int n) {
        int numZeros = 0;
        
        while(n)
        {
            numZeros += (n/5);
            n /= 5;
        }
        
        return numZeros;
    }

    int trailingZeroes(int n) {
        int numZeros = 0;
        
        for(long i = 5; i <= n; i *= 5)
            numZeros += (n/i);
        
        return numZeros;
    }
};

