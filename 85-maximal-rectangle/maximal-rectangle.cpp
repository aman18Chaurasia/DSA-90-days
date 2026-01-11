class Solution {
public:
    int largest(vector<int>& h) {
        stack<int> st;
        int ans = 0;
        h.push_back(0);

        for (int i = 0; i < h.size(); i++) {
            while (!st.empty() && h[st.top()] > h[i]) {
                int x = h[st.top()];
                st.pop();
                int w = st.empty() ? i : i - st.top() - 1;
                ans = max(ans, x * w);
            }
            st.push(i);
        }
        h.pop_back();
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int r = matrix.size(), c = matrix[0].size();
        vector<int> h(c, 0);
        int res = 0;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (matrix[i][j] == '1') h[j]++;
                else h[j] = 0;
            }
            res = max(res, largest(h));
        }
        return res;
    }
};
