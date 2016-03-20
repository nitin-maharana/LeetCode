/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num+1, 0);

        int i = 0;

        result[i++] = 0;

        if(num == 0)
            return result;

        result[i++] = 1;

        if(num == 1)
            return result;

        int range;

        while(i <= num)
        {
            range = i;

            for(int j = 0; j < range && i <= num; j++)
                result[i++] = 1 + result[j];
        }

        return result;
    }
};