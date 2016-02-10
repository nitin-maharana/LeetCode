/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

 class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.length();
    
        if(len == 0 || numRows == 1)
            return s;
    
        string result = "";
    
        for(int i = 0; i < numRows; i++)
        {
            if(i < len)
    	        result += s[i];
    	    else
    	        break;

    	    int j = i;

    	    while(j < len)
    	    {
    		    if(i != numRows-1)
    		    {
    			    j = j + (numRows-i-1)*2;
    			
    			    if(j < len)
    			        result += s[j];
    			    else
    			        break;
    		    }

			    if(i != 0)
			    {
				    j = j + i*2;
				
				    if(j < len)
				        result += s[j];
			        else
			            break;
			    }
    	    }
        }
    
        return result;
    }
};