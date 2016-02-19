/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        int i;
        
        for(i = len-1; i >= 0; i--)
        {
            if(digits[i] == 9)
                digits[i] = 0;
            else
            {
                digits[i]++;
                break;
            }
        }
        
        if(i == -1)
            digits.insert(digits.begin(), 1);

        return digits;
    }
};