/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

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
