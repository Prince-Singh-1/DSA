
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs,
                             int x, vector<int>& queries) {
        int m = logs.size(), k = queries.size();

        sort(logs.begin(), logs.end(),
             [](auto &a, auto &b) {
                 return a[1] < b[1];
             });

        vector<pair<int,int>> qry;
        for (int i = 0; i < k; i++)
            qry.push_back({queries[i], i});

        sort(qry.begin(), qry.end());

        vector<int> cnt(n + 1, 0), ans(k);
        int l = 0, r = 0, active = 0;

        for (auto [q, idx] : qry) {
            while (r < m && logs[r][1] <= q) {
                int id = logs[r][0];

                if (cnt[id] == 0) active++;
                cnt[id]++;
                r++;
            }

            while (l < r && logs[l][1] < q - x) {
                int id = logs[l][0];

                cnt[id]--;
                if (cnt[id] == 0) active--;
                l++;
            }

            ans[idx] = n - active;
        }

        return ans;
    }
};
