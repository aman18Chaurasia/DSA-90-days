#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int max_len = 0;

        for (int i = 0; i < n; ++i) {
            int counts[26] = {0};
            int distinct_count = 0;
            int max_freq = 0;

            for (int j = i; j < n; ++j) {
                int char_idx = s[j] - 'a';

                if (counts[char_idx] == 0) {
                    distinct_count++;
                }

                counts[char_idx]++;
                
                if (counts[char_idx] > max_freq) {
                    max_freq = counts[char_idx];
                }

                int current_len = j - i + 1;

                if (max_freq * distinct_count == current_len) {
                    max_len = std::max(max_len, current_len);
                }
            }
        }

        return max_len;
    }
};