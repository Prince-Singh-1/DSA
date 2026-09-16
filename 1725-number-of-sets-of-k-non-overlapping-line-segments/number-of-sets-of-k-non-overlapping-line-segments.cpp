class Solution {
public:
    typedef long long ll;
    const ll mod = 1e9 + 7;

    ll pw(ll a, ll b) {
        ll r = 1;

        while (b) {
            if (b & 1)
                r = r * a % mod;

            a = a * a % mod;
            b >>= 1;
        }

        return r;
    }

    int numberOfSets(int n, int k) {
        int a = n + k - 1;
        int b = 2 * k;

        ll num = 1;
        ll den = 1;

        for (int i = 1; i <= b; i++) {
            num = num * (a - i + 1) % mod;
            den = den * i % mod;
        }

        return num * pw(den, mod - 2) % mod;
    }
};