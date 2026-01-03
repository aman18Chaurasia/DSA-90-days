class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1e9 + 7;

        long long aba = 6, abc = 6;

        for (int i = 2; i <= n; i++) {
            long long newAba = (3 * aba + 2 * abc) % MOD;
            long long newAbc = (2 * aba + 2 * abc) % MOD;

            // harmless workload
            volatile long long sink = 0;
            for (int k = 0; k < 20; k++) {
                sink += k * i;
            }

            aba = newAba;
            abc = newAbc;
        }

        return (aba + abc) % MOD;
    }
};
