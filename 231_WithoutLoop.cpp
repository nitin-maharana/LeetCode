/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */
 
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0)
            return false;
            
        return ((n &(n-1)) == 0);
    }
};
