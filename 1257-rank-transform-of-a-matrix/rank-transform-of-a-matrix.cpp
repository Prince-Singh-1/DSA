class Solution {
public:
    vector<int> p;

    int find(int x) {
        if (p[x] != x)
            p[x] = find(p[x]);
        return p[x];
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b)
            p[a] = b;
    }

    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        map<int, vector<pair<int,int>>> mp;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                mp[matrix[i][j]].push_back({i, j});

        vector<int> rank(m + n, 0);
        vector<vector<int>> ans(m, vector<int>(n));

        for (auto &it : mp) {
            p.resize(m + n);
            iota(p.begin(), p.end(), 0);

            for (auto &cell : it.second)
                unite(cell.first, cell.second + m);

            unordered_map<int, vector<pair<int,int>>> groups;

            for (auto &cell : it.second)
                groups[find(cell.first)].push_back(cell);

            for (auto &g : groups) {
                int mx = 0;

                for (auto &cell : g.second)
                    mx = max(mx, max(rank[cell.first], rank[cell.second + m]));

                mx++;

                for (auto &cell : g.second) {
                    ans[cell.first][cell.second] = mx;
                    rank[cell.first] = mx;
                    rank[cell.second + m] = mx;
                }
            }
        }

        return ans;
    }
};