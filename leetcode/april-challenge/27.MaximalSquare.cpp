class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = (int) matrix.size();
        
        if (n == 0) {
            return 0;
        }
        
        int m = (int) matrix[0].size();
        
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
        vector<int> diffX = {0, -1, -1};
        vector<int> diffY = {-1, -1, 0};
        
        auto isValidCell = [&] (int i, int j) {
            return 0 <= i && i < n && 0 <= j && j < m;
        };
        
        int answer = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == '0') {
                    continue;
                }
                
                int mn = n + m;
                bool hasInvalid = false;
                for (int k = 0; k < 3; ++k) {
                    int i1 = i + diffX[k];
                    int j1 = j + diffY[k];
                    
                    if (isValidCell(i1, j1)) {
                        mn = min(dp[i1][j1], mn);
                    } else {
                        hasInvalid = true;
                    }
                }
                
                dp[i][j] = (hasInvalid || mn == n + m ? 1 : mn + 1);
                answer = max(answer, dp[i][j]);
            }
        }
        
        return answer * answer;
    }
};
