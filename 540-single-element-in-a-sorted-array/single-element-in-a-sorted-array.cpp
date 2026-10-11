class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        int l = 0, r = a.size() - 1;

        while(l < r) {
            int m = l + (r - l) / 2;

            if(m % 2)
                m--;

            if(a[m] == a[m + 1])
                l = m + 2;
            else
                r = m;
        }

        return a[l];
    }
};