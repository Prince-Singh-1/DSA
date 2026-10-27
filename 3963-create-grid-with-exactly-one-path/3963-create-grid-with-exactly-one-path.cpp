class Solution {
public:
    typedef long long ll;
    vector<string> createGrid(int m, int n) {
        vector<string> prince;
        vector<string> g(m, string(n, '#'));

        if (m == 1) {
            g[0] = string(n, '.');
            return g;
        }

        if (n == 1) {
            for (int i = 0; i < m; i++)
                g[i][0] = '.';
            return g;
        }

        for (int j = 0; j < n; j++)
            g[0][j] = '.';
        for (int i = 0; i < m; i++)
            g[i][n - 1] = '.';

        return g;
    }
};