/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    int myAtoi(string str) {
        long result = 0l;
        bool negative;
        int len = str.length();
        
        int i;
        
        for(i = 0; i < len; i++)
            if(str[i] != ' ')
                break;
                
        if(str[i] == '+' || str[i] == '-')
        {
            negative = (str[i] == '-');
            i++;
        }
        else
            negative = false;
            
        while(i < len)
        {
            if(isdigit(str[i]))
            {
                result = result*10l + (str[i] - '0');

                if(result > INT_MAX)
                    break;
            }
            else
                break;
            
            i++;
        }
        
        if(negative)
            result *= -1;
            
        if(result < INT_MIN)
            result = INT_MIN;
            
        if(result > INT_MAX)
            result = INT_MAX;
            
        return (int)result;
    }
};
