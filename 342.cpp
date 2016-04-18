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

class Solution {
public:
    bool isPowerOfFour(int num) {
        return (num > 0 && (num & (num-1)) == 0 && (num & 0xAAAAAAAA) == 0);
    }
};

class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num <= 0)
            return false;
        
        if(num == 1)
            return true;

        double temp = log(num) / log(4);
        
        return (temp == (int)temp);
    }
};