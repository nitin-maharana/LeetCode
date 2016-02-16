/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    bool isUgly(int num) {
        if(num < 1)
            return false;
            
        for(int i: {2,3,5})
            while(num % i == 0)
                num /= i;

        return (num == 1);
    }
};
