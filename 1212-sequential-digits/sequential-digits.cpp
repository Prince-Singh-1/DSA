class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;

        for (int st = 1; st <= 8; st++) {
            int num = st;
            for (int d = st + 1; d <= 9; d++) {
                num = num * 10 + d;
                if (num >= low && num <= high)
                    ans.push_back(num);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};