/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    bool isPowerOfThree(int n) {
        double rem = log10(n)/log10(3);
        return ((rem - (int)rem) == 0);
    }
};
