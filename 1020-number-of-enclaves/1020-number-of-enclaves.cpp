class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int k, int m, int n) {
        if (i < 0 || k < 0 || i >= m || k >= n || grid[i][k] == 0) {
            return;
        }   
        grid[i][k] = 0;
        dfs(grid, i + 1, k, m, n);
        dfs(grid, i - 1, k, m, n);
        dfs(grid, i, k + 1, m, n);
        dfs(grid, i, k - 1, m, n);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            dfs(grid, i, 0, m, n);
            dfs(grid, i, n - 1, m, n);
        }
        for (int k = 0; k < n; k++) {
            dfs(grid, 0, k, m, n);
            dfs(grid, m - 1, k, m, n);
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int k = 0; k < n; k++) {
                if (grid[i][k] == 1) {
                    ans++;
                }
            }
        }
        return ans;
    }
};