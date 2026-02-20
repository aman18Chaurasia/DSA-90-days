#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0;
        int prev_group_len = 0;
        int cur_group_len = 1;

        for (int i = 1; i < s.length(); ++i) {
            if (s[i] == s[i - 1]) {
                cur_group_len++;
            } else {
                ans += min(prev_group_len, cur_group_len);
                prev_group_len = cur_group_len;
                cur_group_len = 1;
            }
        }
        return ans + min(prev_group_len, cur_group_len);
    }
};