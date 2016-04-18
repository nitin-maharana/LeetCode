/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num <= 0 || num & num-1)
            return false;
        
        int temp = (int)log2(num);
        
        if(temp % 2 == 0)
            return true;
        
        return false;
    }
};