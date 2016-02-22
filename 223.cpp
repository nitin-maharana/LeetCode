/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
    int area;
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        area = ((C-A) * (D-B)) + ((G-E) * (H-F));
        
        if((E >= C) || (A >= G) || (F >= D) || (B >= H))
            return area;
        
        return area - ((min(C,G)-max(E,A)) * (min(D,H)-max(F,B)));
    }
};