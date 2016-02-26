/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

//Iterative Solution - Fibonacci.
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

//Recursive Solution - DP.
class Solution {
    map<int, int> memory;
    map<int, int>::iterator it;
public:
    int climbStairs(int n) {
        if(n <= 0)
            return 1;
            
        it = memory.find(n);
        
        if(it != memory.end())
            return it->second;
            
        int result;
        
        result = climbStairs(n-1);
        
        if(n >= 2)
            result += climbStairs(n-2);
            
        memory.insert(make_pair(n, result));
            
        return result;
    }
};
