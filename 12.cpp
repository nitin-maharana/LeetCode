/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    string convertToRoman(int num, int pos)
    {
        if(!num)
            return "";
            
        string c1, c2, c3;
        
        switch(pos)
        {
            case 1: c1 = 'I';
                    c2 = 'V';
                    c3 = 'X';
                    break;
            case 2: c1 = 'X';
                    c2 = 'L';
                    c3 = 'C';
                    break;
            case 3: c1 = 'C';
                    c2 = 'D';
                    c3 = 'M';
                    break;
            case 4: c1 = 'M';
                    break;
        }
        
        switch(num)
        {
            case 1: return c1;
            case 2: return c1 + c1;
            case 3: return c1 + c1 + c1;
            case 4: return c1 + c2;
            case 5: return c2;
            case 6: return c2 + c1;
            case 7: return c2 + c1 + c1;
            case 8: return c2 + c1 + c1 + c1;
            case 9: return c1 + c3;
        }
            
        
    }
    
    string intToRoman(int num) {
        return convertToRoman(num/1000, 4) + convertToRoman((num/100)%10, 3) + convertToRoman((num/10)%10, 2) + convertToRoman(num%10, 1);
    }
};
