/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
    string number;
    
    void countAndSay(void)
    {
        string tempRes;
        char currnum;
        int count;
        
        tempRes = "";
        currnum = number[0];
        count = 0;
        
        for(int i = 0; i < number.length(); i++)
        {
            if(number[i] == currnum)
                count++;
            else
            {
                tempRes += to_string(count);
                tempRes += currnum;
                
                count = 1;
                currnum = number[i];
            }
        }
        
        tempRes += to_string(count);
        tempRes += currnum;
        
        number = tempRes;
    }
public:
    string countAndSay(int n) {
        if(!n)
            return number;
            
        number = "1";
        number.reserve(1024);
        
        for(int i = 2; i <= n; i++)
            countAndSay();
            
        return number;
    }
};