class Solution {
    using ll = long long;

    int n;
    vector<vector<int>> g;
    vector<int> dep, par, sz, son;
    vector<int> tin, tout, top;
    int tim;

    vector<int> bit;
    vector<int> pre;

    void dfs1(int u, int p) {
        par[u] = p;
        sz[u] = 1;
        son[u] = -1;

        for (int v : g[u]) {
            if (v == p) continue;

            dep[v] = dep[u] + 1;
            dfs1(v, u);

            sz[u] += sz[v];

            if (son[u] == -1 || sz[v] > sz[son[u]])
                son[u] = v;
        }
    }

    void dfs2(int u, int tp) {
        tin[u] = tim++;
        top[u] = tp;

        if (son[u] != -1)
            dfs2(son[u], tp);

        for (int v : g[u]) {
            if (v == par[u] || v == son[u])
                continue;

            dfs2(v, v);
        }

        tout[u] = tim - 1;
    }

    int lca(int u, int v) {
        while (top[u] != top[v]) {
            if (dep[top[u]] < dep[top[v]])
                swap(u, v);

            u = par[top[u]];
        }

        return dep[u] < dep[v] ? u : v;
    }

    void add(int x, int v) {
        x++;

        while (x <= n) {
            bit[x] ^= v;
            x += x & -x;
        }
    }

    int get(int x) {
        x++;
        int r = 0;

        while (x > 0) {
            r ^= bit[x];
            x -= x & -x;
        }

        return r;
    }

    int cv(char c) {
        return 1 << (c - 'a');
    }

public:
    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        this->n = n;

        g.assign(n, {});
        dep.assign(n, 0);
        par.assign(n, -1);
        sz.assign(n, 0);
        son.assign(n, -1);
        tin.assign(n, 0);
        tout.assign(n, 0);
        top.assign(n, 0);

        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        dfs1(0, -1);

        tim = 0;
        dfs2(0, 0);

        pre.assign(n, 0);

        function<void(int,int,int)> dfs = [&](int u, int p, int x) {
            x ^= cv(s[u]);
            pre[u] = x;

            for (int v : g[u]) {
                if (v == p) continue;
                dfs(v, u, x);
            }
        };

        dfs(0, -1, 0);

        bit.assign(n + 1, 0);

        vector<bool> ans;

        for (auto &q : queries) {
            stringstream ss(q);

            string op;
            int u, v;
            char c;

            ss >> op >> u;

            if (op == "update") {
                ss >> c;

                int d = cv(s[u]) ^ cv(c);

                add(tin[u], d);
                add(tout[u] + 1, d);

                s[u] = c;
            }
            else {
                ss >> v;

                int w = lca(u, v);

                int x = pre[u] ^ get(tin[u]);
                int y = pre[v] ^ get(tin[v]);

                int mask = x ^ y ^ cv(s[w]);

                ans.push_back(
                    (mask & (mask - 1)) == 0
                );
            }
        }

        return ans;
    }
};