class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double ans = 0;
        int prv = 0;

        for(auto x : brackets) {
            int up = x[0];
            int rt = x[1];

            int amt = min(income, up) - prv;

            if(amt > 0)
                ans += amt * rt / 100.0;

            if(income <= up)
                break;

            prv = up;
        }

        return ans;
    }
};