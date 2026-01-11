class Solution {
public:
    int maximalRectangle(vector<vector<char>>& m) {
        if (m.empty()) return 0;

        int r = m.size(), c = m[0].size(), ans = 0;
        vector<int> h(c, 0);

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (m[i][j] == '1') h[j]++;
                else h[j] = 0;
            }
            ans = max(ans, solve(h));
        }
        return ans;
    }

    int solve(vector<int>& h) {
        stack<int> st;
        h.push_back(0);
        int res = 0;

        for (int i = 0; i < h.size(); i++) {
            while (!st.empty() && h[st.top()] > h[i]) {
                int x = h[st.top()];
                st.pop();
                int w = st.empty() ? i : i - st.top() - 1;
                res = max(res, x * w);
            }
            st.push(i);
        }
        h.pop_back();
        return res;
    }
};
