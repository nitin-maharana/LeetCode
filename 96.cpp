/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    int numTrees(int n) {
        
        if(!n)
            return 1;
            
        int memory[n+1];
        
        memset(memory, 0, sizeof memory);
        
        memory[0] = 0;
        memory[1] = 1;
        
        for(int i = 2; i <= n; i++)
        {
            memory[i] += (2 * memory[i-1]);
            
            for(int j = 2; j < i; j++)
                memory[i] += (memory[j-1] * memory[i-j]);
        }

        return memory[n];
    }
};