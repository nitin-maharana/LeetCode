/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    int numSquares(int n) {
        if(n <= 0)
            return 0;

        unsigned int memory[n+1];
        memory[0] = 0;
        unsigned int count;
        
        for(int i = 1; i <= n; i++)
        {
            count = i;
            
            for(int j = 1; j*j <= i; j++)
                count = min(memory[i-j*j]+1, count);
            
            memory[i] = count;
        }
        
        return memory[n];
    }
};