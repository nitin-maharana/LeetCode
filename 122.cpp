/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(!prices.size())
            return 0;
            
        for(int i = 0; i < prices.size()-1; i++)
            prices[i] = prices[i+1] - prices[i];
        
        prices.pop_back();
        
        int profit, maximum, maxSoFar;
        
        profit = maximum = maxSoFar = 0;
        
        for(int i = 0; i < prices.size(); i++)
        {
            maxSoFar += prices[i];
            
            if(maxSoFar > maximum)
                maximum = maxSoFar;
            else
            {
                profit += maximum;
                maxSoFar = (prices[i] < 0) ? 0 : prices[i];
                maximum = maxSoFar;
            }
        }
        
        profit += maximum;
        
        return profit;
    }
};