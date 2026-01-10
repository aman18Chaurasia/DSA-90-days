class Solution {
public:
    int minimumDeleteSum(string a, string b) {
        int n = a.size(), m = b.size();
        static int dp[1001];

        for (int j = 0; j <= m; j++)
            dp[j] = 0;

        for (int j = m - 1; j >= 0; j--)
            dp[j] = dp[j + 1] + b[j];

        for (int i = n - 1; i >= 0; i--) {
            int prev = dp[m];
            dp[m] += a[i];
            for (int j = m - 1; j >= 0; j--) {
                int tmp = dp[j];
                if (a[i] == b[j])
                    dp[j] = prev;
                else
                    dp[j] = min(a[i] + dp[j], b[j] + dp[j + 1]);
                prev = tmp;
            }
        }
        return dp[0];
    }
};
