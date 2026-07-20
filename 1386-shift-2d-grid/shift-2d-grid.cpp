class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int t = m * n;
        k %= t;

        vector<vector<int>> ans(m, vector<int>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int idx = i * n + j;
                int ni = (idx + k) % t;
                ans[ni / n][ni % n] = grid[i][j];
            }
        }

        return ans;
    }
};