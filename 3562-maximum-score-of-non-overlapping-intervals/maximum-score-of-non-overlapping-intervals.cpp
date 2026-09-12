class Solution {
public:
    struct Node {
        long long score;
        vector<int> ids;
    };

    bool better(const Node& a, const Node& b) {
        if (a.score != b.score)
            return a.score > b.score;

        return lexicographical_compare(
            a.ids.begin(), a.ids.end(),
            b.ids.begin(), b.ids.end()
        );
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // {left, right, weight, original index}
        vector<array<long long, 4>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Sort by LEFT endpoint
        sort(a.begin(), a.end(), [](const auto& x, const auto& y) {
            if (x[0] != y[0])
                return x[0] < y[0];

            return x[1] < y[1];
        });

        // next[i] = first interval j such that
        // a[j].left > a[i].right
        vector<int> nxt(n);

        for (int i = 0; i < n; i++) {
            int lo = i + 1;
            int hi = n;

            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;

                if (a[mid][0] > a[i][1])
                    hi = mid;
                else
                    lo = mid + 1;
            }

            nxt[i] = lo;
        }

        // dp[i][k]:
        // best result considering intervals [i ... n-1]
        // with at most k intervals
        vector<vector<Node>> dp(n + 1, vector<Node>(5));

        // No intervals remaining
        for (int k = 0; k <= 4; k++) {
            dp[n][k] = {0, {}};
        }

        for (int i = n - 1; i >= 0; i--) {

            dp[i][0] = {0, {}};

            for (int k = 1; k <= 4; k++) {

                // Option 1: skip interval i
                Node skip = dp[i + 1][k];

                // Option 2: take interval i
                Node take = dp[nxt[i]][k - 1];

                take.score += a[i][2];
                take.ids.push_back((int)a[i][3]);

                // The answer must be sorted by ORIGINAL indices
                sort(take.ids.begin(), take.ids.end());

                dp[i][k] = better(take, skip)
                         ? take
                         : skip;
            }
        }

        return dp[0][4].ids;
    }
};
