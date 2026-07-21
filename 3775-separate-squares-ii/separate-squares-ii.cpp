class Seg {
public:
    vector<int> cnt;
    vector<double> len;
    vector<int> xs;

    Seg(vector<int> &v) {
        xs = v;
        int n = xs.size();
        cnt.assign(4 * n, 0);
        len.assign(4 * n, 0);
    }

    void upd(int id, int l, int r, int ql, int qr, int v) {
        if (ql >= r || qr <= l)
            return;
        if (ql <= l && r <= qr)
            cnt[id] += v;
        else {
            int m = (l + r) >> 1;
            upd(id << 1, l, m, ql, qr, v);
            upd(id << 1 | 1, m, r, ql, qr, v);
        }

        if (cnt[id])
            len[id] = xs[r] - xs[l];
        else if (r - l == 1)
            len[id] = 0;
        else
            len[id] = len[id << 1] + len[id << 1 | 1];
    };
};

class Solution {
public:
    double separateSquares(vector<vector<int>>& sq) {
        vector<int> xs;

        struct E {
            int y, x1, x2, t;
        };

        vector<E> ev;

        for (auto &v : sq) {
            int x = v[0], y = v[1], l = v[2];
            xs.push_back(x);
            xs.push_back(x + l);
            ev.push_back({y, x, x + l, 1});
            ev.push_back({y + l, x, x + l, -1});
        }

        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());

        sort(ev.begin(), ev.end(), [](auto &a, auto &b) {
            return a.y < b.y;
        });

        auto calc = [&](double need) {
            Seg st(xs);
            double area = 0;
            int py = ev[0].y;

            for (int i = 0; i < ev.size();) {
                int y = ev[i].y;
                double h = y - py;

                if (area + st.len[1] * h >= need && st.len[1] > 0)
                    return (double)py + (need - area) / st.len[1];

                area += st.len[1] * h;

                while (i < ev.size() && ev[i].y == y) {
                    int l = lower_bound(xs.begin(), xs.end(), ev[i].x1) - xs.begin();
                    int r = lower_bound(xs.begin(), xs.end(), ev[i].x2) - xs.begin();
                    st.upd(1, 0, xs.size() - 1, l, r, ev[i].t);
                    i++;
                }

                py = y;
            }

            return (double)py;
        };

        Seg st(xs);
        double tot = 0;
        int py = ev[0].y;

        for (int i = 0; i < ev.size();) {
            int y = ev[i].y;
            tot += st.len[1] * (y - py);

            while (i < ev.size() && ev[i].y == y) {
                int l = lower_bound(xs.begin(), xs.end(), ev[i].x1) - xs.begin();
                int r = lower_bound(xs.begin(), xs.end(), ev[i].x2) - xs.begin();
                st.upd(1, 0, xs.size() - 1, l, r, ev[i].t);
                i++;
            }

            py = y;
        }

        return calc(tot / 2.0);
    }
};