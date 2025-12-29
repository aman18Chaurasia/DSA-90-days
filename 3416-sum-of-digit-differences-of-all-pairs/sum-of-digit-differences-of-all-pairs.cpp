class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        int n = nums.size();
        int num_digits = to_string(nums[0]).length();
        long long total_diff = 0;
        for (int i = 0; i < num_digits; ++i) {
            vector<long long> counts(10, 0);
            
            for (int& num : nums) {
                int temp = num;
                for (int j = 0; j < i; ++j) temp /= 10;
                counts[temp % 10]++;
            }
            long long total_pairs = (long long)n * (n - 1) / 2;
            
            long long same_pairs = 0;
            for (int d = 0; d < 10; ++d) {
                if (counts[d] > 1) {
                    same_pairs += (counts[d] * (counts[d] - 1)) / 2;
                }
            }
            
            total_diff += (total_pairs - same_pairs);
        }

        return total_diff;
    }
};