/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        int len;
        
        result.push_back(1);
        
        for(int i = 1; i <= rowIndex; i++)
        {
            len = result.size();
            
            for(int i = 0; i < len-1; i++)
                result[i] = result[i] + result[i+1];
                
            result[len-1] = 1;
            result.insert(result.begin(), 1);
        }
        
        return result;
    }
};