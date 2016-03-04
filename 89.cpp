/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    vector<int> grayCode(int n) {
        int len = 1 << n;
        
        vector<int> result(len);
        
        if(!n)
            return result;
        
        bitset<32> memory;
        
        result[0] = memory.to_ulong();
        
        for(int i = 1; i < len; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if((i % (1 << j+1)) == (1<<j))
                {
                    memory.flip(j);
                    break;
                }
            }
            
            result[i] = memory.to_ullong();
        }
        
        return result;
    }
};