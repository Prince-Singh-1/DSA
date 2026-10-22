class Solution {
public:
    struct data {
        string nam, pla;
        int tim, amt;
    };

    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<string> ans;
        vector<data> v;

        for(auto &trans : transactions) {
            stringstream ss(trans);

            string nam, tim, amt, pla;

            getline(ss, nam, ',');
            getline(ss, tim, ',');
            getline(ss, amt, ',');
            getline(ss, pla, ',');

            v.push_back({nam, pla, stoi(tim), stoi(amt)});
        }

        vector<int> bad(v.size(), 0);

        for(int i = 0; i < v.size(); i++) {
            if(v[i].amt > 1000)
                {bad[i] = 1;continue;}

            for(int j = 0; j < v.size(); j++) {
                if(i == j)
                    continue;

                if(v[i].nam == v[j].nam &&
                   abs(v[i].tim - v[j].tim) <= 60 &&
                   v[i].pla != v[j].pla) {
                    bad[i] = 1;
                    break;
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