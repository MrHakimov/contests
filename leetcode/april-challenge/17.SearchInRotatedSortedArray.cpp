class Solution {
public:
    int search(vector<int>& shiftArr, int num) {
      if (shiftArr.empty()) {
        return -1;
      }
        
      int n = (int) shiftArr.size(); // 5
      int splitIndex;
      int l = -1; // -1
      int r = n - 1; // 4
      // (l, r]

      while (r - l > 1) { // 5, 3, 2
        int m = (l + r) / 2; // 1, 2, 3

        if (shiftArr[m] > shiftArr[n - 1]) {
          l = m; // l = 2
        } else {
          r = m; // r = 3
        }
      }

      splitIndex = r; // 3

      if (num <= shiftArr[n - 1]) {
        l = splitIndex - 1; // 2
        r = n - 1; // 4
      } else {
        l = -1;
        r = splitIndex - 1;
      }

      while (r - l > 1) { // 2
        int m = (l + r) / 2; // 3

        if (shiftArr[m] >= num) {
          r = m;
        } else {
          l = m; // 3
        }
      }

      if (r >= 0 && shiftArr[r] == num) {
        return r;
      } else {
        return -1;
      }
    }
};
