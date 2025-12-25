class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        // Step 1: Sort in descending order
        sort(happiness.begin(), happiness.end(), greater<int>());

        long long total = 0;

        // Step 2: Pick k children
        for (int i = 0; i < k; i++) {
            int currentHappiness = happiness[i] - i;

            // Happiness cannot be negative
            if (currentHappiness > 0) {
                total += currentHappiness;
            }
        }

        return total;
    }
};
