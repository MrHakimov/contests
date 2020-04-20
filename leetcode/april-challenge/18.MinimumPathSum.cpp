class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = (int) grid.size();
        
        if (n == 0) {
            return 0;
        }
        
        int m = (int) grid[0].size();
        vector<vector<int>> dp(n, vector<int> (m, 0));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                dp[i][j] = grid[i][j];
                
                set<int> tmp = {INT_MAX};
                if (i - 1 >= 0) {
                    tmp.insert(dp[i - 1][j]);
                }
                
                if (j - 1 >= 0) {
                    tmp.insert(dp[i][j - 1]);
                }
                
                if (*(tmp.begin()) != INT_MAX) {
                    dp[i][j] += *(tmp.begin());
                }
            }
        }
        
        return dp[n - 1][m - 1];
    }
};
