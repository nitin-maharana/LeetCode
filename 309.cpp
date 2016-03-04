/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;

        int buy, s1, s2;
        
        buy = INT_MIN;
        s1 = s2 = 0;
        
        for(int i = 0; i < prices.size(); i++)
        {
            buy = max(buy, s2-prices[i]);
            s2 = s1;
            s1 = max(s1, buy+prices[i]);
        }
        
        return s1;
    }
};