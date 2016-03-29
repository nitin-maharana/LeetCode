/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

//Solution - 1
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        while(m < n)
            n &= n-1;
            
        return n;
    }
};

//Solution - 2
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        long count = 1;
        int result = m;

        while(count < n-m+1)
        {
            result &= (~count);
            count <<= 1;
        }

        result &= n;
        
        return result;
    }
};