class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        map<string, vector<int>> mp;

        for(int i = 0; i < keyName.size(); i++) {
            int h = stoi(keyTime[i].substr(0, 2));
            int m = stoi(keyTime[i].substr(3, 2));

            mp[keyName[i]].push_back(h * 60 + m);
        }

        vector<string> ans;

        for(auto &p : mp) {
            vector<int> v = p.second;

            sort(v.begin(), v.end());

            for(int i = 0; i + 2 < v.size(); i++) {
                if(v[i + 2] - v[i] <= 60) {
                    ans.push_back(p.first);
                    break;
                }
            }
        }

        return ans;
    }
};