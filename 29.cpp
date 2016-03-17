/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
    int divide(long a, long b, bool negative)
    {
        long temp, result, prod;

        result = 0l;
        
        while(a >= b)
        {
            temp = b;
            prod = 1;
            
            while(a >= temp)
            {
                result += prod;
                prod <<= 1;
                
                a -= temp;
                temp <<= 1;
            }
        }
        
        if(negative)
            result = -result;
        
        if(result > INT_MAX)
            return INT_MAX;
        
        return (int)result;
    }
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0)
            return INT_MAX;
        
        bool negative;
        
        negative = ((dividend < 0) && (divisor > 0)) || ((dividend > 0) && (divisor < 0));
        
        return divide(abs((long)dividend), abs((long)divisor), negative);
    }
};