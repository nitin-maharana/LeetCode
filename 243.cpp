/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
	int shortestDistance(vector<string>& words, string word1, string word2) {
		int word1Index, word2Index;
		int dist;

		word1Index = word2Index = -1;
		dist = words.size();

		for(int i = 0; i < words.size(); i++)
		{
			if(words[i] == word1)
			{
				word1Index = i;

				if(word2Index != -1)
					dist = ((word1Index - word2Index) < dist) ? (word1Index - word2Index) : dist;
			}
			else if(words[i] == word2)
			{
				word2Index = i;

				if(word1Index != -1)
					dist = ((word2Index - word1Index) < dist) ? (word2Index - word1Index) : dist;
			}
		}

		return dist;
    }
};