class Solution {
public:
    int minOperations(vector<int>& v) {
        int n = v.size();
        int p = 0;
        for (int i = 0; i < n; i++) {

            if (v[i] == 0) {
                p = i;
                break;
            }
        }
        bool a = 1, b = 1;

        for (int i = 0; i < n; i++) {

            if (v[(p + i) % n] != i)
                a = 0;

            if (v[(p - i + n) % n] != i)
                b = 0;
        }
        int ans = 1e9;
        if (a) {

            if (p == 0)
                ans = 0;
            else
                ans = min({ans, p, n - p + 2});
        }
        if (b)
            ans = min({ans, (p + 1) % n + 1, n - p});

        return ans == 1e9 ? -1 : ans;
    }
};