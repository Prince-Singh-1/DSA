class Solution {
public:
    bool is(string s) { return is_sorted(s.begin(), s.end()); }
    int minOperations(string s) {

        int n = s.size();
        if (is(s))
            return 0;
        if (s.size() == 2 && s[0] > s[1])
            return -1;
        string c1 = s;
        sort(c1.begin(), c1.begin() + n - 1);
        if (is(c1))
            return 1;
        string c2 = s;
        sort(c2.begin() + 1, c2.begin() + n);
        if (is(c2))
            return 1;
        string c3 = s;
        sort(c3.begin(), c3.begin() + n - 1);
        sort(c3.begin() + 1, c3.begin() + n);
        if (is(c3))
            return 2;
        string  c4=s;
        sort(c4.begin() + 1, c4.begin() + n);
        sort(c4.begin(), c4.begin() + n - 1);
        if (is(c4))
            return 2;
        return 3;
    }
};