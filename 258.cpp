/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    int addDigits(int num) {
        if(num%9)
            return num%9;
        
        return (num ? 9 : 0);
    }
};