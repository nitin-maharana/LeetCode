/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit, currProfit, currSum;
        
        maxProfit = currProfit = 0;
        
        for(int i = 1; i < prices.size(); i++)
        {
            currProfit += (prices[i] - prices[i-1]);
            
            currProfit = (currProfit < 0) ? 0 : currProfit;
            
            maxProfit = max(maxProfit, currProfit);
        }
        
        return maxProfit;
    }
};