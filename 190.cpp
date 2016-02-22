/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
public:
	uint32_t reverseBits1(uint32_t n) {
        uint32_t result = 0;
        
        for(int i = 0; i < 32; i++)
        {
            result <<= 1;
            result |= (n & 1);
            n >>= 1;
        }

        return result;
    }

    uint32_t reverseBits(uint32_t n) {
        uint32_t l, r, temp, shift;
        
        l = 1;
        r = 1 << 31;
        shift = 31;
        
        while(l < r)
        {
            temp = (n & l) << shift;
            n = n & ~l;
            n = n | ((n & r) >> shift);
            n = n & ~r;
            n = n | temp;
            l <<= 1;
            r >>= 1;
            shift -= 2;
        }
        
        return n;
    }
};