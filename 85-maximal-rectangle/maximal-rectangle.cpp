class Solution {
public:
    int maximalRectangle(vector<vector<char>>& a) {
        int n = a.size(), m = a[0].size();
        vector<int> h(m, 0), l(m, 0), r(m, m);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int cl = 0, cr = m;

            for (int j = 0; j < m; j++) {
                if (a[i][j] == '1') h[j]++;
                else h[j] = 0;
            }

            for (int j = 0; j < m; j++) {
                if (a[i][j] == '1')
                    l[j] = max(l[j], cl);
                else {
                    l[j] = 0;
                    cl = j + 1;
                }
            }

            for (int j = m - 1; j >= 0; j--) {
                if (a[i][j] == '1')
                    r[j] = min(r[j], cr);
                else {
                    r[j] = m;
                    cr = j;
                }
            }

            for (int j = 0; j < m; j++)
                ans = max(ans, h[j] * (r[j] - l[j]));
        }
        return ans;
    }
};
