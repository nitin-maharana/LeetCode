/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
    void reverseWordWise(string& s)
    {
        int i1, i2, len;
        
        i1 = i2 = 0;
        len = s.length();
        
        while(i1 < len && i2 < len)
        {
            while(i1 < len)
            {
                if(s[i1] != ' ')
                    break;
                i1++;
            }
            
            i2 = i1;
            
            while(i2 < len)
            {
                if(s[i2] == ' ')
                    break;
                i2++;
            }

            reverse(s.begin()+i1, s.begin()+i2);
            
            i1 = i2;
        }
    }

    void removeRightSpaces(string& s)
    {
    	int i;

    	i = s.length()-1;

    	while(i >= 0)
    	{
    		if(s[i] != ' ')
    			break;
    		i--;
    	}

    	i++;

    	if(i < s.length())
    		s.erase(s.begin()+i, s.end());
    }

    void removeSpaceBetweenWords(string& s)
    {
    	int vacantIndex = 0;
    	bool repeat = false;

    	for(int i = 0; i < s.length(); i++)
    	{
    		if(s[i] != ' ')
    		{
				s[vacantIndex++] = s[i];
				repeat = false;
			}
    		else
    		{
    			if(repeat == false)
    			{
    				s[vacantIndex++] = s[i];
    				repeat = true;
    			}
    		}
    	}

    	s.erase(s.begin()+vacantIndex, s.end());
    }
public:
    void reverseWords(string &s) {
    	removeRightSpaces(s);

        reverse(s.begin(), s.end());

        removeRightSpaces(s);
        
        reverseWordWise(s);

        removeSpaceBetweenWords(s);
    }
};

//Using STL
class Solution {
public:
    void reverseWords(string &s) {

    	reverse(s.begin(), s.end());

    	size_t wordLeft, wordRight, len;
    	
    	wordLeft = wordRight = len = 0;
    	
    	wordLeft = s.find_first_not_of(" ", 0);
    	
    	while(wordLeft != string::npos)
    	{
    	    wordRight = s.find(" ", wordLeft);
    	    
    	    if(wordRight == string::npos)
    	        wordRight = s.length();
    	    
    	    reverse(s.begin()+wordLeft, s.begin()+wordRight);
    	    
    	    move(s.begin()+wordLeft, s.begin()+wordRight, s.begin()+len);
    	    
    	    len = len + (wordRight - wordLeft);
    	    s[len++] = ' ';
    	    
    	    wordLeft = s.find_first_not_of(" ", wordRight);
    	}
    	
    	if(len)
    		s.erase(s.begin()+len-1, s.end());
    	else
    	    s = "";
    }
};
