class Solution {
public:
    int minMoves(vector<int>& a) {
       // sort(nums.begin(),nums.end());
       // 1 5 7 10 =3
       // 4 8 10 10 =2
       // 6 10 11 11=2
       // 8 12 12 12=3
       //  11 13 13 13=3
       //  14 14 14 14

         int mn = *min_element(a.begin(), a.end());
        int ans = 0;

        for (int x : a)
            ans += x - mn;

        return ans;

    }
};