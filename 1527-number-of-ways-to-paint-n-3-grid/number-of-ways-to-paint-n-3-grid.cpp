class Solution {
public:
    int numOfWays(int n) {
        int MOD = 1000000007;

        long long sameEnds = 6;
        long long allDiff = 6;

        for (int row = 2; row <= n; row++) {
            long long newSameEnds = (3 * sameEnds + 2 * allDiff) % MOD;
            long long newAllDiff = (2 * sameEnds + 2 * allDiff) % MOD;

            sameEnds = newSameEnds;
            allDiff = newAllDiff;
        }

        return (sameEnds + allDiff) % MOD;
    }
};
