/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size() == 0)
            return 0;

        vector<int> result(triangle.size(), 0);

        result = triangle[triangle.size()-1];

        for(int i = triangle.size()-2; i >= 0; i--)
            for(int j = 0; j <= i; j++)
                result[j] = triangle[i][j] + min(result[j], (j+1 <= i+1) ? result[j+1] : INT_MAX);

        return result[0];
    }
};