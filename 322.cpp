/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

//Recursion
class Solution {
    int *memory;

    int coinChangeUtil(vector<int>& coins, int amount) {
        if(amount == 0)
            return 0;
        
        if(memory[amount] != -1)
            return memory[amount];
        
        int count = INT_MAX, temp;

        for(int i = 0; i < coins.size(); i++)
        {
            if(coins[i] <= amount)
            {
                temp = coinChangeUtil(coins, amount-coins[i]);
                
                if(temp == INT_MAX)
                    continue;
                
                count = min(count, 1+temp);
            }
        }
        
        memory[amount] = count;
        
        return count;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
            
        memory = new int[amount+1];
        
        for(int i = 0; i <= amount; i++)
            memory[i] = -1;
        
        int count = coinChangeUtil(coins, amount);
        
        return (count == INT_MAX) ? -1 : count;
    }
};