/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class NumArray {
    int len;
    int *sum;
public:
    NumArray(vector<int> &nums) {
        len = nums.size();
        
        sum = new int[len];
        
        if(len)
        {
            sum[0] = nums[0];
            
            for (int i = 1; i < len; i++)
                sum[i] = sum[i-1] + nums[i];
        }
    }

    int sumRange(int i, int j) {
        if(!i)
            return sum[j];
            
        return sum[j] - sum[i-1];
    }
};