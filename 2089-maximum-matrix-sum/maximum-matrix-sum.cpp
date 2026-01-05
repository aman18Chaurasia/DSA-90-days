class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long totalSum = 0;
        int negCount = 0;
        int minAbs = INT_MAX;

        for (auto &row : matrix) {
            for (int val : row) {
                if (val < 0) negCount++;
                int absVal = abs(val);
                totalSum += absVal;
                minAbs = min(minAbs, absVal);
            }
        }

        if (negCount % 2 == 0)
            return totalSum;
        else
            return totalSum - 2LL * minAbs;
    }
};
