/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
	int depthSum(vector<NestedInteger>& nestedList, int depth)
	{
        int res = 0;

        for(auto l: nestedList)
        {
        	res += (l.isInteger() ? (depth * l.getInteger()) : depthSum(l.getList(), depth + 1));
        }

        return res;
    }
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        return depthSum(nestedList, 1);
    }
};