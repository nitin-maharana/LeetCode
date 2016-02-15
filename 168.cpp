/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    string convertToTitle(int n) {
        string result = "";
        int tempRes;
        
        while(n)
        {
            tempRes = n % 26;
            
            if(tempRes == 0)
                result = 'Z' + result;
            else
                result = (char)('A'+tempRes-1) + result;
                
            n = (tempRes ? (n - tempRes) : (n - 26));
            n /= 26;
        }
        
        return result;
    }
};
