class Solution {
public:
    typedef long long ll;

    long long maxSubarraySum(vector<int>& a, int k) {
        int n = a.size();

        vector<ll> mn(k, LLONG_MAX);

        ll pre = 0;
        ll ans = LLONG_MIN;

        mn[0] = 0;

        for (int i = 0; i < n; i++) {
            pre += a[i];

            int rem = (i + 1) % k;

            if (mn[rem] != LLONG_MAX)
                ans = max(ans, pre - mn[rem]);

            mn[rem] = min(mn[rem], pre);
        }

        return ans;
    }
};