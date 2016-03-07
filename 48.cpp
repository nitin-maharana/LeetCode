/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int level = n/2;
        int temp, r;

        for(int l = 0; l < level; l++)
        {
            r = n-1-l;

            for(int i = l; i < r; i++)
            {
                temp = matrix[l][i];

                matrix[l][i] = matrix[r-(i-l)][l];
                matrix[r-(i-l)][l] =  matrix[r][r-(i-l)];
                matrix[r][r-(i-l)] = matrix[i][r];
                matrix[i][r] = temp;
            }
        }
    }
};