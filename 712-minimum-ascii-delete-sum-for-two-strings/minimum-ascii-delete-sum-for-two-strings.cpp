class Solution {
public:
    int minimumDeleteSum(string a, string b) {
        int n = a.size(), m = b.size();
        vector<int> d(m + 1);

        for (int j = m - 1; j >= 0; j--)
            d[j] = d[j + 1] + b[j];

        for (int i = n - 1; i >= 0; i--) {
            int p = d[m];
            d[m] += a[i];
            for (int j = m - 1; j >= 0; j--) {
                int q = d[j];
                if (a[i] == b[j])
                    d[j] = p;
                else
                    d[j] = min(a[i] + d[j], b[j] + d[j + 1]);
                p = q;
            }
        }
        return d[0];
    }
};
