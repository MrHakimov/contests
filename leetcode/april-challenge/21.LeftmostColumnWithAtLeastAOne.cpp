/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dims = binaryMatrix.dimensions();
        
        int n = dims[0];
        int m = dims[1];
        
        if (n == 0) {
            return -1;
        }
        
        int answer = m;
        int i = 0;
        int j = m - 1;
        
        while (i < n && j >= 0) {
            if (binaryMatrix.get(i, j) == 1) {
                answer = min(answer, j);
                --j;
            } else {
                ++i;
            }
        }
        
        if (answer == m) {
            return -1;
        } else {
            return answer;
        }
    }
};

