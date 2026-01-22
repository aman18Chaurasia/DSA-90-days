class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int freq[2001] = {0};
        bool seen[1002] = {false};

        for (int x : arr) {
            freq[x + 1000]++;
        }

        for (int i = 0; i < 2001; i++) {
            if (freq[i] > 0) {
                if (seen[freq[i]]) return false;
                seen[freq[i]] = true;
            }
        }

        return true;
    }
};
