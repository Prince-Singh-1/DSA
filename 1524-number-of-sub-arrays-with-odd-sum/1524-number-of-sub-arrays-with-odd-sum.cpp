class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int mod = 1e9 + 7;

        long long odd = 0, even = 1, sum = 0;
        long long ans = 0;

        for (int x : arr) {
            sum += x;

            if (sum % 2)
                ans = (ans + even) % mod, odd++;
            else
                ans = (ans + odd) % mod, even++;
        }

        return ans;
    }
};