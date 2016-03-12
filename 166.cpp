class Solution {
    /*
     * Converts integer to string.
     */
    string intToString(long num)
    {
        string result = "";

        while(num)
        {
            result += (char)((num % 10) + '0');
            num /= 10;
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
    
    /*
     * Make both numbers positive.
     * Returns the positive or negative sign.
     * Depends on the result.
     */
    string processTheNumbers(long& n, long& d)
    {
        long prod;
        
        prod = n * d;
        
        n = abs(n);
        d = abs(d);
        
        if(prod < 0l)
            return "-";
        else
            return "";
    }
    
    /*
     * Checks for repetition of fractional part using memory (stores the value itself)
     */
    string fractionPart(long n, long d)
    {
        vector<long> memory;
        string result = "";
        
        while(n)
        {
            int i = 0;
            
            for(i = 0; i < memory.size(); i++)
                if(memory[i] == n)
                    break;

            if(i != memory.size())
            {
                result.insert(i, "(");
                result += ')';
                break;
            }
            
            result += (char)((n / d) + '0');
            
            memory.push_back(n);
            
            n = (n % d) * 10;
        }
        
        return result;
    }
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0 || denominator == 0)
            return "0";

        //Conversion is done to handle the INT_MIN case to make positive. (Out of Range)
        long n = numerator, d = denominator;
        
        string result = "";
        result += processTheNumbers(n, d);
        
        if((n % d) == 0)
            return (result + intToString(n/d));
        
        if(n > d)
        {
            result += intToString(n/d);
            result += '.';
            n = n % d;
        }
        else
            result += "0.";

        n = n * 10;
        
        result += fractionPart(n, d);

        return result;
    }
};
