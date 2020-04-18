class Solution {
    void dfs(pair<int, int> u, map<pair<int, int>, vector<pair<int, int>>> &g, vector<vector<bool>> &used) {
        used[u.first][u.second] = true;
        
        for (auto v : g[u]) {
            if (!used[v.first][v.second]) {
                dfs(v, g, used);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = (int) grid.size();
        
        if (n == 0) {
            return 0;
        }
        
        int m = (int) grid[0].size();
        
        map<pair<int, int>, vector<pair<int, int>>> g;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '0') {
                    continue;
                }
                
                vector<int> diffX = {-1, 0, 1, 0};
                vector<int> diffY = {0, -1, 0, 1};
                
                for (int k = 0; k < 4; ++k) {
                    int i1 = i + diffX[k];
                    int j1 = j + diffY[k];
                    
                    if (0 <= i1 && i1 < n && 0 <= j1 && j1 < m && grid[i1][j1] == '1') {
                        g[{i, j}].push_back({i1, j1});
                        g[{i1, j1}].push_back({i, j});
                    }
                }
            }
        }
        
        vector<vector<bool>> used(n, vector<bool> (m, false));
        int answer = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1' && !used[i][j]) {
                    dfs({i, j}, g, used);
                    ++answer;
                }
            }
        }
        
        return answer;
    }
};
