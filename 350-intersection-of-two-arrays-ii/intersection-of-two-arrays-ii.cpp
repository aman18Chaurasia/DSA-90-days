class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int freq[1001] = {0};
        vector<int> result;
        for (int x : nums1) {
            freq[x]++;
        }
        for (int x : nums2) {
            if (freq[x] > 0) {
                result.push_back(x);
                freq[x]--;
            }
        }

        return result;
    }
};
