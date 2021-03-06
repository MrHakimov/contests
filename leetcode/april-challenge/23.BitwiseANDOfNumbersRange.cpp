class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int result = 0;
        
        for (int i = 0; i < 31; ++i) {
            if ((n - m <= ((1 << i) - 1)) && (((m >> i) & 1) == 1) && (((n >> i) & 1 == 1))) {
                result |= (1 << i);
            }
        }
        
        return result;
    }
};
