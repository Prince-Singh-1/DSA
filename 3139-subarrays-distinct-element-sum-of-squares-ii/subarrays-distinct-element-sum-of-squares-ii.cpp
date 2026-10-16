class Solution {
public:
    typedef long long ll;

    const ll mod = 1e9 + 7;

    vector<ll> sm, sq, lz;

    void apply(int p, int l, int r, ll x) {
        ll len = r - l + 1;

        sq[p] = (sq[p] + 2 * x % mod * sm[p] % mod
                + x * x % mod * len) % mod;

        sm[p] = (sm[p] + x * len) % mod;

        lz[p] += x;
    }

    void push(int p, int l, int r) {
        if(lz[p] == 0 || l == r)
            return;

        int m = (l + r) / 2;

        apply(2 * p, l, m, lz[p]);
        apply(2 * p + 1, m + 1, r, lz[p]);

        lz[p] = 0;
    }

    void upd(int p, int l, int r, int ql, int qr) {
        if(qr < l || r < ql)
            return;

        if(ql <= l && r <= qr) {
            apply(p, l, r, 1);
            return;
        }

        push(p, l, r);

        int m = (l + r) / 2;

        upd(2 * p, l, m, ql, qr);
        upd(2 * p + 1, m + 1, r, ql, qr);

        sm[p] = (sm[2 * p] + sm[2 * p + 1]) % mod;
        sq[p] = (sq[2 * p] + sq[2 * p + 1]) % mod;
    }

    int sumCounts(vector<int>& nums) {
        int n = nums.size();

        sm.assign(4 * n + 5, 0);
        sq.assign(4 * n + 5, 0);
        lz.assign(4 * n + 5, 0);

        vector<int> last(100001, -1);

        ll ans = 0;

        for(int i = 0; i < n; i++) {
            int p = last[nums[i]];

            upd(1, 0, n - 1, p + 1, i);

            ans = (ans + sq[1]) % mod;

            last[nums[i]] = i;
        }

        return ans;
    }
};