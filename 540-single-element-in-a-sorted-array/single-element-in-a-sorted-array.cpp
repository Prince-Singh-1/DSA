class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        int n = a.size();

        for(int i = 0; i < n; i++) {
            if(i > 0 && a[i] == a[i - 1])
                continue;

            if(i + 1 < n && a[i] == a[i + 1])
                continue;

            return a[i];
        }

        return -1;
    }
};