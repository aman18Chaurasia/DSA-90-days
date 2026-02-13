#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int max_len = 0;

        // Case 1: 1 distinct character (Contiguous blocks)
        int current_run = 0;
        for (int i = 0; i < n; ++i) {
            if (i > 0 && s[i] == s[i-1]) current_run++;
            else current_run = 1;
            max_len = max(max_len, current_run);
        }

        // Case 2: 2 distinct characters
        // Pairs: (a,b), (b,c), (a,c). The third character acts as a "wall".
        max_len = max({max_len, solveTwo(s, 'a', 'b', 'c'), 
                               solveTwo(s, 'b', 'c', 'a'), 
                               solveTwo(s, 'a', 'c', 'b')});

        // Case 3: 3 distinct characters
        max_len = max(max_len, solveThree(s));

        return max_len;
    }

private:
    // Finds longest substring with equal counts of x and y, containing NO z.
    int solveTwo(const string& s, char x, char y, char z) {
        int res = 0, diff = 0;
        unordered_map<int, int> first_seen;
        first_seen[0] = -1;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == z) {
                first_seen.clear();
                first_seen[0] = i;
                diff = 0;
            } else {
                if (s[i] == x) diff++;
                else diff--; // s[i] is y
                
                if (first_seen.count(diff)) {
                    res = max(res, i - first_seen[diff]);
                } else {
                    first_seen[diff] = i;
                }
            }
        }
        return res;
    }

    // Finds longest substring where count(a) == count(b) == count(c)
    int solveThree(const string& s) {
        int res = 0;
        int ca = 0, cb = 0, cc = 0;
        // Map packed differences (a-b, b-c) to the first index seen
        unordered_map<long long, int> first_seen;
        
        // Initial state: differences are (0, 0) at index -1
        first_seen[0] = -1;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == 'a') ca++;
            else if (s[i] == 'b') cb++;
            else if (s[i] == 'c') cc++;

            int d1 = ca - cb;
            int d2 = cb - cc;
            
            // Encode (d1, d2) into a single long long for the map key
            // Offset by 10^5 to handle negatives if necessary, 
            // but bit-shifting is cleaner.
            long long key = ((long long)d1 << 32) | (unsigned int)d2;

            if (first_seen.count(key)) {
                res = max(res, i - first_seen[key]);
            } else {
                first_seen[key] = i;
            }
        }
        return res;
    }
};