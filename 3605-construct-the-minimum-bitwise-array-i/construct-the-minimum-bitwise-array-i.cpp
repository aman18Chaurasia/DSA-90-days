class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;

        for (int n : nums) {
            if ((n & 1) == 0) {
                ans.push_back(-1);
                continue;
            }

            int k = 0;
            int temp = n;

            while (temp & 1) {
                k++;
                temp >>= 1;
            }

            ans.push_back(n - (1 << (k - 1)));
        }

        return ans;
    }
};
