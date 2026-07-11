class Solution {
public:
    vector<vector<int>> g;
    vector<int> vis;

    void dfs(int u, vector<int> &cmp) {
        vis[u] = 1;
        cmp.push_back(u);

        for (int v : g[u])
            if (!vis[v])
                dfs(v, cmp);
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        g.assign(n, {});
        vis.assign(n, 0);

        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;

            vector<int> cmp;
            dfs(i, cmp);

            int nodes = cmp.size();
            int deg = 0;

            for (int u : cmp)
                deg += g[u].size();

            if (deg / 2 == nodes * (nodes - 1) / 2)
                ans++;
        }

        return ans;
    }
};