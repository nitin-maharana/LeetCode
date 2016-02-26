/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

//Using Loop.
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n == 0)
            return false;
            
        while(n%3 == 0)
            n /= 3;
        
        return (n==1);
    }
};

//Without using Loop.
class Solution {
public:
    bool isPowerOfThree(int n) {
        double rem = log10(n)/log10(3);
        return ((rem - (int)rem) == 0);
    }
};

//Recursive Solution.
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n == 0)
            return false;
        if(n == 1)
            return true;
        if(n % 3)
            return false;
            
        return isPowerOfThree(n/3);
    }
};