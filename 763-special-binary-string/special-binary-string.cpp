#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string makeLargestSpecial(string s) {
        // Base case: very short strings cannot be rearranged
        if (s.empty()) return "";

        vector<string> substrings;
        int count = 0;
        int start = 0;

        for (int i = 0; i < s.length(); ++i) {
            // Standard balance tracking: 1 is '(' and 0 is ')'
            count += (s[i] == '1' ? 1 : -1);

            // When balance hits 0, we've found an "atomic" special substring
            if (count == 0) {
                // The substring is s[start...i].
                // We strip the outer '1' and '0', recurse on the middle,
                // then wrap it back.
                string inner = s.substr(start + 1, i - start - 1);
                substrings.push_back("1" + makeLargestSpecial(inner) + "0");
                
                // Move start pointer for the next atomic block
                start = i + 1;
            }
        }

        // Sort substrings in descending order to get the lexicographical maximum
        sort(substrings.begin(), substrings.end(), greater<string>());

        // Concatenate and return
        string result = "";
        for (const string& sub : substrings) {
            result += sub;
        }
        return result;
    }
};