/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
    set<int> memory;
public:
    int findSquare(int n)
    {
        int result = 0, tempRes;
        
        while(n)
        {
            tempRes = n % 10;
            result += (tempRes*tempRes);
            n /= 10;
        }
        
        return result;
    }
    
    bool isHappy(int n) {
        if(n == 1)
            return true;
            
        memory.insert(n);
        
        while(n != 1)
        {
            n = findSquare(n);
            
            if(memory.find(n) != memory.end())
                break;
            
            memory.insert(n);
        }
        
        return (n==1);
    }
};
