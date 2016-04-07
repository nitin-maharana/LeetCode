/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:

    bool isInteger(string& s)
    {
        bool flag = false;
        
        int i;
        
        for(i = 0; i < s.length(); i++)
        {
            if(s[i] == ' ' || s[i] == '\t')
                continue;
            else
                break;
        }
        
        if(s[i] == '-' || s[i] == '+')
            i++;
        
        for(i; i < s.length(); i++)
        {
            if(s[i] >= '0' && s[i] <= '9')
                flag = true;
            else
                break;
        }
                
        for(i; i < s.length(); i++)
        {
            if(s[i] == ' ' || s[i] == '\t')
                continue;
            else
            {
                flag = false;
                break;
            }
        }
        
        return flag;
    }

    bool isFloat(string& s)
    {
        bool flag = false;
        
        int i;
        
        for(i = 0; i < s.length(); i++)
        {
            if(s[i] == ' ' || s[i] == '\t')
                continue;
            else
                break;
        }
        
        if(s[i] == '-' || s[i] == '+')
            i++;
            
        for(i; i < s.length(); i++)
        {
            if(s[i] >= '0' && s[i] <= '9')
                flag = true;
            else
                break;
        }
        
        if(s[i] == '.')
            i++;
        else
            return false;
            
        for(i; i < s.length(); i++)
        {
            if(s[i] >= '0' && s[i] <= '9')
                flag = true;
            else
                break;
        }
                
        for(i; i < s.length(); i++)
        {
            if(s[i] == ' ' || s[i] == '\t')
                continue;
            else
                return false;
        }
        
        return flag;
    }
    
    bool isExp (string& s)
    {
	    bool flag = false;
	
	    int i;
	
	    for(i = 0; i < s.length(); i++)
	    {
    		if(s[i] == ' ' || s[i] == '\t')
			    continue;
		    else
		    	break;
	    }
	
    	if(s[i] == '+' || s[i] == '-')
		    i++;
	
	    for(i; i < s.length(); i++)
	    {
	    	if(s[i] >= '0' && s[i] <= '9')
			    flag = true;
		    else
	    		break;
	    }

    	if(s[i] == '.')
    		i++;
    		
    	for(i; i < s.length(); i++)
    	{
            if(s[i] >= '0' && s[i] <= '9')
                flag = true;
            else
                break;
    	}
		
    	if(flag && (s[i] == 'e' || s[i] == 'E'))
    		i++;
    	else
    	    return false;
	
    	if(s[i] == '+' || s[i] == '-')
		    i++;
		    
		if(s[i] >= '0' && s[i] <= '9')
		    flag = true;
		else
		    return false;
		
	    for(i; i < s.length(); i++)
	    {
    		if(s[i] >= '0' && s[i] <= '9')
			    flag = true;
		    else
		    	break;
	    }
	
	    for(i; i < s.length(); i++)
	    {
		    if(s[i] == ' ' || s[i] == '\t')
			    continue;
		    else
		    	return false;
	    }
	
	    return flag;
    }
    
    bool isNumber(string s) {
        
        bool dot = false;
        bool expo = false;
        bool digit = false;
        
        for(int i = 0; i < s.length(); i++)
        {
            switch(s[i])
            {
                case '+':   
                case '-':
                case ' ':
                case '\t':  break;
                case '.':   dot = true;
                            break;
                case 'e':   expo = true;
                            break;
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':   digit = true;
                            break;
                default:    return false;
            }
        }
        
        if(digit && !dot && !expo && isInteger(s))
            return true;
            
        if(digit && dot && !expo && isFloat(s))
            return true;
            
        if(digit && expo && isExp(s))
            return true;
        
        return false;
    }
};