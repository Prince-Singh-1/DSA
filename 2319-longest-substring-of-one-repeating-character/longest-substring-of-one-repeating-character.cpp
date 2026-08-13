class Solution {
    struct Node {
        int len;
        int pre;
        int suf;
        int mx;
        char lc;
        char rc;
    };

    vector<Node> st;

    Node merge(Node a, Node b) {
        Node c;

        c.len = a.len + b.len;
        c.lc = a.lc;
        c.rc = b.rc;

        c.pre = a.pre;
        c.suf = b.suf;
        c.mx = max(a.mx, b.mx);

        if(a.rc == b.lc) {
            c.mx = max(c.mx, a.suf + b.pre);

            if(a.pre == a.len)
                c.pre = a.len + b.pre;

            if(b.suf == b.len)
                c.suf = b.len + a.suf;
        }

        return c;
    }

    void build(int p, int l, int r, string &s) {
        if(l == r) {
            st[p] = {1, 1, 1, 1, s[l], s[l]};
            return;
        }

        int m = (l + r) / 2;

        build(p * 2, l, m, s);
        build(p * 2 + 1, m + 1, r, s);

        st[p] = merge(st[p * 2], st[p * 2 + 1]);
    }

    void update(int p, int l, int r, int x, char ch) {
        if(l == r) {
            st[p] = {1, 1, 1, 1, ch, ch};
            return;
        }

        int m = (l + r) / 2;

        if(x <= m)
            update(p * 2, l, m, x, ch);
        else
            update(p * 2 + 1, m + 1, r, x, ch);

        st[p] = merge(st[p * 2], st[p * 2 + 1]);
    }

public:
    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {
        int n = s.size();

        st.resize(4 * n + 5);

        build(1, 0, n - 1, s);

        vector<int> ans;

        for(int i = 0; i < queryIndices.size(); i++) {
            update(
                1,
                0,
                n - 1,
                queryIndices[i],
                queryCharacters[i]
            );

            ans.push_back(st[1].mx);
        }

        return ans;
    }
};