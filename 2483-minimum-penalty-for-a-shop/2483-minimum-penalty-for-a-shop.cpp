class Solution {
public:
    int bestClosingTime(string customer) {
        int n = customer.size();

        vector<int> pn(n), sy(n);

        if(customer[0] == 'N')
            pn[0] = 1;

        for(int i = 1; i < n; i++) {
            pn[i] = pn[i - 1];

            if(customer[i] == 'N')
                pn[i]++;
        }

        if(customer[n - 1] == 'Y')
            sy[n - 1] = 1;

        for(int i = n - 2; i >= 0; i--) {
            sy[i] = sy[i + 1];

            if(customer[i] == 'Y')
                sy[i]++;
        }

        int mp = sy[0];
        int ans = 0;

        for(int j = 1; j < n; j++) {
            int pt = pn[j - 1] + sy[j];

            if(pt < mp) {
                mp = pt;
                ans = j;
            }
        }

        // Closing at n
        if(pn[n - 1] < mp)
            ans = n;

        return ans;
    }
};