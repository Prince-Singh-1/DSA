class Solution {
public:
    int m, n;

    bool dfs(vector<vector<int>>& g, int r, int c) {
        if (r < 0 || c < 0 || r >= m || c >= n)
            return false;

        if (g[r][c] == 1)
            return true;

        g[r][c] = 1;

        bool a = dfs(g, r + 1, c);
        bool b = dfs(g, r - 1, c);
        bool d = dfs(g, r, c + 1);
        bool e = dfs(g, r, c - 1);

        return a && b && d && e;
    }

    int closedIsland(vector<vector<int>>& g) {
        m = g.size();
        n = g[0].size();

        int ans = 0;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (g[r][c] == 0) {
                    if (dfs(g, r, c))
                        ans++;
                }
            }
        }

        return ans;
    }
};