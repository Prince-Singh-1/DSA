class Solution {
public:
    vector<int> v = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    int f(string s) {
        int m = stoi(s.substr(0, 2));
        int d = stoi(s.substr(3, 2));

        int x = d;

        for(int i = 0; i < m - 1; i++)
            x += v[i];

        return x;
    }

    int countDaysTogether(string a1, string a2,
                          string b1, string b2) {

        int x = max(f(a1), f(b1));
        int y = min(f(a2), f(b2));

        return max(0, y - x + 1);
    }
};