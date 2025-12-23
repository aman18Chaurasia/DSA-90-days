class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        // Sort by end time
        sort(events.begin(), events.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });

        int n = events.size();
        vector<int> prefixMax(n);
        prefixMax[0] = events[0][2];

        // Build prefix max of values
        for (int i = 1; i < n; i++) {
            prefixMax[i] = max(prefixMax[i - 1], events[i][2]);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int currStart = events[i][0];
            int currValue = events[i][2];

            // Binary search for last event ending before currStart
            int l = 0, r = i - 1, idx = -1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (events[mid][1] < currStart) {
                    idx = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            if (idx != -1) {
                currValue += prefixMax[idx];
            }

            ans = max(ans, currValue);
        }

        return ans;
    }
};
