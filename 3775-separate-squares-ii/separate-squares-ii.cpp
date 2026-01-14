class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        vector<long long> xs;
        vector<array<long long,4>> ev;
        for (auto &s : squares) {
            long long x = s[0], y = s[1], l = s[2];
            xs.push_back(x);
            xs.push_back(x + l);
            ev.push_back({y, x, x + l, 1});
            ev.push_back({y + l, x, x + l, -1});
        }
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        int n = xs.size();

        vector<long long> cnt(4 * n), len(4 * n);

        function<void(int,int,int)> pull = [&](int node, int l, int r) {
            if (cnt[node] > 0) len[node] = xs[r] - xs[l];
            else if (l + 1 == r) len[node] = 0;
            else len[node] = len[node*2] + len[node*2+1];
        };

        function<void(int,int,int,int,int,int)> upd =
        [&](int node, int l, int r, int ql, int qr, int v) {
            if (qr <= l || r <= ql) return;
            if (ql <= l && r <= qr) {
                cnt[node] += v;
                pull(node, l, r);
                return;
            }
            int m = (l + r) / 2;
            upd(node*2, l, m, ql, qr, v);
            upd(node*2+1, m, r, ql, qr, v);
            pull(node, l, r);
        };

        sort(ev.begin(), ev.end());

        double total = 0;
        long long prevY = ev[0][0];
        for (int i = 0; i < ev.size(); ) {
            long long y = ev[i][0];
            total += (double)len[1] * (y - prevY);
            while (i < ev.size() && ev[i][0] == y) {
                int l = lower_bound(xs.begin(), xs.end(), ev[i][1]) - xs.begin();
                int r = lower_bound(xs.begin(), xs.end(), ev[i][2]) - xs.begin();
                upd(1, 0, n - 1, l, r, ev[i][3]);
                i++;
            }
            prevY = y;
        }

        double half = total / 2.0;
        double cur = 0;
        fill(cnt.begin(), cnt.end(), 0);
        fill(len.begin(), len.end(), 0);

        prevY = ev[0][0];
        for (int i = 0; i < ev.size(); ) {
            long long y = ev[i][0];
            double strip = (double)len[1] * (y - prevY);
            if (cur + strip >= half) {
                return prevY + (half - cur) / len[1];
            }
            cur += strip;
            while (i < ev.size() && ev[i][0] == y) {
                int l = lower_bound(xs.begin(), xs.end(), ev[i][1]) - xs.begin();
                int r = lower_bound(xs.begin(), xs.end(), ev[i][2]) - xs.begin();
                upd(1, 0, n - 1, l, r, ev[i][3]);
                i++;
            }
            prevY = y;
        }
        return prevY;
    }
};
