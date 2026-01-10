class Solution {
public:
    int minimumDeleteSum(string a, string b) {
        int x = a.size(), y = b.size();
        vector<vector<int>> t(x + 1, vector<int>(y + 1));

        for (int i = x - 1; i >= 0; i--)
            t[i][y] = t[i + 1][y] + a[i];

        for (int j = y - 1; j >= 0; j--)
            t[x][j] = t[x][j + 1] + b[j];

        for (int i = x - 1; i >= 0; i--) {
            for (int j = y - 1; j >= 0; j--) {
                if (a[i] == b[j])
                    t[i][j] = t[i + 1][j + 1];
                else
                    t[i][j] = min(a[i] + t[i + 1][j], b[j] + t[i][j + 1]);
            }
        }
        return t[0][0];
    }
};
