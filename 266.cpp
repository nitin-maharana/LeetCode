/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
    bool canPermutePalindrome(string s) {
		int memory[260];
		
		memset(memory, 0, sizeof(memory));

		int len = s.length();

		for(int i = 0; i < len; i++)
			memory[s[i]]++;

		int numOfOdds = 0;

		if(len&1)
		{
			for(int i = 0; i < 260; i++)
			{
				if(memory[i]&1)
					numOfOdds++;

				if(numOfOdds > 1)
					return false;
			}

			return true;
		}
		else
		{
			for(int i = 0; i < 260; i++)
				if(memory[i]&1)
					return false;

			return true;
		}
	}
};
