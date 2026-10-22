class Solution {
public:
    struct data {
        string nam, pla;
        int tim, amt;
    };

    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<string> ans;
        vector<data> v;
        map<string, vector<int>> mp;

        for(int i = 0; i < transactions.size(); i++) {
            stringstream ss(transactions[i]);

            string nam, tim, amt, pla;

            getline(ss, nam, ',');
            getline(ss, tim, ',');
            getline(ss, amt, ',');
            getline(ss, pla, ',');

            v.push_back({nam, pla, stoi(tim), stoi(amt)});
            mp[nam].push_back(i);
        }

        vector<int> bad(v.size(), 0);

        for(auto &[nam, ids] : mp) {
            for(int i : ids) {
                if(v[i].amt > 1000)
                    bad[i] = 1;

                for(int j : ids) {
                    if(v[i].pla != v[j].pla &&
                       abs(v[i].tim - v[j].tim) <= 60) {
                        bad[i] = 1;
                        break;
                    }
                }
            }
        }

        for(int i = 0; i < v.size(); i++) {
            if(bad[i])
                ans.push_back(transactions[i]);
        }

        return ans;
    }
};