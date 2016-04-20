/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

//Recursion
class Solution {
    int integerBreak(int n, int *memory)
    {
        if(n < 4)
            return n-1;

        if(memory[n])
            return memory[n];

        int result = 0;

        for(int i = 1; i <= n/2; i++)
            result = max(result, max(i, integerBreak(i, memory)) * max(n-i, integerBreak(n-i, memory)));

        memory[n] = result;

        return result;
    }
public:
    int integerBreak(int n) {
        int memory[n+1];

        memset(memory, 0, sizeof memory);

        return integerBreak(n, memory);
    }
};